/**
 * @file orb_slam3_interface.cpp
 * @brief Implementation of the ORBSLAM3Interface class.
 * @author Suchetan R S (rssuchetan@gmail.com)
 */
#include "orb_slam3_ros2_wrapper/orb_slam3_interface.hpp"

namespace ORB_SLAM3_Wrapper
{
    using namespace WrapperTypeConversions;
    ORBSLAM3Interface::ORBSLAM3Interface(const std::string &strVocFile,
                                         const std::string &strSettingsFile,
                                         ORB_SLAM3::System::eSensor sensor,
                                         bool bUseViewer,
                                         bool loopClosing,
                                         geometry_msgs::msg::Pose initialRobotPose,
                                         std::string globalFrame,
                                         std::string odomFrame,
                                         std::string robotFrame)
        : strVocFile_(strVocFile),
          strSettingsFile_(strSettingsFile),
          sensor_(sensor),
          bUseViewer_(bUseViewer),
          loopClosing_(loopClosing),
          initialRobotPose_(initialRobotPose),
          globalFrame_(globalFrame),
          odomFrame_(odomFrame),
          robotFrame_(robotFrame)
    {
        std::cout << "Interface constructor started" << endl;
        mSLAM_ = std::make_shared<ORB_SLAM3::System>(strVocFile_, strSettingsFile_, sensor_, bUseViewer_, loopClosing);
        orbAtlas_ = mSLAM_->GetAtlas();
        time_profiler_ = TimeProfiler::getInstance();
        std::cout << "Interface constructor complete" << endl;
        robotBase_to_cameraLink_ = Eigen::Affine3f(
            Eigen::Translation3f(initialRobotPose_.position.x, initialRobotPose_.position.y, initialRobotPose_.position.z) *
            Eigen::Quaternionf(initialRobotPose_.orientation.w, initialRobotPose_.orientation.x, initialRobotPose_.orientation.y, initialRobotPose_.orientation.z));
        std::cout << "Robot X: " << initialRobotPose_.position.x << " Robot Y: " << initialRobotPose_.position.y << std::endl;
    }

    ORBSLAM3Interface::~ORBSLAM3Interface()
    {
        std::cout << "Interface destructor" << endl;
        mSLAM_->Shutdown();
        mSLAM_.reset();
        mapReferencePoses_.clear();
        allKFs_.clear();
    }

    std::unordered_map<long unsigned int, ORB_SLAM3::KeyFrame *> ORBSLAM3Interface::makeKFIdPair(std::vector<ORB_SLAM3::Map *> mapsList)
    {
        std::unordered_map<long unsigned int, ORB_SLAM3::KeyFrame *> mpIdKFs;
        for (ORB_SLAM3::Map *pMap_i : mapsList)
        {
            std::vector<ORB_SLAM3::KeyFrame *> vpKFs_Mi = pMap_i->GetAllKeyFrames();

            for (ORB_SLAM3::KeyFrame *pKF_j_Mi : vpKFs_Mi)
            {
                mpIdKFs[pKF_j_Mi->mnId] = pKF_j_Mi;
            }
        }

        return mpIdKFs;
    }

    void ORBSLAM3Interface::calculateReferencePoses()
    {
        struct compareInitKFid
        {
            inline bool operator()(ORB_SLAM3::Map *elem1, ORB_SLAM3::Map *elem2)
            {
                return elem1->GetInitKFid() < elem2->GetInitKFid();
            }
        };

        mapReferencesMutex_.lock();
        mapReferencePoses_.clear();
        std::vector<ORB_SLAM3::Map *> mapsList = orbAtlas_->GetAllMaps();
        // sort the map array in init kf id order.
        std::sort(mapsList.begin(), mapsList.end(), compareInitKFid());
        allKFs_ = makeKFIdPair(mapsList);
        // std::vector<ORB_SLAM3::Map *> mapsList2 = orbAtlas_->GetAllMaps();
        // std::cout << "Current map id: " << orbAtlas_->GetCurrentMap()->GetId() << std::endl;
        // for (auto mp : mapsList2)
        // {
        //     if (mp != nullptr && mp->GetOriginKF() != nullptr)
        //     {
        //         std::cout << "Map id: " << mp->GetId() << std::endl;
        //         std::cout << "Map init id: " << mp->GetInitKFid() << std::endl;
        //         std::cout << "Map origin kf id: " << mp->GetOriginKF()->mnId << std::endl;
        //         std::cout << "Map max kf id: " << mp->GetMaxKFid() << std::endl;
        //         std::cout << "================" << std::endl;
        //     }
        // }
        // std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
        for (size_t c = 0; c < mapsList.size(); c++)
        {
            // std::cout << "Map ID: " << mapsList[c]->GetId() << " origin kf ID: " << mapsList[c]->GetOriginKF()->mnId << " init kf id: " << mapsList[c]->GetInitKFid() << " max kf id: " << mapsList[c]->GetMaxKFid() << std::endl;
            if (c == 0)
            {
                auto poseWithoutOffset = se3ToAffine(mapsList[c]->GetOriginKF()->GetPose());
                // transform from map_orb -> camera
                mapReferencePoses_[mapsList[c]] = poseWithoutOffset;
            }
            else
            {
                bool parentMapFound = false;
                int parentMapID = mapsList[c]->GetInitKFid() - 1;
                while (!parentMapFound)
                {
                    if (parentMapID < 0)
                    {
                        throw std::runtime_error("The init KF id - 1 is lesser than 0. This should not happen");
                    }
                    if (allKFs_.count(parentMapID) > 0)
                    {
                        parentMapFound = true;
                        break;
                    }
                    parentMapID -= 1;
                }
                if (mapReferencePoses_.count(allKFs_[parentMapID]->GetMap()) == 0)
                {
                    throw std::runtime_error("The parent map pose for this map ID does not exist. This should not happen.");
                }
                auto parentMapORBPose = allKFs_[parentMapID]->GetPose();
                // transform from map_orb -> camera
                mapReferencePoses_[mapsList[c]] = transformPoseWithReference<Eigen::Affine3f>(mapReferencePoses_[allKFs_[parentMapID]->GetMap()], parentMapORBPose);
            }
        }
        // used for reset map service. To contonue tracking where it was left off. 
        for (auto& overridenRefPoses : mapReferencePosesOverrides_)
        {
            mapReferencePoses_[overridenRefPoses.first] = overridenRefPoses.second;
        }
        // std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
        mapReferencesMutex_.unlock();
    }

    void ORBSLAM3Interface::getCurrentMapPoints(sensor_msgs::msg::PointCloud2 &mapPointCloud)
    {
        std::lock_guard<std::mutex> lock(currentMapPointsMutex_);
        // this flag serves to support
        std::vector<Eigen::Vector3f> trackedMapPoints;
        auto atlasAllKFs_ = orbAtlas_->GetAllKeyFrames();
        for (auto &KF : atlasAllKFs_)
        {
            for (auto &mapPoint : KF->GetMapPoints())
            {
                if (!mapPoint->isBad())
                {
                    auto worldPos = vector3fORBToROS(mapPoint->GetWorldPos());
                    mapReferencesMutex_.lock();
                    if (allKFs_.count(KF->mnId) == 0)
                    {
                        mapReferencesMutex_.unlock();
                        continue;
                    }
                    auto mapPointWorld = transformPointWithReference<Eigen::Vector3f>(mapReferencePoses_[allKFs_[KF->mnId]->GetMap()], worldPos);
                    // robotBase_to_cameraLink_ is map_ros->map_orb
                    mapPointWorld = robotBase_to_cameraLink_ * mapPointWorld;
                    mapReferencesMutex_.unlock();
                    trackedMapPoints.push_back(mapPointWorld);
                }
            }
        }
        mapPointCloud = MapPointsToPCL(trackedMapPoints);
    }

    void ORBSLAM3Interface::mapPointsVisibleFromPose(geometry_msgs::msg::Pose cameraPose, std::vector<ORB_SLAM3::MapPoint*>& points, int maxLandmarks, float maxDistance, float maxAngle)
    {
        auto T_mapros_base = poseToAffine(cameraPose);
        auto T_maporb_cam = robotBase_to_cameraLink_.inverse() * T_mapros_base * robotBase_to_cameraLink_;
        auto camPose = se3ROSToORB(T_maporb_cam);
        mapPointsVisibleFromPose(camPose, points, maxLandmarks, maxDistance, maxAngle);
    }

    void ORBSLAM3Interface::mapPointsVisibleFromPose(Sophus::SE3f& cameraPose, std::vector<ORB_SLAM3::MapPoint*>& points, int maxLandmarks, float maxDistance, float maxAngle)
    {
        while(loopClosing_ && mSLAM_->GetLoopClosing()->loopDetected())
        {
            std::cout << "Waiting for loop closure to finish" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
        }
        auto Tcw = cameraPose;
        auto Twc = Tcw.inverse();

        std::cout << "Input camera pose: " << std::endl; 
        auto eulerAngles = rotationORBToEulerROS(Twc.rotationMatrix());
        std::cout << "Translation:" << Twc.translation().transpose() << std::endl;
        std::cout << "Roll ROS coord: " << eulerAngles(0) << std::endl;
        std::cout << "Pitch ROS coord: " << eulerAngles(1) << std::endl;
        std::cout << "Yaw ROS coord: " << eulerAngles(2) << std::endl;
        std::cout << "===" << std::endl;

        auto mRwc = Twc.rotationMatrix();
        auto mOw = Twc.translation();

        auto mRcw = Tcw.rotationMatrix();
        auto mtcw = Tcw.translation();
        if(orbAtlas_->GetAllCameras().size() > 1)
        {
            throw std::runtime_error("The number of cameras is greater than 1. This will be catered later. You cannot check if a map point is visible within a keyframe in this version. Check if there have been version updates.");
        }
        auto pCameraModel = orbAtlas_->GetAllCameras()[0];

        float mnMinX = 0.0f;
        float mnMaxX = 640.0f;
        float mnMinY = 0.0f;
        float mnMaxY = 480.0f;
        int numVisibleMapPoints = 0;
        int numKFsChecked = 0;

        auto mapKFs_ = orbAtlas_->GetCurrentMap()->GetAllKeyFrames();

        std::unordered_set<ORB_SLAM3::MapPoint*> processedMapPoints;
        for(auto pKFMp : mapKFs_)
        {
            auto rel_T_CamToKF = Tcw * pKFMp->GetPoseInverse();
            auto relEulerAngles = rotationORBToEulerROS(rel_T_CamToKF.rotationMatrix());
            float distBwKfs = rel_T_CamToKF.translation().norm();

            // checks ......
            // continue if the distance is too large
            if(distBwKfs >= maxDistance * 2.0)
            {
                continue;
            }
            if(distBwKfs > maxDistance)
            {
                // if distance is large but in range, check if behind. If behind, continue.
                if(rel_T_CamToKF.translation()[2] < 0.0)
                {
                    continue;
                }
                else if(rel_T_CamToKF.translation()[2] > 0.0)
                {
                    if((relEulerAngles(2) >= 0 && relEulerAngles(2) < M_PI / 2.0) || (relEulerAngles(2) > 3.0 * M_PI / 2.0 && relEulerAngles(2) < 2 * M_PI))
                    {
                        continue;
                    }
                }
            }
            if(distBwKfs <= maxDistance)
            {
                // if distance is small but in range, check if behind. If behind, check angles.
                if(rel_T_CamToKF.translation()[2] < 0.0)
                {
                    if((relEulerAngles(2) >= 2.0944 && relEulerAngles(2) < 4.18879))
                    {
                        continue;
                    }
                }
            }
            numKFsChecked++;
            if(numVisibleMapPoints > maxLandmarks)
                break;
            auto currentKFMp = pKFMp->GetMapPoints();
            for (auto pMP : currentKFMp)
            {
                if (processedMapPoints.find(pMP) != processedMapPoints.end())
                    continue;
                processedMapPoints.insert(pMP);
                // 3D in absolute coordinates
                Eigen::Matrix<float,3,1> P = pMP->GetWorldPos();

                // 3D in camera coordinates
                const Eigen::Matrix<float,3,1> Pc = mRcw * P + mtcw;

                // Check positive depth
                const float &PcZ = Pc(2);
                if(PcZ<0.0f)
                    continue;

                const Eigen::Vector2f uv = pCameraModel->project(Pc);

                if(uv(0)<mnMinX || uv(0)>mnMaxX)
                    continue;
                if(uv(1)<mnMinY || uv(1)>mnMaxY)
                    continue;

                // Check distance is in the scale invariance region of the MapPoint
                const float maxDistance = pMP->GetMaxDistanceInvariance();
                const float minDistance = pMP->GetMinDistanceInvariance();
                const Eigen::Vector3f PO = P - mOw;
                const float dist = PO.norm();

                if(dist<minDistance || dist>maxDistance)
                    continue;
                points.push_back(pMP);
                numVisibleMapPoints++;
            }
        }
        /**
        Added the stuff below just to see prints if the num kfs become 0. */
        std::cout << "******" << std::endl;
        std::cout << "Number of visible map points: " << numVisibleMapPoints << std::endl;
        std::cout << "Number of keyframes checked: " << numKFsChecked << std::endl;
        
        // Print the input camera pose translation and rotation
        // std::cout << "Input camera pose translation: " << mOw.transpose() << std::endl;
        // std::cout << "Input camera pose rotation:\n" << mRwc << std::endl;
    }

    void ORBSLAM3Interface::mapDataToMsg(slam_msgs::msg::MapData &mapDataMsg, bool currentMapKFOnly, bool includeMapPoints, std::vector<int> kFIDforMapPoints)
    {
        std::lock_guard<std::mutex> lock(mapDataMutex_);
        slam_msgs::msg::MapGraph poseGraph_;
        getOptimizedPoseGraph(poseGraph_, currentMapKFOnly);
        // publish the map data
        mapDataMsg.graph = poseGraph_;
        mapDataMsg.header.frame_id = globalFrame_;
        if (includeMapPoints)
        {
            for (auto kFId : kFIDforMapPoints)
            {
                slam_msgs::msg::KeyFrame pushedKf;
                pushedKf.id = kFId;
                if (allKFs_.find(kFId) != allKFs_.end())
                {
                    for (auto mapPoint : allKFs_[kFId]->GetMapPoints())
                    {
                        if (!mapPoint->isBad())
                        {
                            auto worldPos = vector3fORBToROS(mapPoint->GetWorldPos());
                            mapReferencesMutex_.lock();
                            auto mapPointWorld = transformPointWithReference<Eigen::Vector3f>(mapReferencePoses_[allKFs_[kFId]->GetMap()], worldPos);
                            mapPointWorld = robotBase_to_cameraLink_ * mapPointWorld;
                            auto mapPointWorldMsg = eigenToPointMsg(mapPointWorld);
                            mapReferencesMutex_.unlock();
                            pushedKf.word_pts.push_back(mapPointWorldMsg);
                        }
                    }
                    mapDataMsg.nodes.push_back(pushedKf);
                }
                else
                {
                    std::cerr << "Requested ID not available." << endl;
                }
            }
        }
    }

    void ORBSLAM3Interface::correctTrackedPose(const Sophus::SE3f &s)
    {
        std::lock_guard<std::mutex> lock(latestTrackedPoseMutex_);
        mapReferencesMutex_.lock();
        latestTrackedPoseORB_camera_ = transformPoseWithReference<Eigen::Affine3f>(
            mapReferencePoses_[orbAtlas_->GetCurrentMap()], s);
        latestTrackedPose_ = robotBase_to_cameraLink_ * latestTrackedPoseORB_camera_ * robotBase_to_cameraLink_.inverse();
        mapReferencesMutex_.unlock();
    }

    void ORBSLAM3Interface::resetLocalMapping()
    {
        std::lock_guard<std::mutex> lock(latestTrackedPoseMutex_);
        mSLAM_->ResetActiveMap();
        mapReferencesMutex_.lock();
        mapReferencePosesOverrides_[orbAtlas_->GetCurrentMap()] = latestTrackedPoseORB_camera_;
        mapReferencesMutex_.unlock();
    };

    void ORBSLAM3Interface::getDirectMapToRobotTF(std_msgs::msg::Header headerToUse, geometry_msgs::msg::TransformStamped &tf)
    {
        if (hasTracked_)
        {
            std::lock_guard<std::mutex> lock(latestTrackedPoseMutex_);
            // get transform between map and odom and send the transform.
            auto poseInMap = latestTrackedPose_;
            geometry_msgs::msg::Pose poseInMapROS = affine3fToPose(poseInMap);
            rclcpp::Duration transformTimeout_ = rclcpp::Duration::from_seconds(0.5);
            rclcpp::Time odomTimestamp = headerToUse.stamp;
            tf.header.stamp = odomTimestamp + transformTimeout_;
            tf.header.frame_id = globalFrame_;
            tf.child_frame_id = robotFrame_;
            tf.transform.translation.x = poseInMapROS.position.x;
            tf.transform.translation.y = poseInMapROS.position.y;
            tf.transform.translation.z = poseInMapROS.position.z;
            tf.transform.rotation = poseInMapROS.orientation;
        }
    }

    void ORBSLAM3Interface::getMapToOdomTF(const geometry_msgs::msg::TransformStamped& odomToBaseTf, geometry_msgs::msg::TransformStamped &tf)
    {
        // tf.header.stamp;
        tf.header.frame_id = globalFrame_;
        tf.child_frame_id = odomFrame_;
        if (hasTracked_)
        {
            // convert odom value to Eigen::Affine3f
            auto latestOdomTransform_ = Eigen::Affine3f(
                Eigen::Translation3f(odomToBaseTf.transform.translation.x,
                                     odomToBaseTf.transform.translation.y,
                                     odomToBaseTf.transform.translation.z) *
                Eigen::Quaternionf(odomToBaseTf.transform.rotation.w,
                                   odomToBaseTf.transform.rotation.x,
                                   odomToBaseTf.transform.rotation.y,
                                   odomToBaseTf.transform.rotation.z));
            // get transform between map and odom and send the transform.
            std::lock_guard<std::mutex> lock(latestTrackedPoseMutex_);
            auto tfMapOdom = latestTrackedPose_ * latestOdomTransform_.inverse();
            geometry_msgs::msg::Pose poseMapOdom = affine3fToPose(tfMapOdom);
            rclcpp::Duration transformTimeout_ = rclcpp::Duration::from_seconds(0.5);
            rclcpp::Time odomTimestamp = odomToBaseTf.header.stamp;
            tf.header.stamp = odomTimestamp + transformTimeout_;
            tf.header.frame_id = globalFrame_;
            tf.child_frame_id = odomFrame_;
            tf.transform.translation.x = poseMapOdom.position.x;
            tf.transform.translation.y = poseMapOdom.position.y;
            tf.transform.translation.z = poseMapOdom.position.z;
            tf.transform.rotation = poseMapOdom.orientation;
        }
    }

    void ORBSLAM3Interface::getRobotPose(geometry_msgs::msg::PoseStamped& pose)
    {
        std::lock_guard<std::mutex> lock(latestTrackedPoseMutex_);
        pose.header.frame_id = globalFrame_;
        pose.pose = affine3fToPose(latestTrackedPose_);
    }

    void ORBSLAM3Interface::getOptimizedPoseGraph(slam_msgs::msg::MapGraph &graph, bool currentMapKFOnly)
    {
        if (!currentMapKFOnly)
        {
            for (const auto &cKf : allKFs_)
            {
                ORB_SLAM3::KeyFrame *kf = cKf.second;
                Sophus::SE3f kfPose = kf->GetPose();
                geometry_msgs::msg::PoseStamped kfPoseStamped;
                mapReferencesMutex_.lock();
                auto affinePose = transformPoseWithReference<Eigen::Affine3f>(mapReferencePoses_[kf->GetMap()], kfPose);
                affinePose = robotBase_to_cameraLink_ * affinePose * robotBase_to_cameraLink_.inverse();
                kfPoseStamped.pose = affine3fToPose(affinePose);
                mapReferencesMutex_.unlock();
                kfPoseStamped.header.frame_id = globalFrame_;
                kfPoseStamped.header.stamp = secToStamp(kf->mTimeStamp);
                graph.poses.push_back(kfPoseStamped);
                graph.poses_id.push_back(kf->mnId);
            }
        }
        else
        {
            vector<ORB_SLAM3::KeyFrame *> vKeyFrames = orbAtlas_->GetAllKeyFrames();
            // TODO: add isBad() check for keyframes. Evaluate mapping if you do this.
            // iterate over current keyframes.
            for (auto pKFcurr : vKeyFrames)
            {
                mapReferencesMutex_.lock();
                auto currReferencePose_ = mapReferencePoses_[pKFcurr->GetMap()];
                mapReferencesMutex_.unlock();
                Sophus::SE3f kFPose = pKFcurr->GetPose();
                geometry_msgs::msg::PoseStamped poseStamped;
                auto affinePose = transformPoseWithReference<Eigen::Affine3f>(currReferencePose_, kFPose);
                affinePose = robotBase_to_cameraLink_ * affinePose * robotBase_to_cameraLink_.inverse();
                poseStamped.pose = affine3fToPose(affinePose);
                poseStamped.header.frame_id = globalFrame_;
                poseStamped.header.stamp = secToStamp(pKFcurr->mTimeStamp);
                // push to pose graph.
                graph.poses.push_back(poseStamped);
                graph.poses_id.push_back(pKFcurr->mnId);
            }
        }
    }

    bool ORBSLAM3Interface::processTrackedPose(const Sophus::SE3f& Tcw)
    {
        auto currentTrackingState = mSLAM_->GetTrackingState();
        auto orbLoopClosing = mSLAM_->GetLoopClosing();
        if (loopClosing_ && orbLoopClosing->mergeDetected())
        {
            // do not publish any values during map merging. This is because the reference poses change.
            std::cout << "Waiting for merge to finish." << endl;
            return false;
        }
        if (currentTrackingState == 2)
        {
            // time_profiler_->startEvent("RefPosesCalc");
            calculateReferencePoses();
            // time_profiler_->endEvent("RefPosesCalc");
            // time_profiler_->startEvent("CorrectTracked");
            correctTrackedPose(Tcw);
            // time_profiler_->endEvent("CorrectTracked");
            // auto tempTwc = Tcw.inverse();
            // std::vector<ORB_SLAM3::MapPoint *> tempMapPoints;
            // mapPointsVisibleFromPose(tempTwc, tempMapPoints, 1000, 5.0, 2.0);
            hasTracked_ = true;
            return true;
        }
        else
        {
            switch (currentTrackingState)
            {
            case 0:
                std::cerr << "ORB-SLAM failed: No images yet." << endl;
                break;
            case 1:
                std::cerr << "ORB-SLAM failed: Not initialized." << endl;
                break;
            case 3:
                std::cerr << "ORB-SLAM failed: Tracking LOST." << endl;
                break;
            }
            return false;
        }
    }
}
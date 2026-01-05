/**
 * @file slam_node_base.cpp
 * @brief Implementation of the common ROS 2 wrapper base class.
 */

#include "orb_slam3_ros2_wrapper/slam_node_base.hpp"

#include <Eigen/Core>

namespace ORB_SLAM3_Wrapper
{
    using namespace WrapperTypeConversions;

    SlamNodeBase::SlamNodeBase(const std::string &node_name,
                               const std::string &strVocFile,
                               const std::string &strSettingsFile,
                               ORB_SLAM3::System::eSensor sensor)
        : rclcpp::Node(node_name)
    {
#ifdef ORB_SLAM3_ROS2_WRAPPER_ENABLE_CUDA
        bool RunOrbExtractionOnGPU = true;
        bool RunStereoMatchOnGPU = true;
        bool RunSearchLocalPointsOnGPU = true;
        bool RunPoseEstimationOnGPU = true;
        bool RunPoseOptimization = false;

        // RunOrbExtractionOnGPU, RunStereoMatchOnGPU, RunSearchLocalPointsOnGPU, RunPoseEstimationOnGPU, RunPoseOptimization
        KernelController::setGPURunMode(RunOrbExtractionOnGPU, RunStereoMatchOnGPU, RunSearchLocalPointsOnGPU, RunPoseEstimationOnGPU, RunPoseOptimization);
        std::cout << "======================== CUDA CONFIGURATION ========================" << std::endl;
        std::cout << "RunOrbExtractionOnGPU: " << (RunOrbExtractionOnGPU ? "True" : "False") << std::endl;
        std::cout << "RunStereoMatchOnGPU: " << (RunStereoMatchOnGPU ? "True" : "False") << std::endl;
        std::cout << "RunSearchLocalPointsOnGPU: " << (RunSearchLocalPointsOnGPU ? "True" : "False") << std::endl;
        std::cout << "RunPoseEstimationOnGPU: " << (RunPoseEstimationOnGPU ? "True" : "False") << std::endl;
        std::cout << "RunPoseOptimization: " << (RunPoseOptimization ? "True" : "False") << std::endl;
// #  pragma message("ORB_SLAM3_ROS2_WRAPPER: CUDA mode enabled (compiling GPU path))")
#endif

        // ROS Publishers
        //---- the following is published when a service is called
        mapPointsPub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("map_points", 10);
        visibleLandmarksPub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("visible_landmarks", 10);
        visibleLandmarksPose_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("visible_landmarks_pose", 10);
        slamInfoPub_ = this->create_publisher<slam_msgs::msg::SlamInfo>("slam_info", 10);
        //---- the following is published continously
        mapDataPub_ = this->create_publisher<slam_msgs::msg::MapData>("map_data", 10);
        robotPoseMapFrame_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("robot_pose_slam", 10);

        // Services
        getMapDataService_ = this->create_service<slam_msgs::srv::GetMap>("orb_slam3/get_map_data", std::bind(&SlamNodeBase::getMapServer, this,
                                                                                                              std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
        pointsInViewCallbackGroup_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        getMapPointsService_ = this->create_service<slam_msgs::srv::GetLandmarksInView>("orb_slam3/get_landmarks_in_view", std::bind(&SlamNodeBase::getMapPointsInViewServer, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), rmw_qos_profile_services_default, pointsInViewCallbackGroup_);
        mapPointsCallbackGroup_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        mapPointsService_ = this->create_service<slam_msgs::srv::GetAllLandmarksInMap>("orb_slam3/get_all_landmarks_in_map", std::bind(&SlamNodeBase::publishMapPointCloud, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), rmw_qos_profile_services_default, mapPointsCallbackGroup_);
        resetLocalMapSrv_ = this->create_service<std_srvs::srv::SetBool>("orb_slam3/reset_mapping", std::bind(&SlamNodeBase::resetActiveMapSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), rmw_qos_profile_services_default, mapPointsCallbackGroup_);

        // TF
        tfBroadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
        tfBuffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
        tfListener_ = std::make_shared<tf2_ros::TransformListener>(*tfBuffer_);

        bool bUseViewer;
        this->declare_parameter("visualization", rclcpp::ParameterValue(true));
        this->get_parameter("visualization", bUseViewer);

        this->declare_parameter("robot_base_frame", "base_footprint");
        this->get_parameter("robot_base_frame", robot_base_frame_id_);

        this->declare_parameter("global_frame", "map");
        this->get_parameter("global_frame", global_frame_);

        this->declare_parameter("odom_frame", "odom");
        this->get_parameter("odom_frame", odom_frame_id_);

        this->declare_parameter("robot_x", rclcpp::ParameterValue(1.0));
        this->get_parameter("robot_x", robot_x_);

        this->declare_parameter("robot_y", rclcpp::ParameterValue(1.0));
        this->get_parameter("robot_y", robot_y_);

        this->declare_parameter("robot_z", rclcpp::ParameterValue(1.0));
        this->get_parameter("robot_z", robot_z_);

        // Declare and get the quaternion components
        this->declare_parameter("robot_qx", rclcpp::ParameterValue(0.0));
        this->get_parameter("robot_qx", robot_qx_);

        this->declare_parameter("robot_qy", rclcpp::ParameterValue(0.0));
        this->get_parameter("robot_qy", robot_qy_);

        this->declare_parameter("robot_qz", rclcpp::ParameterValue(0.0));
        this->get_parameter("robot_qz", robot_qz_);

        this->declare_parameter("robot_qw", rclcpp::ParameterValue(1.0));
        this->get_parameter("robot_qw", robot_qw_);

        // Create and populate the Pose message
        geometry_msgs::msg::Pose initial_pose;
        initial_pose.position.x = robot_x_;
        initial_pose.position.y = robot_y_;
        initial_pose.position.z = robot_z_;
        initial_pose.orientation.x = robot_qx_;
        initial_pose.orientation.y = robot_qy_;
        initial_pose.orientation.z = robot_qz_;
        initial_pose.orientation.w = robot_qw_;

        this->declare_parameter("odometry_mode", rclcpp::ParameterValue(false));
        this->get_parameter("odometry_mode", odometry_mode_);

        this->declare_parameter("publish_tf", rclcpp::ParameterValue(true));
        this->get_parameter("publish_tf", publish_tf_);

        this->declare_parameter("map_data_publish_frequency", rclcpp::ParameterValue(1000));
        this->get_parameter("map_data_publish_frequency", map_data_publish_frequency_);

        this->declare_parameter("do_loop_closing", rclcpp::ParameterValue(true));
        this->get_parameter("do_loop_closing", do_loop_closing_);

        // Timers
        mapDataCallbackGroup_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        mapDataTimer_ = this->create_wall_timer(std::chrono::milliseconds(map_data_publish_frequency_), std::bind(&SlamNodeBase::publishMapData, this), mapDataCallbackGroup_);

        interface_ = std::make_shared<ORB_SLAM3_Wrapper::ORBSLAM3Interface>(strVocFile, strSettingsFile,
                                                                            sensor, bUseViewer, do_loop_closing_, initial_pose, global_frame_, odom_frame_id_, robot_base_frame_id_);

        frequency_tracker_count_ = 0;
        frequency_tracker_clock_ = std::chrono::high_resolution_clock::now();
    }

    SlamNodeBase::~SlamNodeBase()
    {
        interface_.reset();
    }

    void SlamNodeBase::onTracked(const std_msgs::msg::Header &stamp_source_header)
    {
        isTracked_ = true;
        // if tf publishing is enabled, move into this block.
        if (publish_tf_)
        {
            // populate map to base_footprint tf if odometry is not being used to get transform map -> base_link
            if (!odometry_mode_)
            {
                auto tfMapRobot = geometry_msgs::msg::TransformStamped();
                tfMapRobot.header.stamp = stamp_source_header.stamp;
                tfMapRobot.header.frame_id = global_frame_;
                tfMapRobot.child_frame_id = odom_frame_id_;
                interface_->getDirectMapToRobotTF(stamp_source_header, tfMapRobot);
                tfBroadcaster_->sendTransform(tfMapRobot);
            }
            // populate map to odom tf if odometry is being used to get transform map -> odom -> base_link
            else
            {
                try
                {
                    auto msgOdom = tfBuffer_->lookupTransform(odom_frame_id_, robot_base_frame_id_, tf2::TimePointZero);
                    interface_->getMapToOdomTF(msgOdom, tfMapOdom_);
                    tfBroadcaster_->sendTransform(tfMapOdom_);
                }
                catch (tf2::TransformException &ex)
                {
                    RCLCPP_WARN(this->get_logger(), "Could not transform %s to %s: %s", odom_frame_id_.c_str(), robot_base_frame_id_.c_str(), ex.what());
                    RCLCPP_ERROR(this->get_logger(), "You have set the parameter `odometry_mode` to true. This requires the transform between `odom_frame` and `robot_base_frame` to exist. If you do not have odometry information, set odometry_mode to false.");
                    return;
                }
            }
        }
        geometry_msgs::msg::PoseStamped pose;
        interface_->getRobotPose(pose);
        pose.header.stamp = stamp_source_header.stamp;
        robotPoseMapFrame_->publish(pose);

        ++frequency_tracker_count_;
    }

    void SlamNodeBase::publishMapPointCloud(std::shared_ptr<rmw_request_id_t> /*request_header*/,
                                            std::shared_ptr<slam_msgs::srv::GetAllLandmarksInMap::Request> /*request*/,
                                            std::shared_ptr<slam_msgs::srv::GetAllLandmarksInMap::Response> response)
    {
        if (isTracked_)
        {
            // Using high resolution clock to measure time
            auto start = std::chrono::high_resolution_clock::now();

            sensor_msgs::msg::PointCloud2 mapPCL;

            auto t1 = std::chrono::high_resolution_clock::now();
            auto time_create_mapPCL = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - start).count();
            RCLCPP_DEBUG_STREAM(this->get_logger(), "Time to create mapPCL object: " << time_create_mapPCL << " seconds");

            interface_->getCurrentMapPoints(mapPCL);

            if (mapPCL.data.size() == 0)
                return;

            auto t2 = std::chrono::high_resolution_clock::now();
            auto time_get_map_points = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
            RCLCPP_DEBUG_STREAM(this->get_logger(), "Time to get current map points: " << time_get_map_points << " seconds");

            mapPointsPub_->publish(mapPCL);
            auto t3 = std::chrono::high_resolution_clock::now();
            auto time_publish_map_points = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2).count();
            RCLCPP_DEBUG_STREAM(this->get_logger(), "Time to publish map points: " << time_publish_map_points << " seconds");
            RCLCPP_DEBUG_STREAM(this->get_logger(), "=======================");

            // Calculate the time taken for each line

            // Print the time taken for each line
            response->landmarks = mapPCL;
        }
    }

    void SlamNodeBase::resetActiveMapSrv(std::shared_ptr<rmw_request_id_t> /*request_header*/,
                                         std::shared_ptr<std_srvs::srv::SetBool::Request> /*request*/,
                                         std::shared_ptr<std_srvs::srv::SetBool::Response> /*response*/)
    {
        interface_->resetLocalMapping();
    }

    void SlamNodeBase::publishMapData()
    {
        if (isTracked_)
        {
            auto start = std::chrono::high_resolution_clock::now();
            slam_msgs::msg::SlamInfo slamInfoMsg;
            RCLCPP_DEBUG_STREAM(this->get_logger(), "Publishing map data");
            double tracking_freq = frequency_tracker_count_ / std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - frequency_tracker_clock_).count();
            RCLCPP_INFO_STREAM(this->get_logger(), "Current ORB-SLAM3 tracking frequency: " << tracking_freq << " frames / sec");
            frequency_tracker_clock_ = std::chrono::high_resolution_clock::now();
            frequency_tracker_count_ = 0;
            // publish the map data (current active keyframes etc)
            slam_msgs::msg::MapData mapDataMsg;
            interface_->mapDataToMsg(mapDataMsg, true, false);
            mapDataPub_->publish(mapDataMsg);
            slamInfoMsg.num_maps = interface_->getNumberOfMaps();
            slamInfoMsg.num_keyframes_in_current_map = mapDataMsg.graph.poses_id.size();
            slamInfoMsg.tracking_frequency = tracking_freq;
            auto t1 = std::chrono::high_resolution_clock::now();
            auto time_publishMapData = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - start).count();
            RCLCPP_DEBUG_STREAM(this->get_logger(), "Time to create mapdata: " << time_publishMapData << " seconds");
            RCLCPP_INFO_STREAM(this->get_logger(), "*************************");
            slamInfoPub_->publish(slamInfoMsg);
        }
    }

    void SlamNodeBase::getMapServer(std::shared_ptr<rmw_request_id_t> /*request_header*/,
                                    std::shared_ptr<slam_msgs::srv::GetMap::Request> request,
                                    std::shared_ptr<slam_msgs::srv::GetMap::Response> response)
    {
        RCLCPP_INFO(this->get_logger(), "GetMap2 service called.");
        slam_msgs::msg::MapData mapDataMsg;
        interface_->mapDataToMsg(mapDataMsg, false, request->tracked_points, request->kf_id_for_landmarks);
        response->data = mapDataMsg;
    }

    void SlamNodeBase::getMapPointsInViewServer(std::shared_ptr<rmw_request_id_t> /*request_header*/,
                                                std::shared_ptr<slam_msgs::srv::GetLandmarksInView::Request> request,
                                                std::shared_ptr<slam_msgs::srv::GetLandmarksInView::Response> response)
    {
        RCLCPP_INFO(this->get_logger(), "GetMapPointsInView service called.");
        std::vector<slam_msgs::msg::MapPoint> landmarks;
        std::vector<ORB_SLAM3::MapPoint *> points;
        interface_->mapPointsVisibleFromPose(request->pose, points, 1000, request->max_dist_pose_observation, request->max_angle_pose_observation);
        auto affineMapToPos = poseToAffine(request->pose);
        auto affinePosToMap = affineMapToPos.inverse();
        // Populate the pose of the points vector into the ros message
        for (const auto &point : points)
        {
            slam_msgs::msg::MapPoint landmark;
            Eigen::Vector3f landmark_position = point->GetWorldPos();
            auto position = vector3fORBToROS(landmark_position);
            position = transformPointWithReference<Eigen::Vector3f>(affinePosToMap, position);
            // RCLCPP_INFO_STREAM(this->get_logger(), "x: " << position.x() << " y: " << position.y() << " z: " << position.z());
            landmark.position.x = position.x();
            landmark.position.y = position.y();
            landmark.position.z = position.z();
            landmarks.push_back(landmark);
        }
        response->map_points = landmarks;
        auto cloud = MapPointsToPCL(points);
        visibleLandmarksPub_->publish(cloud);

        // Convert the pose in request to PoseStamped and publish
        geometry_msgs::msg::PoseStamped pose_stamped;
        pose_stamped.header.stamp = this->now();
        pose_stamped.header.frame_id = "map"; // Assuming the frame is "map", adjust if needed
        pose_stamped.pose = request->pose;

        // Publish the PoseStamped
        visibleLandmarksPose_->publish(pose_stamped);
    }

} // namespace ORB_SLAM3_Wrapper

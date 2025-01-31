/**
 * @file orb_slam3_interface.hpp
 * @brief Implementation of the ORBSLAM3Interface class.
 * @author Suchetan R S (rssuchetan@gmail.com)
 */
#ifndef ORBSLAM3_INTERFACE_HPP
#define ORBSLAM3_INTERFACE_HPP

#include <iostream>
#include <algorithm>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <tf2_eigen/tf2_eigen.hpp>

#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"

#include <slam_msgs/msg/map_data.hpp>
#include <slam_msgs/msg/map_graph.hpp>

#include <cv_bridge/cv_bridge.h>


#include "sophus/se3.hpp"
#include "System.h"
#include "Frame.h"
#include "Map.h"
#include "Atlas.h"
#include "orb_slam3_ros2_wrapper/type_conversion.hpp"

namespace ORB_SLAM3_Wrapper
{
    class ORBSLAM3Interface
    {
    public:
        ORBSLAM3Interface(const std::string &strVocFile,
                          const std::string &strSettingsFile,
                          ORB_SLAM3::System::eSensor sensor,
                          bool bUseViewer,
                          double robotX,
                          double robotY,
                          std::string globalFrame,
                          std::string odomFrame,
                          std::string robotFrame);

        ~ORBSLAM3Interface();

        /**
         * @brief Generates a map of KeyFrame IDs and their pointers.
         * @param mapsList List of Map pointers.
         * @return Map of KeyFrame IDs and their pointers.
         */
        std::unordered_map<long unsigned int, ORB_SLAM3::KeyFrame *> makeKFIdPair(std::vector<ORB_SLAM3::Map *> mapsList);

        /**
         * @brief Calculates reference poses for each map.
         */
        void calculateReferencePoses();

        /**
         * @brief Converts the entire map data into a ROS Message.
         * @param orbAtlas Pointer to the Atlas object.
         * @note Only call this after calculating the reference poses.
         */
        void mapDataToMsg(slam_msgs::msg::MapData &mapDataMsg, bool currentMapKFOnly, bool includeMapPoints = false, std::vector<int> kFIDforMapPoints = std::vector<int>());

        void correctTrackedPose(Sophus::SE3f &s);

        void getDirectMapToRobotTF(std_msgs::msg::Header headerToUse, geometry_msgs::msg::TransformStamped &tf);

        void getMapToOdomTF(const nav_msgs::msg::Odometry::SharedPtr msgOdom, geometry_msgs::msg::TransformStamped &tf);

        void getRobotPose(geometry_msgs::msg::PoseStamped& pose);

        void getOptimizedPoseGraph(slam_msgs::msg::MapGraph &graph, bool currentMapGraph);

        void getCurrentMapPoints(sensor_msgs::msg::PointCloud2 &mapPointCloud);

        void mapPointsVisibleFromPose(geometry_msgs::msg::Pose cameraPose, std::vector<ORB_SLAM3::MapPoint*>& points, int maxLandmarks, float maxDistance, float maxAngle);

        void mapPointsVisibleFromPose(Sophus::SE3f& cameraPose, std::vector<ORB_SLAM3::MapPoint*>& points, int maxLandmarks, float maxDistance, float maxAngle);

        void handleIMU(const sensor_msgs::msg::Imu::SharedPtr msgIMU);

        bool trackRGBDi(const sensor_msgs::msg::Image::SharedPtr msgRGB, const sensor_msgs::msg::Image::SharedPtr msgD, Sophus::SE3f &Tcw);

        bool trackRGBD(const sensor_msgs::msg::Image::SharedPtr msgRGB, const sensor_msgs::msg::Image::SharedPtr msgD, Sophus::SE3f &Tcw);

        std::shared_ptr<WrapperTypeConversions> getTypeConversionPtr()
        {
            return typeConversions_;
        };

    private:
        std::shared_ptr<ORB_SLAM3::System> mSLAM_;
        std::shared_ptr<WrapperTypeConversions> typeConversions_;
        ORB_SLAM3::Atlas *orbAtlas_;
        std::string strVocFile_;
        std::string strSettingsFile_;
        ORB_SLAM3::System::eSensor sensor_;
        bool bUseViewer_;

        queue<sensor_msgs::msg::Imu::SharedPtr> imuBuf_;
        std::mutex bufMutex_;
        std::mutex mapDataMutex_;
        std::mutex currentMapPointsMutex_;

        std::unordered_map<ORB_SLAM3::Map *, Eigen::Affine3d> mapReferencePoses_;
        std::mutex mapReferencesMutex_;
        std::unordered_map<long unsigned int, ORB_SLAM3::KeyFrame *> allKFs_;
        Eigen::Affine3d latestTrackedPose_;
        bool hasTracked_ = false;
        double robotX_, robotY_;
        std::string globalFrame_;
        std::string odomFrame_;
        std::string robotFrame_;
    };
}

#endif // ORBSLAM3_INTERFACE_HPP
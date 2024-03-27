/**
 * @file rgbd-slam-node.hpp
 * @brief Definition of the RgbdSlamNode Wrapper class.
 * @author Suchetan R S (rssuchetan@gmail.com)
 */

#ifndef RGBD_SLAM_NODE_HPP_
#define RGBD_SLAM_NODE_HPP_

#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"

#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <geometry_msgs/msg/pose_array.hpp>
#include "geometry_msgs/msg/transform_stamped.hpp"

#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/transform_listener.h"

#include "message_filters/subscriber.h"
#include "message_filters/synchronizer.h"
#include "message_filters/sync_policies/approximate_time.h"

#include <slam_msgs/msg/map_data.hpp>
#include <slam_msgs/srv/get_map.hpp>

#include "type_conversion.hpp"
#include "orb_slam3_interface.hpp"

#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/conversions.h>
#include <pcl_ros/impl/transforms.hpp>

namespace ORB_SLAM3_Wrapper
{
    class RgbdSlamNode : public rclcpp::Node
    {
    public:
        RgbdSlamNode(const std::string &strVocFile,
                     const std::string &strSettingsFile,
                     ORB_SLAM3::System::eSensor sensor);
        ~RgbdSlamNode();

    private:
        typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::Image, sensor_msgs::msg::Image> approximate_sync_policy;

        // ROS 2 Callbacks.
        void ImuCallback(const sensor_msgs::msg::Imu::SharedPtr msgIMU);
        void OdomCallback(const nav_msgs::msg::Odometry::SharedPtr msgOdom);
        void RGBDCallback(const sensor_msgs::msg::Image::SharedPtr msgRGB,
                       const sensor_msgs::msg::Image::SharedPtr msgD);
        void LidarCallback(const sensor_msgs::PointCloud2ConstPtr& msgLidar);

        /**
         * @brief Publishes map data. (Keyframes and all poses in the current active map.)
         * @param orb_atlas Pointer to the Atlas object.
         * @param last_init_kf_id ID of the last initialized keyframe.
         */
        void publishMapData();

        void publishMapPointCloud();

        /**
         * @brief Callback function for GetMap service.
         * @param request_header Request header.
         * @param request Request message.
         * @param response Response message.
         */
        void getMapServer(std::shared_ptr<rmw_request_id_t> request_header,
                          std::shared_ptr<slam_msgs::srv::GetMap::Request> request,
                          std::shared_ptr<slam_msgs::srv::GetMap::Response> response);

        /**
         * Member variables
         */
        // RGBD
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> rgb_sub;
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> depth_sub;
        // ROS Publishers and Subscribers
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub;
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub;
        rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr lidar_sub;
        rclcpp::Publisher<slam_msgs::msg::MapData>::SharedPtr map_data_pub;
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr map_points_pub;
        rclcpp::Service<slam_msgs::srv::GetMap>::SharedPtr get_map_data_service;
        std::shared_ptr<message_filters::Synchronizer<approximate_sync_policy>> syncApproximate;
        std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

        // ROS Params
        std::string robot_base_frame_id_;
        std::string odom_frame_id_;
        std::string global_frame_;
        double robot_x_, robot_y_;
        bool rosViz_;
        ORB_SLAM3_Wrapper::WrapperTypeConversions conversions;
        std::shared_ptr<ORB_SLAM3_Wrapper::ORBSLAM3Interface> interface;
        geometry_msgs::msg::TransformStamped tfMapOdom;
    };
}
#endif

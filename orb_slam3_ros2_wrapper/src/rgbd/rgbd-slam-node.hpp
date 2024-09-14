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

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>

#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/transform_listener.h>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <slam_msgs/msg/map_data.hpp>
#include <slam_msgs/srv/get_map.hpp>
#include <slam_msgs/srv/get_landmarks_in_view.hpp>

#include "orb_slam3_ros2_wrapper/type_conversion.hpp"
#include "orb_slam3_ros2_wrapper/orb_slam3_interface.hpp"

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

        void getMapPointsInViewServer(std::shared_ptr<rmw_request_id_t> request_header,
                          std::shared_ptr<slam_msgs::srv::GetLandmarksInView::Request> request,
                          std::shared_ptr<slam_msgs::srv::GetLandmarksInView::Response> response);
        /**
         * Member variables
         */
        // RGBD Sensor specifics
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> rgbSub_;
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> depthSub_;
        std::shared_ptr<message_filters::Synchronizer<approximate_sync_policy>> syncApproximate_;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imuSub_;
        // ROS Publishers and Subscribers
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odomSub_;
        rclcpp::Publisher<slam_msgs::msg::MapData>::SharedPtr mapDataPub_;
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr mapPointsPub_;
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr visibleLandmarksPub_;
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr visibleLandmarksPose_;
        // TF
        std::shared_ptr<tf2_ros::TransformBroadcaster> tfBroadcaster_;
        std::shared_ptr<tf2_ros::TransformListener> tfListener_;
        std::shared_ptr<tf2_ros::Buffer> tfBuffer_;
        // ROS Services
        rclcpp::Service<slam_msgs::srv::GetMap>::SharedPtr getMapDataService_;
        rclcpp::Service<slam_msgs::srv::GetLandmarksInView>::SharedPtr getMapPointsService_;
        // ROS Timers
        rclcpp::TimerBase::SharedPtr mapDataTimer_;
        rclcpp::CallbackGroup::SharedPtr mapDataCallbackGroup_;
        rclcpp::TimerBase::SharedPtr mapPointsTimer_;
        rclcpp::CallbackGroup::SharedPtr mapPointsCallbackGroup_;
        // ROS Params
        std::string robot_base_frame_id_;
        std::string odom_frame_id_;
        std::string global_frame_;
        double robot_x_, robot_y_;
        bool rosViz_;
        bool isTracked_ = false;
        bool no_odometry_mode_;
        bool publish_tf_;
        double frequency_tracker_count_ = 0;
        int map_data_publish_frequency_;
        int landmark_publish_frequency_;
        std::chrono::_V2::system_clock::time_point frequency_tracker_clock_;

        ORB_SLAM3_Wrapper::WrapperTypeConversions typeConversion_;
        std::shared_ptr<ORB_SLAM3_Wrapper::ORBSLAM3Interface> interface_;
        geometry_msgs::msg::TransformStamped tfMapOdom_;
    };
}
#endif

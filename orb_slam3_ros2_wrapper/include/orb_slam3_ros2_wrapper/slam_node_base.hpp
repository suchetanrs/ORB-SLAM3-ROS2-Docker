/**
 * @file slam_node_base.hpp
 * @brief Common ROS 2 wrapper base class for ORB-SLAM3 sensor nodes.
 */
#ifndef ORB_SLAM3_ROS2_WRAPPER__SLAM_NODE_BASE_HPP_
#define ORB_SLAM3_ROS2_WRAPPER__SLAM_NODE_BASE_HPP_

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

#include "std_srvs/srv/set_bool.hpp"

#include <slam_msgs/msg/map_data.hpp>
#include <slam_msgs/msg/slam_info.hpp>
#include <slam_msgs/srv/get_map.hpp>
#include <slam_msgs/srv/get_landmarks_in_view.hpp>
#include <slam_msgs/srv/get_all_landmarks_in_map.hpp>

#include "orb_slam3_ros2_wrapper/type_conversion.hpp"
#include "orb_slam3_ros2_wrapper/orb_slam3_interface.hpp"

namespace ORB_SLAM3_Wrapper
{

    class SlamNodeBase : public rclcpp::Node
    {
    public:
        SlamNodeBase(const std::string &node_name,
                     const std::string &strVocFile,
                     const std::string &strSettingsFile,
                     ORB_SLAM3::System::eSensor sensor);

        ~SlamNodeBase() override;

    protected:
        // Called by derived sensor nodes when tracking succeeded for a frame.
        void onTracked(const std_msgs::msg::Header &stamp_source_header);

        std::shared_ptr<ORBSLAM3Interface> interface() { return interface_; }

    private:
        void publishMapData();

        void publishMapPointCloud(std::shared_ptr<rmw_request_id_t> request_header,
                                  std::shared_ptr<slam_msgs::srv::GetAllLandmarksInMap::Request> request,
                                  std::shared_ptr<slam_msgs::srv::GetAllLandmarksInMap::Response> response);

        void resetActiveMapSrv(std::shared_ptr<rmw_request_id_t> request_header,
                               std::shared_ptr<std_srvs::srv::SetBool::Request> request,
                               std::shared_ptr<std_srvs::srv::SetBool::Response> response);

        void getMapServer(std::shared_ptr<rmw_request_id_t> request_header,
                          std::shared_ptr<slam_msgs::srv::GetMap::Request> request,
                          std::shared_ptr<slam_msgs::srv::GetMap::Response> response);

        void getMapPointsInViewServer(std::shared_ptr<rmw_request_id_t> request_header,
                                      std::shared_ptr<slam_msgs::srv::GetLandmarksInView::Request> request,
                                      std::shared_ptr<slam_msgs::srv::GetLandmarksInView::Response> response);

    private:
        // ROS Publishers and Subscribers
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odomSub_;
        rclcpp::Publisher<slam_msgs::msg::MapData>::SharedPtr mapDataPub_;
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr mapPointsPub_;
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr visibleLandmarksPub_;
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr visibleLandmarksPose_;
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr robotPoseMapFrame_;
        rclcpp::Publisher<slam_msgs::msg::SlamInfo>::SharedPtr slamInfoPub_;
        // TF
        std::shared_ptr<tf2_ros::TransformBroadcaster> tfBroadcaster_;
        std::shared_ptr<tf2_ros::TransformListener> tfListener_;
        std::shared_ptr<tf2_ros::Buffer> tfBuffer_;
        // ROS Services
        rclcpp::Service<slam_msgs::srv::GetMap>::SharedPtr getMapDataService_;
        rclcpp::Service<slam_msgs::srv::GetLandmarksInView>::SharedPtr getMapPointsService_;
        rclcpp::Service<slam_msgs::srv::GetAllLandmarksInMap>::SharedPtr mapPointsService_;
        rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr resetLocalMapSrv_;
        // ROS Timers
        rclcpp::TimerBase::SharedPtr mapDataTimer_;
        rclcpp::CallbackGroup::SharedPtr mapDataCallbackGroup_;
        rclcpp::CallbackGroup::SharedPtr mapPointsCallbackGroup_;
        rclcpp::CallbackGroup::SharedPtr pointsInViewCallbackGroup_;
        // ROS Params
        std::string robot_base_frame_id_;
        std::string odom_frame_id_;
        std::string global_frame_;
        double robot_x_, robot_y_, robot_z_, robot_qx_, robot_qy_, robot_qz_, robot_qw_;
        bool isTracked_ = false;
        bool odometry_mode_;
        bool publish_tf_;
        double frequency_tracker_count_ = 0;
        int map_data_publish_frequency_;
        bool do_loop_closing_;
        std::chrono::_V2::system_clock::time_point frequency_tracker_clock_;
        std::shared_ptr<ORB_SLAM3_Wrapper::ORBSLAM3Interface> interface_;
        geometry_msgs::msg::TransformStamped tfMapOdom_;
    };

} // namespace ORB_SLAM3_Wrapper

#endif // ORB_SLAM3_ROS2_WRAPPER__SLAM_NODE_BASE_HPP_

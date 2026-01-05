/**
 * @file rgbd-imu-slam-node.hpp
 * @brief Definition of the RgbdImuSlamNode Wrapper class.
 * @author Suchetan R S (rssuchetan@gmail.com)
 */

#ifndef RGBD_IMU_SLAM_NODE_HPP_
#define RGBD_IMU_SLAM_NODE_HPP_

#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <queue>
#include <mutex>

#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include "orb_slam3_ros2_wrapper/slam_node_base.hpp"

namespace ORB_SLAM3_Wrapper
{
    class RgbdImuSlamNode : public SlamNodeBase
    {
    public:
        RgbdImuSlamNode(const std::string &strVocFile,
                        const std::string &strSettingsFile,
                        ORB_SLAM3::System::eSensor sensor);
        ~RgbdImuSlamNode();

    private:
        typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::Image, sensor_msgs::msg::Image> approximate_sync_policy;

        // ROS 2 Callbacks
        void ImuCallback(const sensor_msgs::msg::Imu::SharedPtr msgImu);
        void RGBDCallback(const sensor_msgs::msg::Image::SharedPtr msgRGB,
                          const sensor_msgs::msg::Image::SharedPtr msgD);

        /**
         * Member variables
         */
        // RGBD Sensor specifics
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> rgbSub_;
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> depthSub_;
        std::shared_ptr<message_filters::Synchronizer<approximate_sync_policy>> syncApproximate_;

        // Dedicated callback group for IMU subscription (allows independent scheduling vs RGBD callback).
        rclcpp::CallbackGroup::SharedPtr imuCallbackGroup_;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imuSub_;
        std::mutex imuMutex_;
        std::queue<sensor_msgs::msg::Imu::SharedPtr> imuBuf_;
    };
}
#endif



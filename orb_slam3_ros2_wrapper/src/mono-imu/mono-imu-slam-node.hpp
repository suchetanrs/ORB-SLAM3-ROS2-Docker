/**
 * @file mono-imu-slam-node.hpp
 * @brief Definition of the MonoImuSlamNode Wrapper class.
 */

#ifndef MONO_IMU_SLAM_NODE_HPP_
#define MONO_IMU_SLAM_NODE_HPP_

#include <mutex>
#include <queue>

#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>

#include "orb_slam3_ros2_wrapper/slam_node_base.hpp"

namespace ORB_SLAM3_Wrapper
{
    class MonoImuSlamNode : public SlamNodeBase
    {
    public:
        MonoImuSlamNode(const std::string &strVocFile,
                        const std::string &strSettingsFile,
                        ORB_SLAM3::System::eSensor sensor);
        ~MonoImuSlamNode();

    private:
        void ImuCallback(const sensor_msgs::msg::Imu::SharedPtr msgImu);
        void ImageCallback(const sensor_msgs::msg::Image::SharedPtr msgImg);

        // Image subscription
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr imageSub_;

        // Dedicated callback group for IMU subscription (allows independent scheduling vs image callback).
        rclcpp::CallbackGroup::SharedPtr imuCallbackGroup_;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imuSub_;

        std::mutex imuMutex_;
        std::queue<sensor_msgs::msg::Imu::SharedPtr> imuBuf_;
    };
} // namespace ORB_SLAM3_Wrapper

#endif // MONO_IMU_SLAM_NODE_HPP_



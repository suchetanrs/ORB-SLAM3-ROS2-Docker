/**
 * @file stereo-imu-slam-node.hpp
 * @brief Definition of the StereoImuSlamNode Wrapper class.
 */

#ifndef STEREO_IMU_SLAM_NODE_HPP_
#define STEREO_IMU_SLAM_NODE_HPP_

#include <mutex>
#include <queue>

#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include "orb_slam3_ros2_wrapper/slam_node_base.hpp"

namespace ORB_SLAM3_Wrapper
{
    class StereoImuSlamNode : public SlamNodeBase
    {
    public:
        StereoImuSlamNode(const std::string &strVocFile,
                         const std::string &strSettingsFile,
                         ORB_SLAM3::System::eSensor sensor);
        ~StereoImuSlamNode();

    private:
        using approximate_sync_policy = message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::Image, sensor_msgs::msg::Image>;

        void ImuCallback(const sensor_msgs::msg::Imu::SharedPtr msgImu);
        void StereoCallback(const sensor_msgs::msg::Image::SharedPtr msgLeft,
                            const sensor_msgs::msg::Image::SharedPtr msgRight);

        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> leftSub_;
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> rightSub_;
        std::shared_ptr<message_filters::Synchronizer<approximate_sync_policy>> syncApproximate_;

        // Dedicated callback group for IMU subscription (allows independent scheduling vs stereo callback).
        rclcpp::CallbackGroup::SharedPtr imuCallbackGroup_;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imuSub_;

        std::mutex imuMutex_;
        std::queue<sensor_msgs::msg::Imu::SharedPtr> imuBuf_;
    };
} // namespace ORB_SLAM3_Wrapper

#endif // STEREO_IMU_SLAM_NODE_HPP_


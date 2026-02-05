/**
 * @file mono-slam-node.hpp
 * @brief Definition of the MonoSlamNode Wrapper class.
 */

#ifndef MONO_SLAM_NODE_HPP_
#define MONO_SLAM_NODE_HPP_

#include <sensor_msgs/msg/image.hpp>

#include "orb_slam3_ros2_wrapper/slam_node_base.hpp"

namespace ORB_SLAM3_Wrapper
{
    class MonoSlamNode : public SlamNodeBase
    {
    public:
        MonoSlamNode(const std::string &strVocFile,
                     const std::string &strSettingsFile,
                     ORB_SLAM3::System::eSensor sensor);
        ~MonoSlamNode();

    private:
        void ImageCallback(const sensor_msgs::msg::Image::SharedPtr msgImg);

        // Image subscription
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr imageSub_;
    };
} // namespace ORB_SLAM3_Wrapper

#endif // MONO_SLAM_NODE_HPP_


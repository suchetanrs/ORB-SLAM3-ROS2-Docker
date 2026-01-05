/**
 * @file stereo-slam-node.hpp
 * @brief Definition of the StereoSlamNode Wrapper class.
 */

#ifndef STEREO_SLAM_NODE_HPP_
#define STEREO_SLAM_NODE_HPP_

#include <sensor_msgs/msg/image.hpp>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include "orb_slam3_ros2_wrapper/slam_node_base.hpp"

namespace ORB_SLAM3_Wrapper
{
    class StereoSlamNode : public SlamNodeBase
    {
    public:
        StereoSlamNode(const std::string &strVocFile,
                       const std::string &strSettingsFile,
                       ORB_SLAM3::System::eSensor sensor);
        ~StereoSlamNode();

    private:
        using approximate_sync_policy = message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::Image, sensor_msgs::msg::Image>;

        void StereoCallback(const sensor_msgs::msg::Image::SharedPtr msgLeft,
                            const sensor_msgs::msg::Image::SharedPtr msgRight);

        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> leftSub_;
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> rightSub_;
        std::shared_ptr<message_filters::Synchronizer<approximate_sync_policy>> syncApproximate_;
    };
} // namespace ORB_SLAM3_Wrapper

#endif // STEREO_SLAM_NODE_HPP_


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
#include <queue>
#include <mutex>

#include <sensor_msgs/msg/image.hpp>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include "orb_slam3_ros2_wrapper/slam_node_base.hpp"

namespace ORB_SLAM3_Wrapper
{
    class RgbdSlamNode : public SlamNodeBase
    {
    public:
        RgbdSlamNode(const std::string &strVocFile,
                     const std::string &strSettingsFile,
                     ORB_SLAM3::System::eSensor sensor);
        ~RgbdSlamNode();

    private:
        typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::Image, sensor_msgs::msg::Image> approximate_sync_policy;

        // ROS 2 Callbacks.
        void RGBDCallback(const sensor_msgs::msg::Image::SharedPtr msgRGB,
                          const sensor_msgs::msg::Image::SharedPtr msgD);

        /**
         * Member variables
         */
        // RGBD Sensor specifics
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> rgbSub_;
        std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::Image>> depthSub_;
        std::shared_ptr<message_filters::Synchronizer<approximate_sync_policy>> syncApproximate_;
    };
}
#endif

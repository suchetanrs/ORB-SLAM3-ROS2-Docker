/**
 * @file mono-slam-node.cpp
 * @brief Implementation of the MonoSlamNode Wrapper class.
 */

#include "mono-slam-node.hpp"

#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>

namespace ORB_SLAM3_Wrapper
{
    using namespace WrapperTypeConversions;

    MonoSlamNode::MonoSlamNode(const std::string &strVocFile,
                               const std::string &strSettingsFile,
                               ORB_SLAM3::System::eSensor sensor)
        : SlamNodeBase("ORB_SLAM3_MONO_ROS2", strVocFile, strSettingsFile, sensor)
    {
        // Declare parameters (topic names)
        this->declare_parameter("image_topic_name", rclcpp::ParameterValue("camera/image_raw"));

        // Image subscriber (frame callback)
        imageSub_ = this->create_subscription<sensor_msgs::msg::Image>(
            this->get_parameter("image_topic_name").as_string(),
            rclcpp::SensorDataQoS(),
            std::bind(&MonoSlamNode::ImageCallback, this, std::placeholders::_1));

        RCLCPP_INFO(this->get_logger(), "Mono node started. Image: %s",
                    this->get_parameter("image_topic_name").as_string().c_str());
    }

    MonoSlamNode::~MonoSlamNode()
    {
        imageSub_.reset();
        RCLCPP_INFO(this->get_logger(), "Mono node stopped.");
    }

    void MonoSlamNode::ImageCallback(const sensor_msgs::msg::Image::SharedPtr msgImg)
    {
        cv_bridge::CvImageConstPtr cvImg;
        try
        {
            cvImg = cv_bridge::toCvShare(msgImg);
        }
        catch (cv_bridge::Exception &e)
        {
            std::cerr << "cv_bridge exception (mono image)!" << std::endl;
            return;
        }

        const double tImg = stampToSec(msgImg->header.stamp);

        // Track monocular image without IMU measurements.
        auto Tcw = interface()->slam()->TrackMonocular(cvImg->image, tImg);

        // Process and publish on success.
        if (interface()->processTrackedPose(Tcw))
        {
            this->onTracked(msgImg->header);
        }
    }
} // namespace ORB_SLAM3_Wrapper


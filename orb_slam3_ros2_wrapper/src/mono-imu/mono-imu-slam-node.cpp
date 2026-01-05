/**
 * @file mono-imu-slam-node.cpp
 * @brief Implementation of the MonoImuSlamNode Wrapper class.
 */

#include "mono-imu-slam-node.hpp"

#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>

namespace ORB_SLAM3_Wrapper
{
    using namespace WrapperTypeConversions;

    MonoImuSlamNode::MonoImuSlamNode(const std::string &strVocFile,
                                     const std::string &strSettingsFile,
                                     ORB_SLAM3::System::eSensor sensor)
        : SlamNodeBase("ORB_SLAM3_IMU_MONO_ROS2", strVocFile, strSettingsFile, sensor)
    {
        // Declare parameters (topic names)
        this->declare_parameter("image_topic_name", rclcpp::ParameterValue("camera/image_raw"));
        this->declare_parameter("imu_topic_name", rclcpp::ParameterValue("imu"));

        // Image subscriber (frame callback)
        imageSub_ = this->create_subscription<sensor_msgs::msg::Image>(
            this->get_parameter("image_topic_name").as_string(),
            rclcpp::SensorDataQoS(),
            std::bind(&MonoImuSlamNode::ImageCallback, this, std::placeholders::_1));

        // IMU subscriber in an independent callback group.
        imuCallbackGroup_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        rclcpp::SubscriptionOptions imuSubOptions;
        imuSubOptions.callback_group = imuCallbackGroup_;

        imuSub_ = this->create_subscription<sensor_msgs::msg::Imu>(
            this->get_parameter("imu_topic_name").as_string(),
            rclcpp::SensorDataQoS(),
            std::bind(&MonoImuSlamNode::ImuCallback, this, std::placeholders::_1),
            imuSubOptions);

        RCLCPP_INFO(this->get_logger(), "Mono-IMU node started. Image: %s | IMU: %s",
                    this->get_parameter("image_topic_name").as_string().c_str(),
                    this->get_parameter("imu_topic_name").as_string().c_str());
    }

    MonoImuSlamNode::~MonoImuSlamNode()
    {
        imageSub_.reset();
        imuSub_.reset();
        RCLCPP_INFO(this->get_logger(), "Mono-IMU node stopped.");
    }

    void MonoImuSlamNode::ImuCallback(const sensor_msgs::msg::Imu::SharedPtr msgImu)
    {
        std::lock_guard<std::mutex> lock(imuMutex_);
        imuBuf_.push(msgImu);
    }

    void MonoImuSlamNode::ImageCallback(const sensor_msgs::msg::Image::SharedPtr msgImg)
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

        // Collect IMU measurements up to this image timestamp (Euroc-style: everything since last frame).
        std::vector<ORB_SLAM3::IMU::Point> vImuMeas;
        {
            std::lock_guard<std::mutex> lock(imuMutex_);
            while (!imuBuf_.empty() && stampToSec(imuBuf_.front()->header.stamp) <= tImg)
            {
                const double t = stampToSec(imuBuf_.front()->header.stamp);
                const cv::Point3f acc(
                    imuBuf_.front()->linear_acceleration.x,
                    imuBuf_.front()->linear_acceleration.y,
                    imuBuf_.front()->linear_acceleration.z);
                const cv::Point3f gyr(
                    imuBuf_.front()->angular_velocity.x,
                    imuBuf_.front()->angular_velocity.y,
                    imuBuf_.front()->angular_velocity.z);

                vImuMeas.push_back(ORB_SLAM3::IMU::Point(acc, gyr, t));
                imuBuf_.pop();
            }
        }

        if (vImuMeas.empty())
        {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                                 "No IMU measurements available for image t=%.6f (waiting for IMU...)", tImg);
            return;
        }

        // Track monocular image with IMU measurements.
        auto Tcw = interface()->slam()->TrackMonocular(cvImg->image, tImg, vImuMeas);

        // Process and publish on success.
        if (interface()->processTrackedPose(Tcw))
        {
            this->onTracked(msgImg->header);
        }
    }
} // namespace ORB_SLAM3_Wrapper



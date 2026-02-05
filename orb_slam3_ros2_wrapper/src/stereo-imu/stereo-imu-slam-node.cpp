/**
 * @file stereo-imu-slam-node.cpp
 * @brief Implementation of the StereoImuSlamNode Wrapper class.
 */

#include "stereo-imu-slam-node.hpp"

#include <algorithm>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>

namespace ORB_SLAM3_Wrapper
{
    using namespace WrapperTypeConversions;

    StereoImuSlamNode::StereoImuSlamNode(const std::string &strVocFile,
                                         const std::string &strSettingsFile,
                                         ORB_SLAM3::System::eSensor sensor)
        : SlamNodeBase("ORB_SLAM3_IMU_STEREO_ROS2", strVocFile, strSettingsFile, sensor)
    {
        // Declare parameters (topic names)
        this->declare_parameter("left_image_topic_name", rclcpp::ParameterValue("left/image_raw"));
        this->declare_parameter("right_image_topic_name", rclcpp::ParameterValue("right/image_raw"));
        this->declare_parameter("imu_topic_name", rclcpp::ParameterValue("imu"));

        // ROS Subscribers for stereo images
        leftSub_ = std::make_shared<message_filters::Subscriber<sensor_msgs::msg::Image>>(this, this->get_parameter("left_image_topic_name").as_string());
        rightSub_ = std::make_shared<message_filters::Subscriber<sensor_msgs::msg::Image>>(this, this->get_parameter("right_image_topic_name").as_string());
        syncApproximate_ = std::make_shared<message_filters::Synchronizer<approximate_sync_policy>>(approximate_sync_policy(10), *leftSub_, *rightSub_);
        syncApproximate_->registerCallback(&StereoImuSlamNode::StereoCallback, this);

        // IMU subscriber in an independent callback group.
        imuCallbackGroup_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        rclcpp::SubscriptionOptions imuSubOptions;
        imuSubOptions.callback_group = imuCallbackGroup_;

        imuSub_ = this->create_subscription<sensor_msgs::msg::Imu>(
            this->get_parameter("imu_topic_name").as_string(),
            rclcpp::SensorDataQoS(),
            std::bind(&StereoImuSlamNode::ImuCallback, this, std::placeholders::_1),
            imuSubOptions);

        RCLCPP_INFO(this->get_logger(), "Stereo-IMU node started. Left: %s | Right: %s | IMU: %s",
                    this->get_parameter("left_image_topic_name").as_string().c_str(),
                    this->get_parameter("right_image_topic_name").as_string().c_str(),
                    this->get_parameter("imu_topic_name").as_string().c_str());
    }

    StereoImuSlamNode::~StereoImuSlamNode()
    {
        leftSub_.reset();
        rightSub_.reset();
        syncApproximate_.reset();
        imuSub_.reset();
        RCLCPP_INFO(this->get_logger(), "Stereo-IMU node stopped.");
    }

    void StereoImuSlamNode::ImuCallback(const sensor_msgs::msg::Imu::SharedPtr msgImu)
    {
        std::lock_guard<std::mutex> lock(imuMutex_);
        imuBuf_.push(msgImu);
    }

    void StereoImuSlamNode::StereoCallback(const sensor_msgs::msg::Image::SharedPtr msgLeft,
                                          const sensor_msgs::msg::Image::SharedPtr msgRight)
    {
        cv_bridge::CvImageConstPtr cvLeft;
        cv_bridge::CvImageConstPtr cvRight;

        try
        {
            cvLeft = cv_bridge::toCvShare(msgLeft);
        }
        catch (cv_bridge::Exception &e)
        {
            std::cerr << "cv_bridge exception left!" << std::endl;
            return;
        }

        try
        {
            cvRight = cv_bridge::toCvShare(msgRight);
        }
        catch (cv_bridge::Exception &e)
        {
            std::cerr << "cv_bridge exception right!" << std::endl;
            return;
        }

        const double tFrame = std::min(stampToSec(msgLeft->header.stamp), stampToSec(msgRight->header.stamp));

        // Collect IMU measurements up to this stereo frame timestamp (Euroc-style: everything since last frame).
        std::vector<ORB_SLAM3::IMU::Point> vImuMeas;
        {
            std::lock_guard<std::mutex> lock(imuMutex_);
            while (!imuBuf_.empty() && stampToSec(imuBuf_.front()->header.stamp) <= tFrame)
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
                                 "No IMU measurements available for stereo frame t=%.6f (waiting for IMU...)", tFrame);
            return;
        }

        // Track stereo images with IMU measurements.
        auto Tcw = interface()->slam()->TrackStereo(cvLeft->image, cvRight->image, tFrame, vImuMeas);

        if (interface()->processTrackedPose(Tcw))
        {
            this->onTracked(msgLeft->header);
        }
    }
} // namespace ORB_SLAM3_Wrapper


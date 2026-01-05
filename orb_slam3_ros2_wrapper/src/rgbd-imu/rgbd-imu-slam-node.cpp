/**
 * @file rgbd-imu-slam-node.cpp
 * @brief Implementation of the RgbdImuSlamNode Wrapper class.
 * @author Suchetan R S (rssuchetan@gmail.com)
 */
#include "rgbd-imu-slam-node.hpp"

#include <opencv2/core/core.hpp>
#include <cv_bridge/cv_bridge.h>

namespace ORB_SLAM3_Wrapper
{
    using namespace WrapperTypeConversions;

    RgbdImuSlamNode::RgbdImuSlamNode(const std::string &strVocFile,
                                     const std::string &strSettingsFile,
                                     ORB_SLAM3::System::eSensor sensor)
        : SlamNodeBase("ORB_SLAM3_IMU_RGBD_ROS2", strVocFile, strSettingsFile, sensor)
    {
        // Declare parameters (topic names)
        this->declare_parameter("rgb_image_topic_name", rclcpp::ParameterValue("camera/image_raw"));
        this->declare_parameter("depth_image_topic_name", rclcpp::ParameterValue("depth/image_raw"));
        this->declare_parameter("imu_topic_name", rclcpp::ParameterValue("imu"));

        // Subscribers: RGB + Depth synchronized, IMU buffered
        rgbSub_ = std::make_shared<message_filters::Subscriber<sensor_msgs::msg::Image>>(this, this->get_parameter("rgb_image_topic_name").as_string());
        depthSub_ = std::make_shared<message_filters::Subscriber<sensor_msgs::msg::Image>>(this, this->get_parameter("depth_image_topic_name").as_string());
        syncApproximate_ = std::make_shared<message_filters::Synchronizer<approximate_sync_policy>>(approximate_sync_policy(10), *rgbSub_, *depthSub_);
        syncApproximate_->registerCallback(&RgbdImuSlamNode::RGBDCallback, this);

        // IMU subscriber in an independent callback group.
        imuCallbackGroup_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        rclcpp::SubscriptionOptions imuSubOptions;
        imuSubOptions.callback_group = imuCallbackGroup_;

        imuSub_ = this->create_subscription<sensor_msgs::msg::Imu>(
            this->get_parameter("imu_topic_name").as_string(),
            rclcpp::SensorDataQoS(),
            std::bind(&RgbdImuSlamNode::ImuCallback, this, std::placeholders::_1),
            imuSubOptions);

        RCLCPP_INFO(this->get_logger(), "RGBD-IMU node started. RGB: %s | Depth: %s | IMU: %s",
                    this->get_parameter("rgb_image_topic_name").as_string().c_str(),
                    this->get_parameter("depth_image_topic_name").as_string().c_str(),
                    this->get_parameter("imu_topic_name").as_string().c_str());
    }

    RgbdImuSlamNode::~RgbdImuSlamNode()
    {
        rgbSub_.reset();
        depthSub_.reset();
        syncApproximate_.reset();
        imuSub_.reset();
        RCLCPP_INFO(this->get_logger(), "RGBD-IMU node stopped.");
    }

    void RgbdImuSlamNode::ImuCallback(const sensor_msgs::msg::Imu::SharedPtr msgImu)
    {
        std::lock_guard<std::mutex> lock(imuMutex_);
        imuBuf_.push(msgImu);
    }

    void RgbdImuSlamNode::RGBDCallback(const sensor_msgs::msg::Image::SharedPtr msgRGB, const sensor_msgs::msg::Image::SharedPtr msgD)
    {
        cv_bridge::CvImageConstPtr cvRGB;
        cv_bridge::CvImageConstPtr cvD;
        // Copy the ros rgb image message to cv::Mat.
        try
        {
            cvRGB = cv_bridge::toCvShare(msgRGB);
        }
        catch (cv_bridge::Exception &e)
        {
            std::cerr << "cv_bridge exception RGB!" << endl;
            return;
        }

        // Copy the ros depth image message to cv::Mat.
        try
        {
            cvD = cv_bridge::toCvShare(msgD);
        }
        catch (cv_bridge::Exception &e)
        {
            std::cerr << "cv_bridge exception D!" << endl;
            return;
        }

        vector<ORB_SLAM3::IMU::Point> vImuMeas;
        {
            std::lock_guard<std::mutex> lock(imuMutex_);
            if (!imuBuf_.empty())
            {
                // Load imu measurements from buffer
                vImuMeas.clear();
                const double tFrame = std::min(stampToSec(msgRGB->header.stamp), stampToSec(msgD->header.stamp));
                while (!imuBuf_.empty() && stampToSec(imuBuf_.front()->header.stamp) <= tFrame)
                {
                    double t = stampToSec(imuBuf_.front()->header.stamp);
                    cv::Point3f acc(imuBuf_.front()->linear_acceleration.x, imuBuf_.front()->linear_acceleration.y, imuBuf_.front()->linear_acceleration.z);
                    cv::Point3f gyr(imuBuf_.front()->angular_velocity.x, imuBuf_.front()->angular_velocity.y, imuBuf_.front()->angular_velocity.z);
                    vImuMeas.push_back(ORB_SLAM3::IMU::Point(acc, gyr, t));
                    imuBuf_.pop();
                }
            }
        }
        if (vImuMeas.empty())
        {
            RCLCPP_WARN(this->get_logger(), "No IMU measurements between two RGBD frames!");
            return;
        }

        // track the frame.
        auto Tcw = interface()->slam()->TrackRGBD(cvRGB->image, cvD->image, stampToSec(msgRGB->header.stamp), vImuMeas);
        
        // process the tracked pose.
        if (interface()->processTrackedPose(Tcw))
        {
            // Use RGB timestamp as the source stamp for TF/pose publishing.
            this->onTracked(msgRGB->header);
        }
    }
}

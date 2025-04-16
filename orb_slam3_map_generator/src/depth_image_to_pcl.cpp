#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/point_cloud2_iterator.hpp>
#include <image_transport/image_transport.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

// For message_filters Synchronizer
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/synchronizer.h>

using namespace std::chrono_literals;

// This code takes in a coloured image and an rgb image. Outputs the coloured pointcloud using a message filter sync.
// Uses the rgb camera intrinsics
class ColoredPointCloudNode : public rclcpp::Node
{
public:
    ColoredPointCloudNode()
        : Node("colored_pointcloud_node")
    {
        this->declare_parameter<std::string>("rgb_image_topic", "rgb_camera");
        this->declare_parameter<std::string>("depth_image_topic", "depth_camera");
        this->declare_parameter<std::string>("rgb_info_topic", "rgb_camera/camera_info");
        this->declare_parameter<std::string>("depth_info_topic", "camera_info");
        
        // Get parameter values.
        std::string rgb_image_topic;
        std::string depth_image_topic;
        std::string rgb_info_topic;
        std::string depth_info_topic;
        this->get_parameter("rgb_image_topic", rgb_image_topic);
        this->get_parameter("depth_image_topic", depth_image_topic);
        this->get_parameter("rgb_info_topic", rgb_info_topic);
        this->get_parameter("depth_info_topic", depth_info_topic);

        RCLCPP_INFO_STREAM(this->get_logger(), "RGB image topic: " << rgb_image_topic);
        RCLCPP_INFO_STREAM(this->get_logger(), "Depth image topic: " << depth_image_topic);
        RCLCPP_INFO_STREAM(this->get_logger(), "RGB info topic: " << rgb_info_topic);
        RCLCPP_INFO_STREAM(this->get_logger(), "Depth info topic: " << depth_info_topic);
        RCLCPP_INFO(this->get_logger(), "=================================");

        // Set up subscribers using message_filters
        rgb_image_sub_.subscribe(this, rgb_image_topic);
        depth_image_sub_.subscribe(this, depth_image_topic);

        rgb_info_sub_ = this->create_subscription<sensor_msgs::msg::CameraInfo>(
            rgb_info_topic, 10,
            std::bind(&ColoredPointCloudNode::rgbInfoCallback, this, std::placeholders::_1));

        depth_info_sub_ = this->create_subscription<sensor_msgs::msg::CameraInfo>(
            depth_info_topic, 10,
            std::bind(&ColoredPointCloudNode::depthInfoCallback, this, std::placeholders::_1));

        typedef message_filters::sync_policies::ApproximateTime<
            sensor_msgs::msg::Image,
            sensor_msgs::msg::Image>
            SyncPolicy;

        sync_ = std::make_shared<message_filters::Synchronizer<SyncPolicy>>(
            SyncPolicy(10), rgb_image_sub_, depth_image_sub_);

        // Register the synchronized callback
        sync_->registerCallback(
            std::bind(&ColoredPointCloudNode::callbackSync, this,
                      std::placeholders::_1, std::placeholders::_2));

        // Publisher for PointCloud2
        pointcloud_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>(
            "/camera/colored_pointcloud", 10);
    }

private:
    void rgbInfoCallback(const sensor_msgs::msg::CameraInfo::ConstSharedPtr &info_msg)
    {
        if (!rgb_info_received_)
        {
            RCLCPP_INFO(this->get_logger(), "Received RGB CameraInfo once. Storing intrinsics.");
            rgb_k_ = info_msg->k; // store the 3x3 intrinsic matrix in a std::array<double, 9>
            rgb_info_received_ = true;

            // If you are sure you only need this info once, unsubscribe
            rgb_info_sub_.reset();
        }
    }

    void depthInfoCallback(const sensor_msgs::msg::CameraInfo::ConstSharedPtr &info_msg)
    {
        if (!depth_info_received_)
        {
            RCLCPP_INFO(this->get_logger(), "Received Depth CameraInfo once. Storing intrinsics.");
            depth_k_ = info_msg->k;
            depth_info_received_ = true;

            // If you are sure you only need this info once, unsubscribe
            depth_info_sub_.reset();
        }
    }

    void callbackSync(const sensor_msgs::msg::Image::ConstSharedPtr &rgb_msg,
                      const sensor_msgs::msg::Image::ConstSharedPtr &depth_msg)
    {
        if (!rgb_info_received_ || !depth_info_received_)
            return;
        // Convert ROS image messages to OpenCV images
        cv::Mat rgb_image, depth_image;
        try
        {
            rgb_image = cv_bridge::toCvCopy(rgb_msg, "bgr8")->image;
            // Depth image typically is TYPE_16UC1 or TYPE_32FC1
            depth_image = cv_bridge::toCvCopy(depth_msg, depth_msg->encoding)->image;
        }
        catch (cv_bridge::Exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            return;
        }

        // For simplicity, assume depth and RGB share same intrinsics
        double fx, fy, cx, cy;
        // fx = depth_k_[0];
        // fy = depth_k_[4];
        // cx = depth_k_[2];
        // cy = depth_k_[5];

        fx = rgb_k_[0];
        fy = rgb_k_[4];
        cx = rgb_k_[2];
        cy = rgb_k_[5];

        // Prepare PointCloud2 message
        sensor_msgs::msg::PointCloud2 cloud_msg;
        cloud_msg.header = rgb_msg->header;
        cloud_msg.height = depth_image.rows;
        cloud_msg.width = depth_image.cols;
        cloud_msg.is_bigendian = false;
        cloud_msg.is_dense = false;

        sensor_msgs::PointCloud2Modifier modifier(cloud_msg);
        modifier.setPointCloud2Fields(
            4,
            "x", 1, sensor_msgs::msg::PointField::FLOAT32,
            "y", 1, sensor_msgs::msg::PointField::FLOAT32,
            "z", 1, sensor_msgs::msg::PointField::FLOAT32,
            "rgb", 1, sensor_msgs::msg::PointField::FLOAT32);
        modifier.resize(cloud_msg.height * cloud_msg.width);

        sensor_msgs::PointCloud2Iterator<float> out_x(cloud_msg, "x");
        sensor_msgs::PointCloud2Iterator<float> out_y(cloud_msg, "y");
        sensor_msgs::PointCloud2Iterator<float> out_z(cloud_msg, "z");
        sensor_msgs::PointCloud2Iterator<uint8_t> out_rgb(cloud_msg, "rgb");

        // Example depth_scale if your depth is in mm (e.g., 16UC1)
        double depth_scale = 0.001;

        for (int v = 0; v < depth_image.rows; ++v)
        {
            for (int u = 0; u < depth_image.cols; ++u)
            {
                float Z = 0.0f;
                if (depth_image.type() == CV_16UC1)
                {
                    uint16_t d = depth_image.at<uint16_t>(v, u);
                    if (d == 0)
                    {
                        Z = std::numeric_limits<float>::quiet_NaN();
                    }
                    else
                    {
                        Z = static_cast<float>(d) * depth_scale;
                    }
                }
                else if (depth_image.type() == CV_32FC1)
                {
                    float d = depth_image.at<float>(v, u);
                    if (std::isnan(d) || d <= 0.0f)
                    {
                        Z = std::numeric_limits<float>::quiet_NaN();
                    }
                    else
                    {
                        Z = d;
                    }
                }
                else
                {
                    RCLCPP_WARN_ONCE(this->get_logger(),
                                     "Unsupported depth type. Please add handling code.");
                    Z = std::numeric_limits<float>::quiet_NaN();
                }

                float X = std::numeric_limits<float>::quiet_NaN();
                float Y = std::numeric_limits<float>::quiet_NaN();
                if (!std::isnan(Z))
                {
                    X = (static_cast<float>(u) - cx) * Z / fx;
                    Y = (static_cast<float>(v) - cy) * Z / fy;
                }

                *out_x = X;
                ++out_x;
                *out_y = Y;
                ++out_y;
                *out_z = Z;
                ++out_z;

                // Get color
                cv::Vec3b bgr_color = rgb_image.at<cv::Vec3b>(v, u);
                uint8_t b = bgr_color[0];
                uint8_t g = bgr_color[1];
                uint8_t r = bgr_color[2];

                // Pack color into a float
                uint32_t rgb = (static_cast<uint32_t>(r) << 16 |
                                static_cast<uint32_t>(g) << 8 |
                                static_cast<uint32_t>(b));
                memcpy(&(*out_rgb), &rgb, sizeof(uint32_t));
                ++out_rgb;
            }
        }

        pointcloud_pub_->publish(cloud_msg);
    }

    // Subscribers
    message_filters::Subscriber<sensor_msgs::msg::Image> rgb_image_sub_;
    message_filters::Subscriber<sensor_msgs::msg::Image> depth_image_sub_;

    // Synchronizer
    std::shared_ptr<message_filters::Synchronizer<
        message_filters::sync_policies::ApproximateTime<
            sensor_msgs::msg::Image,
            sensor_msgs::msg::Image>>>
        sync_;

    // Publisher
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud_pub_;
    // --- Subscriptions for Camera Info (only to store intrinsics once) ---
    rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr rgb_info_sub_;
    rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr depth_info_sub_;

    bool rgb_info_received_;
    bool depth_info_received_;

    // Store camera intrinsics from the callback
    std::array<double, 9> rgb_k_;
    std::array<double, 9> depth_k_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ColoredPointCloudNode>());
    rclcpp::shutdown();
    return 0;
}

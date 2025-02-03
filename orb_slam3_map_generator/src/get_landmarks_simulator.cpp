#include <cmath>
#include <vector>
#include <string>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "sensor_msgs/point_cloud2_iterator.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/point.hpp"

#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <geometry_msgs/msg/quaternion.hpp>
#include <iostream>

#include "slam_msgs/srv/get_landmarks_in_view.hpp"
#include "slam_msgs/msg/map_point.hpp"
#include <Eigen/Geometry>

// This code simulates the landmarks in view service of the orb slam3 wrapper. This should not be run when the SLAM is running.
// Takes in the published map points and returns the points inside an fov for an input pose in the service request.

const double MAP_PITCH = 10.0; // degrees
const double max_angle = M_PI / 6;
const double max_dist = 1.3;

class MapPointsNode : public rclcpp::Node
{
public:
    MapPointsNode()
        : Node("map_points_server_node")
    {
        // Subscription to PointCloud2
        pointcloud_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
            "map_points",
            10,
            std::bind(&MapPointsNode::pointCloudCallback, this, std::placeholders::_1));

        // Service to retrieve the visible landmarks
        service_ = this->create_service<slam_msgs::srv::GetLandmarksInView>(
            "orb_slam3/get_landmarks_in_view",
            std::bind(&MapPointsNode::handleGetLandmarksInView, this,
                      std::placeholders::_1, std::placeholders::_2));

        landmarks_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>(
            "landmarks_in_view", 10);

        trans_landmarks_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>(
            "transformed_map_points", 10);

        RCLCPP_INFO(this->get_logger(), "map_points_server_node is up and running.");
    }

private:
    void pointCloudCallback(sensor_msgs::msg::PointCloud2::SharedPtr msg)
    {
        // Clear local storage of points so we only store the latest message.
        stored_points_.clear();

        // Convert 10 degrees to radians.
        const double theta = MAP_PITCH * M_PI / 180.0;
        const double cos_theta = std::cos(theta);
        const double sin_theta = std::sin(theta);

        // Use PointCloud2 iterators to read x, y, z from the incoming cloud.
        // This example assumes fields: x, y, z (and possibly other data).
        sensor_msgs::PointCloud2Iterator<float> iter_x(*msg, "x");
        sensor_msgs::PointCloud2Iterator<float> iter_y(*msg, "y");
        sensor_msgs::PointCloud2Iterator<float> iter_z(*msg, "z");

        for (size_t i = 0; i < msg->width * msg->height;
             ++i, ++iter_x, ++iter_y, ++iter_z)
        {
            slam_msgs::msg::MapPoint map_point;
            float x = *iter_x;
            float y = *iter_y;
            float z = *iter_z;

            float new_x = cos_theta * x + sin_theta * z;
            float new_y = y;
            float new_z = -sin_theta * x + cos_theta * z;

            map_point.position.x = new_x;
            map_point.position.y = new_y;
            map_point.position.z = new_z;

            stored_points_.push_back(map_point);

            *iter_x = new_x;
            *iter_y = new_y;
            *iter_z = new_z;
        }

        trans_landmarks_pub_->publish(*msg);

        RCLCPP_INFO(this->get_logger(), "Stored %zu points from PointCloud2.", stored_points_.size());
    }

    geometry_msgs::msg::Point transformPointToPoseFrame(
        const geometry_msgs::msg::Point &point_in_map,
        const geometry_msgs::msg::Pose &pose_in_map)
    {
        // Convert Pose to Eigen objects
        Eigen::Quaterniond q(pose_in_map.orientation.w,
                             pose_in_map.orientation.x,
                             pose_in_map.orientation.y,
                             pose_in_map.orientation.z);
        Eigen::Vector3d t(pose_in_map.position.x,
                          pose_in_map.position.y,
                          pose_in_map.position.z);

        // Convert Point to Eigen vector
        Eigen::Vector3d p(point_in_map.x, point_in_map.y, point_in_map.z);

        // Compute transformation: T^-1 * P
        Eigen::Vector3d transformed_point = q.inverse() * (p - t);

        // Convert back to geometry_msgs::msg::Point
        geometry_msgs::msg::Point point_in_pose_frame;
        point_in_pose_frame.x = transformed_point.x();
        point_in_pose_frame.y = transformed_point.y();
        point_in_pose_frame.z = transformed_point.z();

        return point_in_pose_frame;
    }

    void handleGetLandmarksInView(
        const std::shared_ptr<slam_msgs::srv::GetLandmarksInView::Request> request,
        std::shared_ptr<slam_msgs::srv::GetLandmarksInView::Response> response)
    {
        // Extract the pose's position
        double pose_x = request->pose.position.x;
        double pose_y = request->pose.position.y;
        double pose_z = request->pose.position.z;

        // Convert the pose's orientation to roll, pitch, yaw
        double roll_req, pitch_req, yaw_req;
        tf2::Quaternion tf_quat(request->pose.orientation.x, request->pose.orientation.y, request->pose.orientation.z, request->pose.orientation.w);
        tf2::Matrix3x3(tf_quat).getRPY(roll_req, pitch_req, yaw_req);
        if (yaw_req < 0)
            yaw_req += 2 * M_PI;

        // RCLCPP_INFO_STREAM(this->get_logger(), "YAW REQ: " << yaw_req * 180 / M_PI);

        // For each stored point:
        //   1. Compute distance from request->pose
        //   2. If within max_dist, check orientation difference if max_angle <= pi
        //   3. Add to response if it passes all checks

        std::vector<slam_msgs::msg::MapPoint> v_map_points_map;
        for (const auto &map_point : stored_points_)
        {
            // 1) Distance check
            double dx = map_point.position.x - pose_x;
            double dy = map_point.position.y - pose_y;
            double dz = map_point.position.z - pose_z;
            double dist = std::sqrt(dx * dx + dy * dy);

            auto ros_point_cam = transformPointToPoseFrame(map_point.position, request->pose);
            slam_msgs::msg::MapPoint map_point_cam;
            map_point_cam.position = ros_point_cam;

            if (dist > max_dist)
            {
                continue;
            }

            double heading_to_point = std::atan2(dy, dx); // angle from x-axis
            if (heading_to_point < 0)
                heading_to_point += 2 * M_PI;
            double yaw_diff = heading_to_point - yaw_req;

            if (std::fabs(yaw_diff) <= max_angle)
            {
                // Point is within the distance AND within the angular range
                response->map_points.push_back(map_point_cam);
                v_map_points_map.push_back(map_point);
            }
        }

        RCLCPP_INFO(
            this->get_logger(),
            "Returning %zu landmarks (out of %zu total).",
            response->map_points.size(),
            stored_points_.size());

        auto points_in_view = v_map_points_map;
        // Now publish these points as a PointCloud2 in the map frame
        sensor_msgs::msg::PointCloud2 cloud_msg;
        cloud_msg.header.stamp = this->now();
        cloud_msg.header.frame_id = "map"; // <-- The map frame you want

        cloud_msg.height = 1;
        cloud_msg.width = static_cast<uint32_t>(points_in_view.size());
        cloud_msg.is_bigendian = false;
        cloud_msg.is_dense = false;

        // Define fields (x, y, z)
        sensor_msgs::PointCloud2Modifier modifier(cloud_msg);
        modifier.setPointCloud2FieldsByString(1, "xyz");

        // Resize to hold all points
        modifier.resize(points_in_view.size());

        // Iterate and fill
        sensor_msgs::PointCloud2Iterator<float> out_x(cloud_msg, "x");
        sensor_msgs::PointCloud2Iterator<float> out_y(cloud_msg, "y");
        sensor_msgs::PointCloud2Iterator<float> out_z(cloud_msg, "z");

        for (size_t i = 0; i < points_in_view.size(); ++i, ++out_x, ++out_y, ++out_z)
        {
            *out_x = points_in_view[i].position.x;
            *out_y = points_in_view[i].position.y;
            *out_z = points_in_view[i].position.z;
        }

        // Publish the resulting cloud
        landmarks_pub_->publish(cloud_msg);
    }

    // Subscription
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud_sub_;

    // Service
    rclcpp::Service<slam_msgs::srv::GetLandmarksInView>::SharedPtr service_;

    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr landmarks_pub_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr trans_landmarks_pub_;

    // Internal storage of the most recent map points
    std::vector<slam_msgs::msg::MapPoint> stored_points_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MapPointsNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
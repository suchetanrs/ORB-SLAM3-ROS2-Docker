/**
 * @file ros_common.hpp
 * @brief Small ROS helpers shared by the wrapper nodes.
 */
#pragma once

#include <chrono>
#include <string>

#include <Eigen/Geometry>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

namespace ORB_SLAM3_Wrapper
{
    /**
     * @brief Blocks until the static extrinsics are available on TF, then fills:
     *        tf_SlamToLidar = slam_frame <- lidar_frame, tf_BaseToSlam = base_frame <- slam_frame.
     */
    inline void populateTransforms(std::string slam_frame_id, std::string robot_base_frame_id, std::string lidar_frame_id,
                                   rclcpp::Clock::SharedPtr clock, rclcpp::Logger logger, std::shared_ptr<tf2_ros::Buffer> tf_buffer, Eigen::Affine3f &tf_SlamToLidar, Eigen::Affine3f &tf_BaseToSlam)
    {
        (void)clock;
        bool tf1_found = false;
        bool tf2_found = false;

        while (!tf1_found && rclcpp::ok())
        {
            geometry_msgs::msg::TransformStamped tf_stamped;
            try
            {
                // TimePointZero = latest static
                tf_stamped = tf_buffer->lookupTransform(
                    slam_frame_id,
                    lidar_frame_id,
                    tf2::TimePointZero,
                    tf2::durationFromSec(1.0));
                tf1_found = true;
            }
            catch (const tf2::TransformException &ex)
            {
                RCLCPP_ERROR(logger,
                             "Could not get %s->%s : %s",
                             slam_frame_id.c_str(), lidar_frame_id.c_str(), ex.what());
                rclcpp::sleep_for(std::chrono::seconds(1));
                continue;
            }

            Eigen::Translation3f translation_slam_lidar(
                tf_stamped.transform.translation.x,
                tf_stamped.transform.translation.y,
                tf_stamped.transform.translation.z);
            Eigen::Quaternion<float> quaternion_slam_lidar(
                tf_stamped.transform.rotation.w,
                tf_stamped.transform.rotation.x,
                tf_stamped.transform.rotation.y,
                tf_stamped.transform.rotation.z);
            tf_SlamToLidar = translation_slam_lidar * quaternion_slam_lidar;
        }

        while (!tf2_found && rclcpp::ok())
        {
            geometry_msgs::msg::TransformStamped tf_stamped;
            try
            {
                // TimePointZero = latest static
                tf_stamped = tf_buffer->lookupTransform(
                    robot_base_frame_id,
                    slam_frame_id,
                    tf2::TimePointZero,
                    tf2::durationFromSec(1.0));
                tf2_found = true;
            }
            catch (const tf2::TransformException &ex)
            {
                RCLCPP_ERROR(logger,
                             "Could not get %s->%s : %s",
                             robot_base_frame_id.c_str(), slam_frame_id.c_str(), ex.what());
                rclcpp::sleep_for(std::chrono::seconds(1));
                continue;
            }

            Eigen::Translation3f translation_bf_slam(
                tf_stamped.transform.translation.x,
                tf_stamped.transform.translation.y,
                tf_stamped.transform.translation.z);
            Eigen::Quaternion<float> quaternion_bf_slam(
                tf_stamped.transform.rotation.w,
                tf_stamped.transform.rotation.x,
                tf_stamped.transform.rotation.y,
                tf_stamped.transform.rotation.z);
            tf_BaseToSlam = translation_bf_slam * quaternion_bf_slam;
        }
    }
}

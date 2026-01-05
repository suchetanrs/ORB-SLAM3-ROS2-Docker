/**
 * @file type_conversion.hpp
 * @brief Class handling the conversions between data types for ORB-SLAM3 Wrapper.
 * @author Suchetan R S (rssuchetan@gmail.com)
 */

#ifndef ORB_WRAPPER_TYPE_CONVERSIONS_HPP_
#define ORB_WRAPPER_TYPE_CONVERSIONS_HPP_

#include <Eigen/Core>
#include <Eigen/Geometry>
#include "sophus/se3.hpp"

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>

#include <sensor_msgs/msg/point_cloud2.hpp>

#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Vector3.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2_eigen/tf2_eigen.hpp>

#include "MapPoint.h"

namespace ORB_SLAM3_Wrapper
{
    namespace WrapperTypeConversions
    {
        // **************************************DATA TYPE CONVERSIONS*************************************
        /**
         * @brief Converts a ROS timestamp to seconds.
         * @param stamp The ROS timestamp to convert.
         * @return The corresponding time in seconds.
         */
        double stampToSec(builtin_interfaces::msg::Time stamp);

        /**
         * @brief Converts seconds to a ROS timestamp.
         * @param seconds The time in seconds.
         * @return The corresponding ROS timestamp.
         */
        builtin_interfaces::msg::Time secToStamp(double seconds);

        /**
         * @brief Converts an Eigen vector to a geometry_msgs Point message.
         * @param e The Eigen vector to convert.
         * @return The corresponding Point message.
         */
        geometry_msgs::msg::Point eigenToPointMsg(Eigen::Vector3f &e);

        /**
         * @brief Converts an Eigen quaternion to a geometry_msgs Quaternion message.
         * @param e The Eigen quaternion to convert.
         * @return The corresponding Quaternion message.
         */
        geometry_msgs::msg::Quaternion eigenToQuaternionMsg(Eigen::Quaternionf &e);

        /**
         * @note Essentially, this converts the ORB coordinates pose of the world frame in the camera frame (Tcw) 
         * to camera frame in world frame of ROS coordinates.
         * @brief Converts a Sophus SE3f transform to a Affine Transform.
         * @param s The Sophus SE3f transform.
         * @return The corresponding Affine Transform in world frame of ROS coordinates.
         * @attention Use only with Tcw. Will not work with Twc.
         */
        Eigen::Affine3f se3ORBToROS(const Sophus::SE3f &s);

        Sophus::SE3f se3ROSToORB(const Eigen::Affine3f &affineMatrix);

        /**
         * @brief This function converts a vector in the world frame of ORB coordinates 
         * to a vector in the world frame of ROS coordinates.
         * @param s The Vector transform.
         * @return The corresponding vector after transform.
         */
        Eigen::Vector3f vector3fORBToROS(const Eigen::Vector3f &s);

        /**
         * @brief Converts a Sophus SE3f transform to an Eigen Affine3f transform.
         * @param s The Sophus SE3f transform.
         * @return The corresponding Eigen Affine3f transform.
         */
        Eigen::Affine3f se3ToAffine(const Sophus::SE3f &s);

        Eigen::Affine3f poseToAffine(const geometry_msgs::msg::Pose &pose);

        /** 
        * @brief Given a rotation matrix in Twc ORB Coordinates, outputs the euler angles [Roll, Pitch, Yaw] in ROS Coordinates. Range of euler angles [0, 2*PI)
         */
        Eigen::Vector3f rotationORBToEulerROS(const Eigen::Matrix3f& rotation);
        
        /**
         * @brief Converts a Sophus SE3f transform to a geometry_msgs Pose message.
         * @param s The Sophus SE3f transform.
         * @return The corresponding Pose message.
         */
        geometry_msgs::msg::Pose se3ToPoseMsg(const Sophus::SE3f &s);

        geometry_msgs::msg::Pose affine3fToPose(const Eigen::Affine3f & in);

        sensor_msgs::msg::PointCloud2 MapPointsToPCL(std::vector<Eigen::Vector3f>& mapPoints);

        sensor_msgs::msg::PointCloud2 MapPointsToPCL(std::vector<ORB_SLAM3::MapPoint*>& mapPoints);

        // **************************************TRANSFORMATIONS*************************************
        /**
         * @brief Transforms a pose using a reference pose and SE3 transform.
         * @param referencePose Reference pose.
         * @param s SE3 transform.
         * @return Transformed pose.
         */
        template <typename T>
        T transformPoseWithReference(Eigen::Affine3f &, const Sophus::SE3f &);

        /**
         * @brief Transforms a pose using a reference pose and SE3 transform.
         * @param referencePose Reference pose.
         * @param s SE3 transform.
         * @return Transformed pose.
         */
        template <typename T>
        T transformPointWithReference(Eigen::Affine3f &referencePose, Eigen::Vector3f &s);
    };
}

#endif

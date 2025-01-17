/**
 * @file type_conversion.cpp
 * @brief Class handling the conversions between data types for ORB-SLAM3 Wrapper.
 * @author Suchetan R S (rssuchetan@gmail.com)
 */

#include "orb_slam3_ros2_wrapper/type_conversion.hpp"
#include "sophus/se3.hpp"

namespace ORB_SLAM3_Wrapper
{
    double WrapperTypeConversions::stampToSec(builtin_interfaces::msg::Time stamp)
    {
        double seconds = stamp.sec + (stamp.nanosec * pow(10, -9));
        return seconds;
    }

    builtin_interfaces::msg::Time WrapperTypeConversions::secToStamp(double seconds)
    {
        builtin_interfaces::msg::Time stamp;
        stamp.sec = static_cast<int32_t>(std::floor(seconds));
        stamp.nanosec = static_cast<uint32_t>((seconds - stamp.sec) * pow(10, 9));
        return stamp;
    }

    geometry_msgs::msg::Point WrapperTypeConversions::eigenToPointMsg(Eigen::Vector3f &e)
    {
        geometry_msgs::msg::Point p;
        p.x = e.x();
        p.y = e.y();
        p.z = e.z();
        return p;
    }

    geometry_msgs::msg::Quaternion WrapperTypeConversions::eigenToQuaternionMsg(Eigen::Quaternionf &e)
    {
        geometry_msgs::msg::Quaternion q;
        q.w = e.w();
        q.x = e.x();
        q.y = e.y();
        q.z = e.z();
        return q;
    }

    Eigen::Affine3f WrapperTypeConversions::se3ORBToROS(const Sophus::SE3f &s)
    {
        Eigen::Matrix3f tfCameraRotation = s.rotationMatrix();
        Eigen::Vector3f tfCameraTranslation = s.translation();

        Eigen::Matrix3f tfORBToROS;
        tfORBToROS << 0, 0, 1,
            -1, 0, 0,
            0, -1, 0;

        // Transform from orb coordinate system to ros coordinate system on camera coordinates
        Eigen::Matrix3f tfCameraRotationTemp = tfORBToROS * tfCameraRotation;
        Eigen::Vector3f tfCameraTranslationTemp = tfORBToROS * tfCameraTranslation;

        // Inverse matrix (Tcw -> Twc, converts to map frame of ROS coordinates)
        Eigen::Matrix3f tfCameraRotationInv = tfCameraRotationTemp.transpose();
        Eigen::Vector3f tfCameraTranslationInv = -(tfCameraRotationInv * tfCameraTranslationTemp);

        // Transform from orb coordinate system to ros coordinate system on map coordinates
        tfCameraRotation = tfORBToROS * tfCameraRotationInv;
        tfCameraTranslation = tfORBToROS * tfCameraTranslationInv;

        Eigen::Affine3f affineMatrix = Eigen::Affine3f::Identity();
        affineMatrix.rotate(tfCameraRotation);
        affineMatrix.translation() = tfCameraTranslation;

        return affineMatrix;
    }

    Sophus::SE3f WrapperTypeConversions::se3ROSToORB(const Eigen::Affine3f &affineMatrix)
    {
        // Extract rotation and translation from the affine matrix
        Eigen::Matrix3f tfCameraRotation = affineMatrix.rotation();
        Eigen::Vector3f tfCameraTranslation = affineMatrix.translation();

        // Define the transformation matrix from ROS to ORB coordinate system
        Eigen::Matrix3f tfROSToORB;
        tfROSToORB << 0, -1, 0,
                    0,  0, -1,
                    1,  0,  0;

        // Transform from ROS coordinate system to ORB coordinate system on map coordinates
        Eigen::Matrix3f tfCameraRotationTemp = tfROSToORB * tfCameraRotation;
        Eigen::Vector3f tfCameraTranslationTemp = tfROSToORB * tfCameraTranslation;

        // Inverse matrix (Twc -> Tcw, converts to camera frame of ORB coordinates)
        Eigen::Matrix3f tfCameraRotationInv = tfCameraRotationTemp.transpose();
        Eigen::Vector3f tfCameraTranslationInv = -(tfCameraRotationInv * tfCameraTranslationTemp);

        // Transform from ROS coordinate system to ORB coordinate system on camera coordinates
        tfCameraRotation = tfROSToORB * tfCameraRotationInv;
        tfCameraTranslation = tfROSToORB * tfCameraTranslationInv;

        // Create and return the Sophus::SE3f object
        return Sophus::SE3f(tfCameraRotation, tfCameraTranslation);
    }

    Eigen::Vector3f WrapperTypeConversions::vector3fORBToROS(const Eigen::Vector3f &s)
    {
        Eigen::Matrix3f tfCameraRotation = Eigen::Matrix3f::Identity();
        Eigen::Vector3f tfCameraTranslation = s;

        // Coordinate transformation matrix from orb coordinate system to ros coordinate system
        Eigen::Matrix3f tfORBToROS;
        tfORBToROS << 0, 0, 1,
            -1, 0, 0,
            0, -1, 0;

        // Transform from orb coordinate system to ros coordinate system on camera coordinates
        Eigen::Matrix3f tfCameraRotationTemp = tfORBToROS * tfCameraRotation;
        Eigen::Vector3f tfCameraTranslationTemp = tfORBToROS * tfCameraTranslation;

        tfCameraRotation = tfCameraRotationTemp;
        tfCameraTranslation = tfCameraTranslationTemp;

        return tfCameraTranslation;
    }

    Eigen::Affine3d WrapperTypeConversions::se3ToAffine(const Sophus::SE3f &s)
    {
        Eigen::Affine3d affineTf = se3ORBToROS(s).cast<double>();
        return affineTf;
    }

    Eigen::Affine3f WrapperTypeConversions::poseToAffine(const geometry_msgs::msg::Pose &pose)
    {
        auto translation = Eigen::Translation3f(
            static_cast<float>(pose.position.x),
            static_cast<float>(pose.position.y),
            static_cast<float>(pose.position.z));
        auto quaternion = Eigen::Quaternion<float>(
            static_cast<float>(pose.orientation.w), // w
            static_cast<float>(pose.orientation.x),   // x
            static_cast<float>(pose.orientation.y), // y
            static_cast<float>(pose.orientation.z));  // z
        return translation * quaternion;
    }

    Eigen::Vector3f WrapperTypeConversions::rotationORBToEulerROS(const Eigen::Matrix3f& rotation)
    {
        auto eulerAngles = rotation.eulerAngles(2, 0, 1);
        eulerAngles[1] = -eulerAngles[1];
        eulerAngles[2] = -eulerAngles[2];

        eulerAngles[0] = eulerAngles[0] < 0 ? (2 * M_PI) + eulerAngles[0] : eulerAngles[0]; 
        eulerAngles[1] = eulerAngles[1] < 0 ? (2 * M_PI) + eulerAngles[1] : eulerAngles[1]; 
        eulerAngles[2] = eulerAngles[2] < 0 ? (2 * M_PI) + eulerAngles[2] : eulerAngles[2]; 
        return eulerAngles;
    }

    geometry_msgs::msg::Pose WrapperTypeConversions::se3ToPoseMsg(const Sophus::SE3f &s)
    {
        Eigen::Affine3d poseTransform = se3ORBToROS(s).cast<double>();
        geometry_msgs::msg::Pose pose = tf2::toMsg(poseTransform);
        return pose;
    }

    sensor_msgs::msg::PointCloud2 WrapperTypeConversions::MapPointsToPCL(std::vector<Eigen::Vector3f>& mapPoints)
    {
        const int numChannels = 3; // x y z

        if (mapPoints.size() == 0)
        {
            std::cout << "Map point vector is empty!" << std::endl;
        }

        sensor_msgs::msg::PointCloud2 cloud;

        // cloud.header.stamp = current_frame_time;
        cloud.header.frame_id = "map";
        cloud.height = 1;
        cloud.width = mapPoints.size();
        cloud.is_bigendian = false;
        cloud.is_dense = true;
        cloud.point_step = numChannels * sizeof(float);
        cloud.row_step = cloud.point_step * cloud.width;
        cloud.fields.resize(numChannels);

        std::string channel_id[] = {"x", "y", "z"};

        for (int i = 0; i < numChannels; i++)
        {
            cloud.fields[i].name = channel_id[i];
            cloud.fields[i].offset = i * sizeof(float);
            cloud.fields[i].count = 1;
            cloud.fields[i].datatype = sensor_msgs::msg::PointField::FLOAT32;
        }

        cloud.data.resize(cloud.row_step * cloud.height);

        unsigned char *cloud_data_ptr = &(cloud.data[0]);

        for (unsigned int i = 0; i < cloud.width; i++)
        {
            Eigen::Vector3f point_translation = mapPoints[i];

            float data_array[numChannels] = {
                point_translation.x(), point_translation.y(), point_translation.z()};

            memcpy(cloud_data_ptr + (i * cloud.point_step), data_array,
                    numChannels * sizeof(float));
        }
        return cloud;
    }


    sensor_msgs::msg::PointCloud2 WrapperTypeConversions::MapPointsToPCL(std::vector<ORB_SLAM3::MapPoint*>& mapPoints)
    {
        const int numChannels = 3; // x y z

        if (mapPoints.size() == 0)
        {
            std::cout << "Map point vector is empty!" << std::endl;
        }

        sensor_msgs::msg::PointCloud2 cloud;

        // cloud.header.stamp = current_frame_time;
        cloud.header.frame_id = "map";
        cloud.height = 1;
        cloud.width = mapPoints.size();
        cloud.is_bigendian = false;
        cloud.is_dense = true;
        cloud.point_step = numChannels * sizeof(float);
        cloud.row_step = cloud.point_step * cloud.width;
        cloud.fields.resize(numChannels);

        std::string channel_id[] = {"x", "y", "z"};

        for (int i = 0; i < numChannels; i++)
        {
            cloud.fields[i].name = channel_id[i];
            cloud.fields[i].offset = i * sizeof(float);
            cloud.fields[i].count = 1;
            cloud.fields[i].datatype = sensor_msgs::msg::PointField::FLOAT32;
        }

        cloud.data.resize(cloud.row_step * cloud.height);

        unsigned char *cloud_data_ptr = &(cloud.data[0]);

        for (unsigned int i = 0; i < cloud.width; i++)
        {
            Eigen::Vector3f point_translation = vector3fORBToROS(mapPoints[i]->GetWorldPos());

            float data_array[numChannels] = {
                point_translation.x(), point_translation.y(), point_translation.z()};

            memcpy(cloud_data_ptr + (i * cloud.point_step), data_array,
                    numChannels * sizeof(float));
        }
        return cloud;
    }

    template <>
    geometry_msgs::msg::Pose WrapperTypeConversions::transformPoseWithReference(Eigen::Affine3d &affineMapToRef, Sophus::SE3f &transform)
    {
        // Convert SE3 to affine.
        auto affine_map_to_pose = affineMapToRef * se3ToAffine(transform);
        return tf2::toMsg(affine_map_to_pose);
    }

    template <>
    Eigen::Affine3d WrapperTypeConversions::transformPoseWithReference(Eigen::Affine3d &affineMapToRef, Sophus::SE3f &transform)
    {
        // Convert SE3 to affine.
        auto affineMapToPose = affineMapToRef * se3ToAffine(transform);
        return affineMapToPose;
    }

    template <>
    geometry_msgs::msg::Point WrapperTypeConversions::transformPointWithReference(Eigen::Affine3d &affineMapToRef, Eigen::Vector3f &point)
    {
        auto affine_map_to_pose = affineMapToRef.cast<float>() * point;
        return eigenToPointMsg(affine_map_to_pose);
    }

    template <>
    Eigen::Vector3f WrapperTypeConversions::transformPointWithReference(Eigen::Affine3d &affineMapToRef, Eigen::Vector3f &point)
    {
        auto affine_map_to_pose = affineMapToRef.cast<float>() * point;
        return affine_map_to_pose;
    }
}
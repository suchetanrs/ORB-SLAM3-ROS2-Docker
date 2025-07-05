#include <rclcpp/rclcpp.hpp>
#include <slam_msgs/srv/get_global_point_cloud.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <slam_msgs/msg/map_data.hpp>

// TF2 / Transform includes
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_eigen/tf2_eigen.hpp>

// PCL includes for transforming / concatenating pointclouds
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/voxel_grid.h>

#include <deque>
#include <vector>
#include <limits>
#include <memory>
#include <mutex>
#include <unordered_map>

class DepthPointcloudStitcher : public rclcpp::Node
{
public:
    DepthPointcloudStitcher()
        : Node("orb_slam3_pointcloud_stitcher"),
          buffer_duration_(3.0),
          tf_buffer_(this->get_clock()),
          tf_listener_(tf_buffer_),
          pointcloud_frame_id_(nullptr),
          robot_base_frame_id_("base_footprint")
    {
        // Create separate callback groups
        callback_group_pc_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        callback_group_map_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        callback_group_service_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

        // Setup subscription options for each callback group
        rclcpp::SubscriptionOptions pc_sub_options;
        pc_sub_options.callback_group = callback_group_pc_;

        rclcpp::SubscriptionOptions map_sub_options;
        map_sub_options.callback_group = callback_group_map_;

        this->declare_parameter("depth_pointcloud_topic", "lidar/points");
        std::string pc_topic;
        this->get_parameter("depth_pointcloud_topic", pc_topic);

        this->declare_parameter("input_pointcloud_rate", 10.0);
        this->get_parameter("input_pointcloud_rate", input_pointcloud_rate_);

        this->declare_parameter("robot_base_frame", "base_footprint");
        this->get_parameter("robot_base_frame", robot_base_frame_id_);

        // 1) Subscribers
        pc_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
            pc_topic,
            rclcpp::QoS(rclcpp::KeepLast(10)).reliable().durability_volatile(),
            std::bind(&DepthPointcloudStitcher::pointCloudCallback, this, std::placeholders::_1), pc_sub_options);

        map_graph_sub_ = this->create_subscription<slam_msgs::msg::MapData>(
            "/map_data",
            10,
            std::bind(&DepthPointcloudStitcher::MapDataCallback, this, std::placeholders::_1), map_sub_options);

        // 2) Publisher for the final global pointcloud
        global_pc_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("global_pointcloud", 1);

        // 3) Service for triggering processing and publishing
        process_service_ = this->create_service<slam_msgs::srv::GetGlobalPointCloud>(
            "trigger_global_cloud",
            std::bind(&DepthPointcloudStitcher::processServiceCallback, this,
                      std::placeholders::_1, std::placeholders::_2));

        RCLCPP_INFO(this->get_logger(), "DepthPointcloudStitcher node started.");
    }

private:
    // Depth camera pointcloud subscriber
    void pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
    {
        // RCLCPP_INFO_STREAM(this->get_logger(), "Received pointcloud");
        buffer_mutex_.lock();
        pointcloud_buffer_.push_back(msg);
        if (pointcloud_frame_id_ == nullptr)
        {
            pointcloud_frame_id_ = std::make_shared<std::string>(msg->header.frame_id);
        }

        // Remove old messages beyond our desired buffer duration
        auto newest_time = rclcpp::Time(msg->header.stamp);
        while (!pointcloud_buffer_.empty())
        {
            auto oldest_time = rclcpp::Time(pointcloud_buffer_.front()->header.stamp);
            if ((newest_time - oldest_time).seconds() > buffer_duration_)
            {
                pointcloud_buffer_.pop_front();
            }
            else
            {
                break;
            }
        }
        buffer_mutex_.unlock();
    }

    // ORB-SLAM3 MapData subscriber
    void MapDataCallback(const slam_msgs::msg::MapData::SharedPtr msg)
    {
        std::lock_guard<std::mutex> lock(global_pcl_mutex_);
        if (msg->graph.poses_id.size() != msg->graph.poses.size())
        {
            RCLCPP_ERROR(this->get_logger(),
                         "MapData message has mismatch in poses_id and poses size! Skipping...");
            return;
        }

        RCLCPP_WARN_STREAM(this->get_logger(), "Map data: " << msg->graph.poses_id.size());

        // Match each pose to the closest pointcloud in time
        for (size_t i = 0; i < msg->graph.poses_id.size(); ++i)
        {
            auto pose_id = msg->graph.poses_id[i];
            auto pose_stamp = msg->graph.poses[i].header.stamp;
            auto pose_only = msg->graph.poses[i].pose;
            stored_poses_[pose_id] = pose_only;
            rclcpp::Time pose_time(pose_stamp);
            if (stored_pose_clouds_.find(pose_id) != stored_pose_clouds_.end())
                continue;

            double best_time_diff = std::numeric_limits<double>::infinity();
            std::shared_ptr<sensor_msgs::msg::PointCloud2> best_match = nullptr;

            buffer_mutex_.lock();
            for (auto pc : pointcloud_buffer_)
            {
                rclcpp::Time pc_time(pc->header.stamp);
                double diff = std::abs((pc_time - pose_time).seconds());
                if (diff < best_time_diff)
                {
                    best_time_diff = diff;
                    best_match = pc;
                }
            }
            buffer_mutex_.unlock();

            if (best_match && std::find(discarded_pose_ids_.begin(), discarded_pose_ids_.end(), pose_id) == discarded_pose_ids_.end())
            {
                if (best_time_diff > 1.0 / input_pointcloud_rate_ * 2.0)
                {
                    RCLCPP_ERROR_STREAM(this->get_logger(), "pose_id: " << pose_id << " || BEST MATCH PCL HAS A VERY HIGH TIMESTAMP DIFF: " << best_time_diff);
                    discarded_pose_ids_.push_back(pose_id);
                    continue;
                }
                stored_pose_clouds_[pose_id] = best_match;

                RCLCPP_INFO(this->get_logger(),
                            "Stored pointcloud for pose_id=%d (time diff=%.6f sec).",
                            pose_id, best_time_diff);
            }
            else
            {
                // RCLCPP_WARN(this->get_logger(),
                //             "No matching pointcloud found for pose_id=%d.", pose_id);
            }
        }
    }

    /**
     * Service callback:
     *   - If request->data == true:
     *       1) Transform each stored pointcloud into the map frame
     *       2) Publish the accumulated cloud
     */
    void processServiceCallback(const std::shared_ptr<slam_msgs::srv::GetGlobalPointCloud::Request> request,
                                std::shared_ptr<slam_msgs::srv::GetGlobalPointCloud::Response> response)
    {
        std::lock_guard<std::mutex> lock(global_pcl_mutex_);

        RCLCPP_INFO(this->get_logger(), "Processing stored clouds...");
        if (pointcloud_frame_id_ == nullptr)
        {
            RCLCPP_ERROR(this->get_logger(), "Pointcloud frame id null. Cannot process this call.");
            response->response = false;
            return;
        }

        // 1) Transform each stored pointcloud into the map frame

        // 1.a) Lookup the static transform from lidar_link -> base_footprint once
        geometry_msgs::msg::TransformStamped cdo_to_cl;
        try
        {
            // If your frames are reversed, swap the order below
            cdo_to_cl = tf_buffer_.lookupTransform(
                robot_base_frame_id_,  // target frame
                *pointcloud_frame_id_, // source frame
                tf2::TimePointZero);
        }
        catch (const tf2::TransformException &ex)
        {
            RCLCPP_ERROR(this->get_logger(), "TF lookup exception: %s", ex.what());
            response->response = false;
            return;
        }
        // TF from lidar_link -> base_footprint.
        // If cdo_to_cl is T_CL_CDO, then its Eigen form is:
        Eigen::Isometry3d T_CL_CDO = tf2::transformToEigen(cdo_to_cl.transform);

        // Use an accumulating PCL cloud in map frame
        pcl::PointCloud<pcl::PointXYZRGB> global_map_cloud;
        global_map_cloud.clear();
        float max_z = request->z_thresh_max;
        bool use_grayscale = request->get_grayscale;

        // For each stored (pose, pointcloud)
        for (const auto &pair : stored_pose_clouds_)
        {
            const auto &pose_id = pair.first;
            const auto cloud_msg = pair.second;
            const auto &camera_pose = stored_poses_[pose_id]; // geometry_msgs::msg::Pose

            // Convert the sensor_msgs cloud to PCL
            pcl::PointCloud<pcl::PointXYZRGB> pcl_in_dense;
            pcl::fromROSMsg(*cloud_msg, pcl_in_dense);

            pcl::PointCloud<pcl::PointXYZRGB> pcl_in;
            pcl::VoxelGrid<pcl::PointXYZRGB> local_voxel_filter;
            local_voxel_filter.setInputCloud(pcl_in_dense.makeShared());
            local_voxel_filter.setLeafSize(request->local_voxel_resolution, request->local_voxel_resolution, request->local_voxel_resolution); // 5 cm voxel size
            local_voxel_filter.filter(pcl_in);

            // Build an Eigen transform from the geometry_msgs::Pose.
            // Here we assume Pose is T_map_cameraLink: (map -> base_footprint).
            Eigen::Isometry3d T_map_CL = poseToEigen(camera_pose);

            // So final transform from lidar_link -> map:
            //   T_map_CDO = T_map_CL * T_CL_CDO
            Eigen::Isometry3d T_map_CDO = T_map_CL * T_CL_CDO;

            // Transform each point in pcl_in
            pcl::PointCloud<pcl::PointXYZRGB> pcl_out;
            pcl_out.reserve(pcl_in.size());
            for (const auto &pt : pcl_in)
            {
                // Skip invalid points if needed
                if (!std::isfinite(pt.x) || !std::isfinite(pt.y) || !std::isfinite(pt.z))
                    continue;

                if (pt.z > max_z)
                    continue;

                Eigen::Vector3d p_in(pt.x, pt.y, pt.z);
                Eigen::Vector3d p_out = T_map_CDO * p_in;

                // Make a copy that includes the color fields
                pcl::PointXYZRGB transformed_pt;
                transformed_pt.x = p_out.x();
                transformed_pt.y = p_out.y();
                transformed_pt.z = p_out.z();
                transformed_pt.rgb = pt.rgb; // Copy the color
                if (use_grayscale)
                {
                    auto gray = 0.299 * transformed_pt.r + 0.587 * transformed_pt.g + 0.114 * transformed_pt.b;
                    transformed_pt.r = gray;
                    transformed_pt.g = gray;
                    transformed_pt.b = gray;
                }

                pcl_out.push_back(transformed_pt);
            }

            // Append to the global map cloud
            global_map_cloud += pcl_out;

            RCLCPP_INFO(this->get_logger(), "Transformed cloud for pose_id=%d, size=%lu points.",
                        pose_id, pcl_out.size());
        }

        pcl::PointCloud<pcl::PointXYZRGB> global_map_filtered;
        pcl::VoxelGrid<pcl::PointXYZRGB> global_voxel_filter;
        global_voxel_filter.setInputCloud(global_map_cloud.makeShared());
        global_voxel_filter.setLeafSize(request->global_voxel_resolution, request->global_voxel_resolution, request->global_voxel_resolution); // 5 cm voxel size
        global_voxel_filter.filter(global_map_filtered);

        // 3) Convert global_map_filtered back to sensor_msgs and publish
        sensor_msgs::msg::PointCloud2 output;
        pcl::toROSMsg(global_map_filtered, output);
        output.header.frame_id = "map";
        output.header.stamp = this->now();
        global_pc_pub_->publish(output);

        RCLCPP_INFO(this->get_logger(), "Published accumulated global map cloud with %lu points.",
                    global_map_filtered.size());

        response->response = true;
    }

    /******************************************
     * Helpers
     ******************************************/

    // Helper to convert geometry_msgs::Pose to an Eigen::Isometry3d
    Eigen::Isometry3d poseToEigen(const geometry_msgs::msg::Pose &pose_msg)
    {
        Eigen::Quaterniond q(
            pose_msg.orientation.w,
            pose_msg.orientation.x,
            pose_msg.orientation.y,
            pose_msg.orientation.z);
        Eigen::Vector3d t(
            pose_msg.position.x,
            pose_msg.position.y,
            pose_msg.position.z);

        Eigen::Isometry3d transform = Eigen::Isometry3d::Identity();
        transform.linear() = q.toRotationMatrix();
        transform.translation() = t;
        return transform;
    }

    /******************************************
     * Members
     ******************************************/

    // Subscriptions
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr pc_sub_;
    rclcpp::Subscription<slam_msgs::msg::MapData>::SharedPtr map_graph_sub_;

    // Publisher
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr global_pc_pub_;

    // Service
    rclcpp::Service<slam_msgs::srv::GetGlobalPointCloud>::SharedPtr process_service_;

    // TF
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;

    // Pointcloud buffer and stored pairings
    std::deque<std::shared_ptr<sensor_msgs::msg::PointCloud2>> pointcloud_buffer_;
    std::mutex buffer_mutex_;
    double buffer_duration_;
    double input_pointcloud_rate_;
    std::shared_ptr<std::string> pointcloud_frame_id_;
    std::string robot_base_frame_id_;

    // For each matched pose-cloud pair, store the Pose as well
    std::unordered_map<int32_t, std::shared_ptr<sensor_msgs::msg::PointCloud2>> stored_pose_clouds_; // (pose_id, PC)
    std::unordered_map<int32_t, geometry_msgs::msg::Pose> stored_poses_;                             // Matching geometry_msgs::Pose
    std::mutex global_pcl_mutex_;                                                                    // protects stored_point_clouds_
    std::vector<int32_t> discarded_pose_ids_; // For debugging, store the pose ids

    // Callback groups
    rclcpp::CallbackGroup::SharedPtr callback_group_pc_;
    rclcpp::CallbackGroup::SharedPtr callback_group_map_;
    rclcpp::CallbackGroup::SharedPtr callback_group_service_;
};

// Main
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DepthPointcloudStitcher>();

    // Use a multithreaded executor to allow callbacks in different groups to run concurrently
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
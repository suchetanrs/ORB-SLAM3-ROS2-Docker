#!/usr/bin/python3
# -*- coding: utf-8 -*-
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from nav2_common.launch import RewrittenYaml


def generate_launch_description():
    orb_wrapper_pkg = get_package_share_directory("orb_slam3_ros2_wrapper")

    use_sim_time = LaunchConfiguration("use_sim_time")
    declare_use_sim_time_cmd = DeclareLaunchArgument(
        name="use_sim_time",
        default_value="True",
        description="Use simulation (Gazebo) clock if true",
    )

    robot_namespace = LaunchConfiguration("robot_namespace")
    robot_namespace_arg = DeclareLaunchArgument(
        "robot_namespace", default_value="robot", description="The namespace of the robot"
    )

    def all_nodes_launch(context, robot_namespace):
        params_file = LaunchConfiguration("params_file")
        vocabulary_file_path = "/home/orb/ORB_SLAM3/Vocabulary/ORBvoc.txt"
        # NOTE: keep settings path consistent with existing launch files. Replace as needed.
        config_file_path = "/root/colcon_ws/src/orb_slam3_ros2_wrapper/params/orb_slam3_params/gazebo_mono_imu.yaml"

        declare_params_file_cmd = DeclareLaunchArgument(
            "params_file",
            default_value=os.path.join(orb_wrapper_pkg, "params", "ros_params", "gazebo-mono-imu-ros-params.yaml"),
            description="Full path to the ROS2 parameters file to use for all launched nodes",
        )

        # Optional namespacing hook (kept consistent with other launch files)
        base_frame = "" if robot_namespace.perform(context) == "" else robot_namespace.perform(context) + "/"
        param_substitutions = {
            # "robot_base_frame": base_frame + "base_footprint",
            # "odom_frame": base_frame + "odom",
        }

        configured_params = RewrittenYaml(
            source_file=params_file,
            root_key=robot_namespace.perform(context),
            param_rewrites=param_substitutions,
            convert_types=True,
        )

        orb_slam3_node = Node(
            package="orb_slam3_ros2_wrapper",
            executable="mono_imu",
            output="screen",
            namespace=robot_namespace.perform(context),
            arguments=[vocabulary_file_path, config_file_path],
            parameters=[configured_params],
        )

        return [declare_params_file_cmd, orb_slam3_node]

    opaque_function = OpaqueFunction(function=all_nodes_launch, args=[robot_namespace])

    return LaunchDescription(
        [
            declare_use_sim_time_cmd,
            robot_namespace_arg,
            opaque_function,
        ]
    )



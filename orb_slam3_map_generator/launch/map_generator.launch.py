#!/usr/bin/python3
# -*- coding: utf-8 -*-
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.actions import IncludeLaunchDescription, OpaqueFunction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, FindExecutable, TextSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from nav2_common.launch import RewrittenYaml

def generate_launch_description():

#---------------------------------------------

    #Essential_paths
    orb_map_generator_pkg = get_package_share_directory('orb_slam3_map_generator')
#---------------------------------------------

    # LAUNCH ARGS
    use_sim_time = LaunchConfiguration('use_sim_time')
    declare_use_sim_time_cmd = DeclareLaunchArgument(
        name='use_sim_time',
        default_value='True',
        description='Use simulation (Gazebo) clock if true')
#---------------------------------------------
    
    depth_image_to_pcl_node = Node(
        package='orb_slam3_map_generator',
        executable='depth_image_to_pcl',
        output='screen',
        # prefix=["gdbserver localhost:3000"],
        parameters=["/root/colcon_ws/src/orb_slam3_map_generator/param/map_generator_params.yaml"])
    
    stitch_pcl_node = Node(
        package='orb_slam3_map_generator',
        executable='pointcloud_stitcher',
        output='screen',
        # prefix=["gdbserver localhost:3000"],
        parameters=["/root/colcon_ws/src/orb_slam3_map_generator/param/map_generator_params.yaml"])
    
#---------------------------------------------

    return LaunchDescription([
        declare_use_sim_time_cmd,
        # depth_image_to_pcl_node,
        stitch_pcl_node
    ])

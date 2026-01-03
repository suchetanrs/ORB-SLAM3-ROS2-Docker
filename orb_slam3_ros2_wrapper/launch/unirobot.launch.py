import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    # Set environment variables
    robot_namespace = ""

    orb_slam3_launch_file_dir = os.path.join(
        get_package_share_directory('orb_slam3_ros2_wrapper'), 'launch')

    orb_slam3_launch_file_path = os.path.join(
            orb_slam3_launch_file_dir, 'rgbd.launch.py')

    # Launch the rgbd.launch.py file
    orb_slam3_launch_description = IncludeLaunchDescription(
            PythonLaunchDescriptionSource(orb_slam3_launch_file_path),
            launch_arguments={"robot_namespace": robot_namespace}.items(),
    )

    monitor_enabled_arg = DeclareLaunchArgument(
        "monitor_enabled",
        default_value="true",
        description="Enable lightweight CPU/RAM monitor for process 'rgbd'.",
    )

    # Print to screen: monitor should log to stdout
    monitor_process = ExecuteProcess(
        condition=IfCondition(LaunchConfiguration("monitor_enabled")),
        cmd=[
            "/root/colcon_ws/src/orb_slam3_ros2_wrapper/scripts/monitor_cpu_ram.sh",
            "--name", "rgbd",
            "--hz", "0.3",
            # no --out: stdout goes to screen via `output="screen"`
        ],
        output="screen",
        shell=False,
    )

    return LaunchDescription([
        monitor_enabled_arg,
        orb_slam3_launch_description,
        monitor_process
    ])

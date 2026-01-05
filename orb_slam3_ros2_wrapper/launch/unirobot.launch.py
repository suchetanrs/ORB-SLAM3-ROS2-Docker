import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    robot_namespace = ""
    sensor_config = LaunchConfiguration("sensor_config")
    sensor_config_arg = DeclareLaunchArgument(
        "sensor_config",
        default_value="rgbd",
        description="Sensor configuration to launch: 'rgbd' (default), 'rgbd_imu', 'mono_imu' or 'stereo'")

    orb_slam3_launch_file_dir = os.path.join(
        get_package_share_directory('orb_slam3_ros2_wrapper'), 'launch')

    rgbd_launch_file_path = os.path.join(
        orb_slam3_launch_file_dir, 'rgbd.launch.py')

    rgbd_imu_launch_file_path = os.path.join(
        orb_slam3_launch_file_dir, 'rgbd_imu.launch.py')

    mono_imu_launch_file_path = os.path.join(
        orb_slam3_launch_file_dir, 'mono_imu.launch.py')
    
    stereo_launch_file_path = os.path.join(
        orb_slam3_launch_file_dir, 'stereo.launch.py')

    rgbd_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(rgbd_launch_file_path),
        launch_arguments={"robot_namespace": robot_namespace}.items(),
        condition=IfCondition(PythonExpression(["'", sensor_config, "' == 'rgbd'"])),
    )

    rgbd_imu_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(rgbd_imu_launch_file_path),
        launch_arguments={"robot_namespace": robot_namespace}.items(),
        condition=IfCondition(PythonExpression(["'", sensor_config, "' == 'rgbd_imu'"])),
    )

    mono_imu_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(mono_imu_launch_file_path),
        launch_arguments={"robot_namespace": robot_namespace}.items(),
        condition=IfCondition(PythonExpression(["'", sensor_config, "' == 'mono_imu'"])),
    )
    
    stereo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(stereo_launch_file_path),
        launch_arguments={"robot_namespace": robot_namespace}.items(),
        condition=IfCondition(PythonExpression(["'", sensor_config, "' == 'stereo'"])),
    )

    monitor_enabled_arg = DeclareLaunchArgument(
        "monitor_enabled",
        default_value="true",
        description="Enable lightweight CPU/RAM monitor for the selected sensor configuration.",
    )

    # Print to screen: monitor should log to stdout
    monitor_process = ExecuteProcess(
        condition=IfCondition(LaunchConfiguration("monitor_enabled")),
        cmd=[
            "/root/colcon_ws/src/orb_slam3_ros2_wrapper/scripts/monitor_cpu_ram.sh",
            "--name", sensor_config,
            "--hz", "0.3",
            # no --out: stdout goes to screen via `output="screen"`
        ],
        output="screen",
        shell=False,
    )

    return LaunchDescription([
        sensor_config_arg,
        monitor_enabled_arg,
        monitor_process,
        rgbd_launch,
        rgbd_imu_launch,
        mono_imu_launch,
        stereo_launch,
    ])

cmake_minimum_required(VERSION 3.5)
project(slam_msgs)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(
  include
)

rosidl_generate_interfaces(${PROJECT_NAME}
"msg/MapGraph.msg"
"msg/MapData.msg"
"msg/KeyFrame.msg"
"msg/MapPoint.msg"
"srv/GetMap.srv"
"srv/GetLandmarksInView.srv"
DEPENDENCIES builtin_interfaces geometry_msgs sensor_msgs std_msgs
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()

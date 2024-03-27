cmake_minimum_required(VERSION 3.5)
project(orb_slam3_ros2_wrapper)

# You should set the PYTHONPATH to your own python site-packages path
set(ENV{PYTHONPATH} "/opt/ros/humble/lib/python3.10/site-packages/")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake_auto REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(message_filters REQUIRED)
find_package(Pangolin REQUIRED)
find_package(Sophus REQUIRED)
find_package(ORB_SLAM3 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(slam_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(PCL REQUIRED)
find_package(pcl_ros REQUIRED)
find_package(pcl_conversions REQUIRED)

include_directories(
  include
  ${ORB_SLAM3_ROOT_DIR}/include
  ${ORB_SLAM3_ROOT_DIR}/include/CameraModels
)

# TODO: add check for pcl_found here and in orbslam3
find_package(traversability_mapping)
if(traversability_mapping_FOUND)
   find_package(PCL)
    include_directories(
    ${traversability_mapping_INCLUDE_DIRS}
    ${PCL_INCLUDE_DIRS}
    )
    ADD_DEFINITIONS("-DWITH_TRAVERSABILITY_MAP")
endif(traversability_mapping_FOUND)

link_directories(
  include
)

add_executable(rgbd
  src/type_conversion.cpp
  src/orb_slam3_interface.cpp
  src/rgbd/rgbd-slam-node.cpp
  src/rgbd/rgbd.cpp
)
ament_target_dependencies(rgbd rclcpp sensor_msgs cv_bridge message_filters ORB_SLAM3 Pangolin tf2_ros tf2_eigen slam_msgs pcl_ros pcl_conversions PCL nav_msgs)

# add_executable(test1
#   src/ft.cpp
#   src/test_frame.cpp
# )
ament_target_dependencies(rgbd rclcpp sensor_msgs cv_bridge message_filters ORB_SLAM3 Pangolin tf2_ros tf2_eigen slam_msgs pcl_ros pcl_conversions PCL nav_msgs)
# ament_target_dependencies(test1 rclcpp sensor_msgs cv_bridge message_filters ORB_SLAM3 Pangolin tf2_ros tf2_eigen slam_msgs pcl_ros pcl_conversions PCL nav_msgs)
# test1
target_link_libraries(rgbd ${PCL_LIBRARIES})
if(traversability_mapping_FOUND)
   target_link_libraries(rgbd
   ${PCL_LIBRARIES}
   type_conversion
   traversabilitySystem
   )
endif(traversability_mapping_FOUND)

install(TARGETS rgbd
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch params
DESTINATION share/${PROJECT_NAME}
)

ament_package()


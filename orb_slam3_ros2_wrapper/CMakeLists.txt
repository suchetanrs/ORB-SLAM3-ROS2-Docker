cmake_minimum_required(VERSION 3.5)
project(orb_slam3_ros2_wrapper)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()

MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall   -O3")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall   -O3")
# set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -march=native")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native")

# You should set the PYTHONPATH to your own python site-packages path
set(ENV{PYTHONPATH} "/opt/ros/humble/lib/python3.10/site-packages/")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

# Default to C++20
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
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
install(TARGETS rgbd
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch params
DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(gtest)
  find_package(ament_cmake_gtest REQUIRED)
  ament_find_gtest()
  include_directories(${GTEST_INCLUDE_DIRS})
  link_directories(${GTEST_LIBRARY_DIRS})
  
  ament_add_gtest(typeconversionTests tests/typeConversionsTests.cpp src/type_conversion.cpp)
  ament_target_dependencies(typeconversionTests rclcpp sensor_msgs cv_bridge message_filters ORB_SLAM3 Pangolin tf2_ros tf2_eigen slam_msgs pcl_ros pcl_conversions PCL nav_msgs)
endif()

ament_package()

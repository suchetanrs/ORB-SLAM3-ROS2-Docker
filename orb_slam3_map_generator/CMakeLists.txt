cmake_minimum_required(VERSION 3.5)
project(orb_slam3_map_generator)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()

MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

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
find_package(tf2_ros REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(slam_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)

# Add these lines after existing find_package() calls
find_package(tf2_sensor_msgs REQUIRED)
find_package(pcl_ros REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(PCL REQUIRED COMPONENTS common)

# Update include_directories to include PCL
include_directories(
  include
  ${ORB_SLAM3_ROOT_DIR}/include
  ${ORB_SLAM3_ROOT_DIR}/include/CameraModels
  ${PCL_INCLUDE_DIRS}
)

set(dependencies
  rclcpp
  sensor_msgs
  tf2_ros
  tf2_eigen
  slam_msgs
  tf2_geometry_msgs
  pcl_conversions
  pcl_ros
  PCL
  tf2_sensor_msgs
  std_srvs
  cv_bridge
  image_transport
)

# Add new point cloud stitcher executable
add_executable(pointcloud_stitcher src/stitch_pcl.cpp)
ament_target_dependencies(pointcloud_stitcher ${dependencies})
target_link_libraries(pointcloud_stitcher ${PCL_LIBRARIES})
install(TARGETS pointcloud_stitcher DESTINATION lib/${PROJECT_NAME})

  ##############
add_executable(depth_image_to_pcl src/depth_image_to_pcl.cpp)
ament_target_dependencies(depth_image_to_pcl ${dependencies})
target_link_libraries(depth_image_to_pcl ${PCL_LIBRARIES})
install(TARGETS depth_image_to_pcl DESTINATION lib/${PROJECT_NAME})

  ##############
add_executable(get_landmarks_simulator src/get_landmarks_simulator.cpp)
ament_target_dependencies(get_landmarks_simulator ${dependencies})
target_link_libraries(get_landmarks_simulator ${PCL_LIBRARIES})
install(TARGETS get_landmarks_simulator DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch param
DESTINATION share/${PROJECT_NAME}
)

ament_package()

# CMake generated Testfile for 
# Source directory: /root/colcon_ws/src/orb_slam3_ros2_wrapper
# Build directory: /root/build/orb_slam3_ros2_wrapper
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(typeconversionTests "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/root/build/orb_slam3_ros2_wrapper/test_results/orb_slam3_ros2_wrapper/typeconversionTests.gtest.xml" "--package-name" "orb_slam3_ros2_wrapper" "--output-file" "/root/build/orb_slam3_ros2_wrapper/ament_cmake_gtest/typeconversionTests.txt" "--command" "/root/build/orb_slam3_ros2_wrapper/typeconversionTests" "--gtest_output=xml:/root/build/orb_slam3_ros2_wrapper/test_results/orb_slam3_ros2_wrapper/typeconversionTests.gtest.xml")
set_tests_properties(typeconversionTests PROPERTIES  LABELS "gtest" REQUIRED_FILES "/root/build/orb_slam3_ros2_wrapper/typeconversionTests" TIMEOUT "60" WORKING_DIRECTORY "/root/build/orb_slam3_ros2_wrapper" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/root/colcon_ws/src/orb_slam3_ros2_wrapper/CMakeLists.txt;87;ament_add_gtest;/root/colcon_ws/src/orb_slam3_ros2_wrapper/CMakeLists.txt;0;")
subdirs("gtest")

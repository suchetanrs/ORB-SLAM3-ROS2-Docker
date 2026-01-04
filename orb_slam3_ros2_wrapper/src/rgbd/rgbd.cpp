#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "rgbd-slam-node.hpp"

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        std::cerr << "\nUsage: ros2 run orbslam rgbd path_to_vocabulary path_to_settings" << std::endl;
        return 1;
    }

    rclcpp::init(argc, argv);

#ifdef ORB_SLAM3_ROS2_WRAPPER_ENABLE_CUDA
    bool RunOrbExtractionOnGPU = true;
    bool RunStereoMatchOnGPU = false;
    bool RunSearchLocalPointsOnGPU = true;
    bool RunPoseEstimationOnGPU = true;
    bool RunPoseOptimization = false;

    // RunOrbExtractionOnGPU, RunStereoMatchOnGPU, RunSearchLocalPointsOnGPU, RunPoseEstimationOnGPU, RunPoseOptimization
    KernelController::setGPURunMode(RunOrbExtractionOnGPU, RunStereoMatchOnGPU, RunSearchLocalPointsOnGPU, RunPoseEstimationOnGPU, RunPoseOptimization);
#  pragma message("ORB_SLAM3_ROS2_WRAPPER: CUDA mode enabled (compiling GPU path)")
#endif

    auto node = std::make_shared<ORB_SLAM3_Wrapper::RgbdSlamNode>(argv[1], argv[2], ORB_SLAM3::System::RGBD);
    std::cout << "============================ " << std::endl;

    auto executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
    executor->add_node(node);
    executor->spin();
    rclcpp::shutdown();

    return 0;
}

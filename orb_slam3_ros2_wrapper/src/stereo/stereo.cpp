#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "stereo-slam-node.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "\nUsage: ros2 run orb_slam3_ros2_wrapper stereo path_to_vocabulary path_to_settings" << std::endl;
        return 1;
    }

    rclcpp::init(argc, argv);

    auto node = std::make_shared<ORB_SLAM3_Wrapper::StereoSlamNode>(
        argv[1], argv[2], ORB_SLAM3::System::STEREO);

    auto executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
    executor->add_node(node);
    executor->spin();
    rclcpp::shutdown();

    return 0;
}


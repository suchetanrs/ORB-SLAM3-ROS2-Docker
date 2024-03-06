#!/bin/bash

# Function to terminate all background processes and exit the script
function cleanup_and_exit {
    echo "Ctrl+C detected. Terminating all background processes..."
    sleep 1
    pid=$(pgrep -f "/root/colcon_ws/install/orb_slam3_ros2_wrapper/lib/orb_slam3_ros2_wrapper/rgbd")
    echo "Process is running with PID: $pid"
    echo "Killing process..."
    kill $pid
    sleep 5
    echo "Process killed successfully."
    exit 1
}

# Trap Ctrl+C signal and call the cleanup_and_exit function
trap cleanup_and_exit INT

export ROBOT_NAMESPACE=""
export ROBOT_X="0.0"
export ROBOT_Y="0.0"
ros2 launch orb_slam3_ros2_wrapper rgbd.launch.py &

wait
#!/bin/bash

# Function to terminate all background processes and exit the script
function cleanup_and_exit {
    echo "Ctrl+C detected. Terminating all background processes..."
    sleep 1
    pid=$(pgrep -f "/root/colcon_ws/install/orb_slam3_ros2_wrapper/lib/orb_slam3_ros2_wrapper/rgbd")
    echo "Process is running with PID: $pid"
    kill $pid
    echo "Waiting for cleanup"
    sleep 5
    echo "Clean finish (I hope lol)"
    exit 1
}

# Trap Ctrl+C signal and call the cleanup_and_exit function
trap cleanup_and_exit INT

export ROBOT_NAMESPACE="scout_2"
export ROBOT_X="1.0"
export ROBOT_Y="1.0"
mkdir /home/$ROBOT_NAMESPACE
ros2 launch orb_slam3_ros2_wrapper rgbd.launch.py &

export ROBOT_NAMESPACE="scout_1"
export ROBOT_X="-8.5"
export ROBOT_Y="7.5"
mkdir /home/$ROBOT_NAMESPACE
ros2 launch orb_slam3_ros2_wrapper rgbd.launch.py &

wait

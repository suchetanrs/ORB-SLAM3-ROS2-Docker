#!/bin/bash

SESSION_NAME="gz_sim_dev_tmux"
tmux new-session -d -s $SESSION_NAME

tmux split-window -h
tmux split-window -v
tmux select-pane -t 0
tmux split-window -v
tmux select-pane -t 1
# tmux split-window -v
# tmux select-pane -t 2
# tmux split-window -v

tmux send-keys -t 0 "cd && source colcon_ws/install/setup.bash && ros2 launch orb_slam3_ros2_wrapper unirobot.launch.py"
tmux send-keys -t 1 "cd && source trav_ws/install/setup.bash && ros2 launch traversability_mapping_ros local_traversability_mapping.launch.py"
tmux send-keys -t 2 "cd /home/traversability/traversability_mapping/ && ./build.sh && cd /home/orb/ORB_SLAM3/ && ./build.sh && cd /root/colcon_ws/ && colcon build --symlink-install && cd /root/trav_ws/ && colcon build --symlink-install" C-m
tmux send-keys -t 3 "cd && rviz2 -d traversability.rviz"

# Attach to the tmux session
tmux attach-session -t $SESSION_NAME

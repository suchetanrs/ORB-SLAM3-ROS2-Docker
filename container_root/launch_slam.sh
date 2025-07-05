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

tmux send-keys -t 0 "ros2 launch orb_slam3_ros2_wrapper unirobot.launch.py"
tmux send-keys -t 1 "ros2 launch orb_slam3_map_generator map_generator.launch.py"
tmux send-keys -t 2 "python3 colcon_ws/src/orb_slam3_map_generator/scripts/stitch_pcl_client.py "
tmux send-keys -t 3 "rviz2 -d orb_slam3.rviz"

# Attach to the tmux session
tmux attach-session -t $SESSION_NAME

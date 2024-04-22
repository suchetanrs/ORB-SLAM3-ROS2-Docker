#!/bin/bash

source /opt/ros/humble/setup.bash
cd /root/trav_ws/traversability_mapping_common/build
cmake ..
make
make install
cd /root/trav_ws/traversability_mapping/build
cmake ..
make
make install
cd /home/orb/ORB_SLAM3/
./build.sh
cd ~/colcon_ws
colcon build --symlink-install
source install/setup.bash
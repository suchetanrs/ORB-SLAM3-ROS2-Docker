#!/bin/bash

source /opt/ros/humble/setup.bash
mkdir -p /root/trav_ws/src/traversability_mapping/traversability_mapping_common/build
cd /root/trav_ws/src/traversability_mapping/traversability_mapping_common/build
cmake ..
make
make install

mkdir -p /root/trav_ws/src/traversability_mapping/traversability_mapping/build
cd /root/trav_ws/src/traversability_mapping/traversability_mapping/build
cmake ..
make
make install

cd /home/orb/ORB_SLAM3/
./build.sh
cd ~/colcon_ws
colcon build --symlink-install
source install/setup.bash

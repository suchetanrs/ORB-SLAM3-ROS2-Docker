# ORB-SLAM3 ROS2 Wrapper Docker

This repository contains a dockerized comprehensive wrapper for ORB-SLAM3 on ROS 2 Humble for Ubuntu 22.04.

# Demo GIF

# Steps to use this wrapper

## 1. Clone this repository

1. ```git clone https://github.com/suchetanrs/ORB-SLAM3-ROS2-Docker```
2. ```cd ORB-SLAM3-ROS2-Docker```
3. ```git submodule update --init --recursive --remote```

## 2. Install Docker on your system

```bash
cd ORB-SLAM3-ROS2-Docker
sudo chmod +x container_root/shell_scripts/docker_install.sh
./container_root/shell_scripts/docker_install.sh
```

## 3. Build the image with ORB_SLAM3

1. Build the image: ```sudo docker build -t orb-slam3-humble:22.04 .```
2. Add ```xhost +``` to your ```.bashrc``` to support correct x11-forwarding using ```echo "xhost +" >> ~/.bashrc```
3. ```source ~/.bashrc```
4. You can see the built images on your machine by running ```sudo docker images```.

## 4. Running the container

1. ```cd ORB-SLAM3-ROS2-Docker``` (ignore if you are already in the folder)
2. ```sudo docker compose run orb_slam3_22_humble```
3. This should take you inside the container. Once you are inside, run the command ```xeyes``` and a pair of eyes should pop-up. If they do, x11 forwarding has correctly been setup on your computer.

## 5. Building the ORB-SLAM3 Wrapper

Launch the container using steps in (4).
```bash
cd /root/colcon_ws/
colcon build --symlink-install
source install/setup.bash
```

## Launching ORB-SLAM3

Launch the container using steps in (4).
If you are inside the container, run the following:

1. ```ros2 launch orb_slam3_ros2_wrapper unirobot.launch.py```
3. You can adjust the initial co-ordinates of the robot along with its namespace in the ```unirobot.launch.py``` file.

## Important notes

ORB-SLAM3 is launched from ```orb_slam3_docker_20_humble/orb_slam3_ros2_wrapper/launch/rgbd.launch.py``` which inturn is launched from ```orb_slam3_docker_20_humble/orb_slam3_ros2_wrapper/launch/unirobot.launch.py```

Currently the ```rgbd.launch.py``` launch file defaults to ```orb_slam3_ros2_wrapper/params/scout_v2_rgbd.yaml```. You can modify this with your own parameter file in case you wish to use your own camera.

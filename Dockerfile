# Image taken from https://github.com/turlucode/ros-docker-gui
FROM osrf/ros:humble-desktop-full-jammy

RUN apt-get update

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get install -y gnupg2 curl lsb-core vim wget python3-pip libpng16-16 libjpeg-turbo8 libtiff5

RUN apt-get install -y \
    # Base tools
    cmake \
    build-essential \
    git \
    unzip \
    pkg-config \
    python3-dev \
    # OpenCV dependencies
    python3-numpy \
    # Pangolin dependencies
    libgl1-mesa-dev \
    libglew-dev \
    libpython3-dev \
    libeigen3-dev \
    apt-transport-https \
    ca-certificates\
    software-properties-common

RUN apt update


# Build OpenCV
RUN apt-get install -y python3-dev python3-numpy python2-dev
RUN apt-get install -y libavcodec-dev libavformat-dev libswscale-dev
RUN apt-get install -y libgstreamer-plugins-base1.0-dev libgstreamer1.0-dev
RUN apt-get install -y libgtk-3-dev

RUN cd /tmp && git clone https://github.com/opencv/opencv.git && \
    cd opencv && \
    git checkout 4.4.0 && mkdir build && cd build && \
    cmake -D CMAKE_BUILD_TYPE=Release -D BUILD_EXAMPLES=OFF  -D BUILD_DOCS=OFF -D BUILD_PERF_TESTS=OFF -D BUILD_TESTS=OFF -D CMAKE_INSTALL_PREFIX=/usr/local .. && \
    make -j8 && make install && \
    cd / && rm -rf /tmp/opencv

# Build Pangolin
RUN cd /tmp && git clone https://github.com/stevenlovegrove/Pangolin && \
    cd Pangolin && git checkout v0.9.1 && mkdir build && cd build && \
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS=-std=c++14 -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
    make -j8 && make install && \
    cd / && rm -rf /tmp/Pangolin

# Build vscode (can be removed later for deployment)
COPY ./container_root/shell_scripts/vscode_install.sh /root/
RUN cd /root/ && sudo chmod +x * && ./vscode_install.sh && rm -rf vscode_install.sh

# Build ORB-SLAM3 with its dependencies.
RUN apt-get update && apt-get update --fix-missing
RUN apt-get update && apt-get install ros-humble-pcl-ros tmux -y
RUN apt-get install ros-humble-nav2-common x11-apps nano ros-humble-grid-map -y
COPY traversability_mapping /home/traversability/traversability_mapping
RUN . /opt/ros/humble/setup.sh && cd /home/traversability/traversability_mapping/ && ./build.sh
COPY ORB_SLAM3 /home/orb/ORB_SLAM3
RUN . /opt/ros/humble/setup.sh && cd /home/orb/ORB_SLAM3 && mkdir -p build && ./build.sh

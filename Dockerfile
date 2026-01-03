# Image taken from https://github.com/turlucode/ros-docker-gui
FROM nvidia/opengl:1.0-glvnd-devel-ubuntu18.04 AS glvnd
FROM osrf/ros:humble-desktop-full-jammy
ARG USE_CI

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

#GPU related --------------------------------------------------------
# Snippet from extension [nvidia]
RUN apt-get update && apt-get install -y --no-install-recommends \
    libglvnd0 \
    libgl1 \
    libglx0 \
    libegl1 \
    libgles2 
COPY --from=glvnd /usr/share/glvnd/egl_vendor.d/10_nvidia.json /usr/share/glvnd/egl_vendor.d/10_nvidia.json
ENV NVIDIA_VISIBLE_DEVICES ${NVIDIA_VISIBLE_DEVICES:-all}
ENV NVIDIA_DRIVER_CAPABILITIES ${NVIDIA_DRIVER_CAPABILITIES:-all}

# Basic deps for adding NVIDIA apt repo
RUN apt-get update && apt-get install -y --no-install-recommends \
    wget ca-certificates gnupg

# Add NVIDIA CUDA repo keyring (Ubuntu 22.04 repo)
RUN wget -q https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/cuda-keyring_1.1-1_all.deb \
 && dpkg -i cuda-keyring_1.1-1_all.deb

# Install CUDA Toolkit 12.2 (no driver)
RUN apt-get update && apt-get install -y --no-install-recommends \
    cuda-toolkit-12-2

# make CUDA visible on PATH
ENV PATH=/usr/local/cuda-12.2/bin:${PATH}
ENV LD_LIBRARY_PATH=/usr/local/cuda-12.2/lib64:${LD_LIBRARY_PATH}

#GPU related ends-----------------------------------------------------

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

# # Build Pangolin
# RUN cd /tmp && git clone https://github.com/stevenlovegrove/Pangolin && \
#     cd Pangolin && git checkout v0.9.1 && mkdir build && cd build && \
#     cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS=-std=c++14 -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
#     make -j8 && make install && \
#     cd / && rm -rf /tmp/Pangolin

# Build vscode (can be removed later for deployment)
COPY ./container_root/shell_scripts/vscode_install.sh /root/
RUN cd /root/ && sudo chmod +x * && ./vscode_install.sh && rm -rf vscode_install.sh

RUN apt-get update && apt-get install ros-humble-pcl-ros tmux -y
RUN apt-get install ros-humble-nav2-common x11-apps nano -y
RUN apt-get install -y gdb gdbserver ros-humble-rmw-cyclonedds-cpp ros-humble-cv-bridge ros-humble-image-transport ros-humble-image-common ros-humble-vision-opencv

COPY ORB_SLAM3 /home/orb/ORB_SLAM3
COPY orb_slam3_ros2_wrapper /root/colcon_ws/src/orb_slam3_ros2_wrapper
COPY orb_slam3_map_generator /root/colcon_ws/src/orb_slam3_map_generator
COPY slam_msgs /root/colcon_ws/src/slam_msgs

# Build ORB-SLAM3 with its dependencies.
RUN if [ "$USE_CI" = "true" ]; then \
    . /opt/ros/humble/setup.sh && cd /home/orb/ORB_SLAM3 && mkdir -p build && ./build.sh && \
    . /opt/ros/humble/setup.sh && cd /root/colcon_ws/ && colcon build --symlink-install; \
    fi

RUN rm -rf /home/orb/ORB_SLAM3 /root/colcon_ws
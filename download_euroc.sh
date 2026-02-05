pip install gdown

if [ ! -f "orb_slam3_ros2_wrapper/datasets/V1_01_easy.zip" ]; then
    gdown --fuzzy https://drive.google.com/file/d/1LFrdiMU6UBjtFfXPHzjJ4L7iDIXcdhvh/view?usp=sharing
else
    echo "orb_slam3_ros2_wrapper/datasets/V1_01_easy.zip already exists. Skipping download."
fi

if [ ! -d "orb_slam3_ros2_wrapper/datasets/V1_01_easy" ]; then
    unzip orb_slam3_ros2_wrapper/datasets/V1_01_easy.zip
else
    echo "orb_slam3_ros2_wrapper/datasets/V1_01_easy directory already exists. Skipping unzip."
fi

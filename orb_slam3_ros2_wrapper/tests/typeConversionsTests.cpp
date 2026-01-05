#include <gtest/gtest.h>
#include <random>
#include <Eigen/Dense>
#include <sophus/se3.hpp>
#include "orb_slam3_ros2_wrapper/type_conversion.hpp"
#include <cstddef>

TEST(TypeConversionsTest, SE3ConversionRoundTrip) {
    using namespace ORB_SLAM3_Wrapper::WrapperTypeConversions;
    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);
    std::uniform_real_distribution<> dis2(-2341.0, 1333.0);

    // Generate a random Affine3f matrix
    Eigen::Affine3f randomAffine = Eigen::Affine3f::Identity();
    Eigen::Matrix3f rotation;
    rotation = Eigen::AngleAxisf(dis(gen) * M_PI, Eigen::Vector3f::UnitX())
            * Eigen::AngleAxisf(dis(gen) * M_PI, Eigen::Vector3f::UnitY())
            * Eigen::AngleAxisf(dis(gen) * M_PI, Eigen::Vector3f::UnitZ());
    randomAffine.rotate(rotation);
    randomAffine.translate(Eigen::Vector3f(dis2(gen), dis2(gen), dis2(gen)));

    // Convert ROS (Affine3f) to ORB (SE3f)
    Sophus::SE3f orbSE3 = se3ROSToORB(randomAffine);

    // Convert back to ROS (Affine3f)
    Eigen::Affine3f convertedAffine = se3ORBToROS(orbSE3);

    // Compare the original and converted matrices
    ASSERT_TRUE(randomAffine.isApprox(convertedAffine, 1e-5))
        << "Original:\n" << randomAffine.matrix() << "\nConverted:\n" << convertedAffine.matrix();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
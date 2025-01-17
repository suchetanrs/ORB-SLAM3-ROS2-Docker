// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from slam_msgs:srv/GetLandmarksInView.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__STRUCT_HPP_
#define SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__slam_msgs__srv__GetLandmarksInView_Request __attribute__((deprecated))
#else
# define DEPRECATED__slam_msgs__srv__GetLandmarksInView_Request __declspec(deprecated)
#endif

namespace slam_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetLandmarksInView_Request_
{
  using Type = GetLandmarksInView_Request_<ContainerAllocator>;

  explicit GetLandmarksInView_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->max_dist_pose_observation = 6.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->max_angle_pose_observation = 0.0f;
      this->max_dist_pose_observation = 0.0f;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->max_angle_pose_observation = 0.0f;
    }
  }

  explicit GetLandmarksInView_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->max_dist_pose_observation = 6.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->max_angle_pose_observation = 0.0f;
      this->max_dist_pose_observation = 0.0f;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->max_angle_pose_observation = 0.0f;
    }
  }

  // field types and members
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _max_angle_pose_observation_type =
    float;
  _max_angle_pose_observation_type max_angle_pose_observation;
  using _max_dist_pose_observation_type =
    float;
  _max_dist_pose_observation_type max_dist_pose_observation;

  // setters for named parameter idiom
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__max_angle_pose_observation(
    const float & _arg)
  {
    this->max_angle_pose_observation = _arg;
    return *this;
  }
  Type & set__max_dist_pose_observation(
    const float & _arg)
  {
    this->max_dist_pose_observation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__slam_msgs__srv__GetLandmarksInView_Request
    std::shared_ptr<slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__slam_msgs__srv__GetLandmarksInView_Request
    std::shared_ptr<slam_msgs::srv::GetLandmarksInView_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetLandmarksInView_Request_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    if (this->max_angle_pose_observation != other.max_angle_pose_observation) {
      return false;
    }
    if (this->max_dist_pose_observation != other.max_dist_pose_observation) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetLandmarksInView_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetLandmarksInView_Request_

// alias to use template instance with default allocator
using GetLandmarksInView_Request =
  slam_msgs::srv::GetLandmarksInView_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace slam_msgs


// Include directives for member types
// Member 'map_points'
#include "slam_msgs/msg/detail/map_point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__slam_msgs__srv__GetLandmarksInView_Response __attribute__((deprecated))
#else
# define DEPRECATED__slam_msgs__srv__GetLandmarksInView_Response __declspec(deprecated)
#endif

namespace slam_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetLandmarksInView_Response_
{
  using Type = GetLandmarksInView_Response_<ContainerAllocator>;

  explicit GetLandmarksInView_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GetLandmarksInView_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _map_points_type =
    std::vector<slam_msgs::msg::MapPoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<slam_msgs::msg::MapPoint_<ContainerAllocator>>>;
  _map_points_type map_points;

  // setters for named parameter idiom
  Type & set__map_points(
    const std::vector<slam_msgs::msg::MapPoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<slam_msgs::msg::MapPoint_<ContainerAllocator>>> & _arg)
  {
    this->map_points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__slam_msgs__srv__GetLandmarksInView_Response
    std::shared_ptr<slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__slam_msgs__srv__GetLandmarksInView_Response
    std::shared_ptr<slam_msgs::srv::GetLandmarksInView_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetLandmarksInView_Response_ & other) const
  {
    if (this->map_points != other.map_points) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetLandmarksInView_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetLandmarksInView_Response_

// alias to use template instance with default allocator
using GetLandmarksInView_Response =
  slam_msgs::srv::GetLandmarksInView_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace slam_msgs

namespace slam_msgs
{

namespace srv
{

struct GetLandmarksInView
{
  using Request = slam_msgs::srv::GetLandmarksInView_Request;
  using Response = slam_msgs::srv::GetLandmarksInView_Response;
};

}  // namespace srv

}  // namespace slam_msgs

#endif  // SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__STRUCT_HPP_

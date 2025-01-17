// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from slam_msgs:msg/MapPoint.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__MAP_POINT__STRUCT_HPP_
#define SLAM_MSGS__MSG__DETAIL__MAP_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'observing_keyframes'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__slam_msgs__msg__MapPoint __attribute__((deprecated))
#else
# define DEPRECATED__slam_msgs__msg__MapPoint __declspec(deprecated)
#endif

namespace slam_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MapPoint_
{
  using Type = MapPoint_<ContainerAllocator>;

  explicit MapPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    (void)_init;
  }

  explicit MapPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _observing_keyframes_type =
    std::vector<geometry_msgs::msg::Pose_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Pose_<ContainerAllocator>>>;
  _observing_keyframes_type observing_keyframes;

  // setters for named parameter idiom
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__observing_keyframes(
    const std::vector<geometry_msgs::msg::Pose_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Pose_<ContainerAllocator>>> & _arg)
  {
    this->observing_keyframes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    slam_msgs::msg::MapPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const slam_msgs::msg::MapPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<slam_msgs::msg::MapPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<slam_msgs::msg::MapPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      slam_msgs::msg::MapPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<slam_msgs::msg::MapPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      slam_msgs::msg::MapPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<slam_msgs::msg::MapPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<slam_msgs::msg::MapPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<slam_msgs::msg::MapPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__slam_msgs__msg__MapPoint
    std::shared_ptr<slam_msgs::msg::MapPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__slam_msgs__msg__MapPoint
    std::shared_ptr<slam_msgs::msg::MapPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MapPoint_ & other) const
  {
    if (this->position != other.position) {
      return false;
    }
    if (this->observing_keyframes != other.observing_keyframes) {
      return false;
    }
    return true;
  }
  bool operator!=(const MapPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MapPoint_

// alias to use template instance with default allocator
using MapPoint =
  slam_msgs::msg::MapPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace slam_msgs

#endif  // SLAM_MSGS__MSG__DETAIL__MAP_POINT__STRUCT_HPP_

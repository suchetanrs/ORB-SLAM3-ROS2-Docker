// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from slam_msgs:msg/MapGraph.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__STRUCT_HPP_
#define SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'poses'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__slam_msgs__msg__MapGraph __attribute__((deprecated))
#else
# define DEPRECATED__slam_msgs__msg__MapGraph __declspec(deprecated)
#endif

namespace slam_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MapGraph_
{
  using Type = MapGraph_<ContainerAllocator>;

  explicit MapGraph_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit MapGraph_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _poses_id_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _poses_id_type poses_id;
  using _poses_type =
    std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>>;
  _poses_type poses;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__poses_id(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->poses_id = _arg;
    return *this;
  }
  Type & set__poses(
    const std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>> & _arg)
  {
    this->poses = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    slam_msgs::msg::MapGraph_<ContainerAllocator> *;
  using ConstRawPtr =
    const slam_msgs::msg::MapGraph_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<slam_msgs::msg::MapGraph_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<slam_msgs::msg::MapGraph_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      slam_msgs::msg::MapGraph_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<slam_msgs::msg::MapGraph_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      slam_msgs::msg::MapGraph_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<slam_msgs::msg::MapGraph_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<slam_msgs::msg::MapGraph_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<slam_msgs::msg::MapGraph_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__slam_msgs__msg__MapGraph
    std::shared_ptr<slam_msgs::msg::MapGraph_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__slam_msgs__msg__MapGraph
    std::shared_ptr<slam_msgs::msg::MapGraph_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MapGraph_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->poses_id != other.poses_id) {
      return false;
    }
    if (this->poses != other.poses) {
      return false;
    }
    return true;
  }
  bool operator!=(const MapGraph_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MapGraph_

// alias to use template instance with default allocator
using MapGraph =
  slam_msgs::msg::MapGraph_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace slam_msgs

#endif  // SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__STRUCT_HPP_

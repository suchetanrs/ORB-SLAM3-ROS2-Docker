// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from slam_msgs:msg/KeyFrame.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__KEY_FRAME__STRUCT_HPP_
#define SLAM_MSGS__MSG__DETAIL__KEY_FRAME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'word_pts'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__slam_msgs__msg__KeyFrame __attribute__((deprecated))
#else
# define DEPRECATED__slam_msgs__msg__KeyFrame __declspec(deprecated)
#endif

namespace slam_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct KeyFrame_
{
  using Type = KeyFrame_<ContainerAllocator>;

  explicit KeyFrame_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
    }
  }

  explicit KeyFrame_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _word_pts_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _word_pts_type word_pts;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__word_pts(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->word_pts = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    slam_msgs::msg::KeyFrame_<ContainerAllocator> *;
  using ConstRawPtr =
    const slam_msgs::msg::KeyFrame_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<slam_msgs::msg::KeyFrame_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<slam_msgs::msg::KeyFrame_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      slam_msgs::msg::KeyFrame_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<slam_msgs::msg::KeyFrame_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      slam_msgs::msg::KeyFrame_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<slam_msgs::msg::KeyFrame_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<slam_msgs::msg::KeyFrame_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<slam_msgs::msg::KeyFrame_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__slam_msgs__msg__KeyFrame
    std::shared_ptr<slam_msgs::msg::KeyFrame_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__slam_msgs__msg__KeyFrame
    std::shared_ptr<slam_msgs::msg::KeyFrame_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KeyFrame_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->word_pts != other.word_pts) {
      return false;
    }
    return true;
  }
  bool operator!=(const KeyFrame_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KeyFrame_

// alias to use template instance with default allocator
using KeyFrame =
  slam_msgs::msg::KeyFrame_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace slam_msgs

#endif  // SLAM_MSGS__MSG__DETAIL__KEY_FRAME__STRUCT_HPP_

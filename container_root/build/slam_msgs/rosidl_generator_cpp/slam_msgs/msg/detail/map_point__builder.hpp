// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from slam_msgs:msg/MapPoint.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__MAP_POINT__BUILDER_HPP_
#define SLAM_MSGS__MSG__DETAIL__MAP_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "slam_msgs/msg/detail/map_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace slam_msgs
{

namespace msg
{

namespace builder
{

class Init_MapPoint_observing_keyframes
{
public:
  explicit Init_MapPoint_observing_keyframes(::slam_msgs::msg::MapPoint & msg)
  : msg_(msg)
  {}
  ::slam_msgs::msg::MapPoint observing_keyframes(::slam_msgs::msg::MapPoint::_observing_keyframes_type arg)
  {
    msg_.observing_keyframes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::slam_msgs::msg::MapPoint msg_;
};

class Init_MapPoint_position
{
public:
  Init_MapPoint_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapPoint_observing_keyframes position(::slam_msgs::msg::MapPoint::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_MapPoint_observing_keyframes(msg_);
  }

private:
  ::slam_msgs::msg::MapPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::slam_msgs::msg::MapPoint>()
{
  return slam_msgs::msg::builder::Init_MapPoint_position();
}

}  // namespace slam_msgs

#endif  // SLAM_MSGS__MSG__DETAIL__MAP_POINT__BUILDER_HPP_

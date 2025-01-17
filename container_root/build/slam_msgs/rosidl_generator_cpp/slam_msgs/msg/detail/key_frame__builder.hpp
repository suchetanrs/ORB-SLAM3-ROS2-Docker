// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from slam_msgs:msg/KeyFrame.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__KEY_FRAME__BUILDER_HPP_
#define SLAM_MSGS__MSG__DETAIL__KEY_FRAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "slam_msgs/msg/detail/key_frame__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace slam_msgs
{

namespace msg
{

namespace builder
{

class Init_KeyFrame_word_pts
{
public:
  explicit Init_KeyFrame_word_pts(::slam_msgs::msg::KeyFrame & msg)
  : msg_(msg)
  {}
  ::slam_msgs::msg::KeyFrame word_pts(::slam_msgs::msg::KeyFrame::_word_pts_type arg)
  {
    msg_.word_pts = std::move(arg);
    return std::move(msg_);
  }

private:
  ::slam_msgs::msg::KeyFrame msg_;
};

class Init_KeyFrame_id
{
public:
  Init_KeyFrame_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_KeyFrame_word_pts id(::slam_msgs::msg::KeyFrame::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_KeyFrame_word_pts(msg_);
  }

private:
  ::slam_msgs::msg::KeyFrame msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::slam_msgs::msg::KeyFrame>()
{
  return slam_msgs::msg::builder::Init_KeyFrame_id();
}

}  // namespace slam_msgs

#endif  // SLAM_MSGS__MSG__DETAIL__KEY_FRAME__BUILDER_HPP_

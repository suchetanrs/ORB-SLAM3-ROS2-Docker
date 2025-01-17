// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from slam_msgs:msg/MapGraph.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__BUILDER_HPP_
#define SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "slam_msgs/msg/detail/map_graph__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace slam_msgs
{

namespace msg
{

namespace builder
{

class Init_MapGraph_poses
{
public:
  explicit Init_MapGraph_poses(::slam_msgs::msg::MapGraph & msg)
  : msg_(msg)
  {}
  ::slam_msgs::msg::MapGraph poses(::slam_msgs::msg::MapGraph::_poses_type arg)
  {
    msg_.poses = std::move(arg);
    return std::move(msg_);
  }

private:
  ::slam_msgs::msg::MapGraph msg_;
};

class Init_MapGraph_poses_id
{
public:
  explicit Init_MapGraph_poses_id(::slam_msgs::msg::MapGraph & msg)
  : msg_(msg)
  {}
  Init_MapGraph_poses poses_id(::slam_msgs::msg::MapGraph::_poses_id_type arg)
  {
    msg_.poses_id = std::move(arg);
    return Init_MapGraph_poses(msg_);
  }

private:
  ::slam_msgs::msg::MapGraph msg_;
};

class Init_MapGraph_header
{
public:
  Init_MapGraph_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapGraph_poses_id header(::slam_msgs::msg::MapGraph::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MapGraph_poses_id(msg_);
  }

private:
  ::slam_msgs::msg::MapGraph msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::slam_msgs::msg::MapGraph>()
{
  return slam_msgs::msg::builder::Init_MapGraph_header();
}

}  // namespace slam_msgs

#endif  // SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__BUILDER_HPP_

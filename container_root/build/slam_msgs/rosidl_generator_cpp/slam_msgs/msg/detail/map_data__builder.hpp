// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from slam_msgs:msg/MapData.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__MAP_DATA__BUILDER_HPP_
#define SLAM_MSGS__MSG__DETAIL__MAP_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "slam_msgs/msg/detail/map_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace slam_msgs
{

namespace msg
{

namespace builder
{

class Init_MapData_nodes
{
public:
  explicit Init_MapData_nodes(::slam_msgs::msg::MapData & msg)
  : msg_(msg)
  {}
  ::slam_msgs::msg::MapData nodes(::slam_msgs::msg::MapData::_nodes_type arg)
  {
    msg_.nodes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::slam_msgs::msg::MapData msg_;
};

class Init_MapData_graph
{
public:
  explicit Init_MapData_graph(::slam_msgs::msg::MapData & msg)
  : msg_(msg)
  {}
  Init_MapData_nodes graph(::slam_msgs::msg::MapData::_graph_type arg)
  {
    msg_.graph = std::move(arg);
    return Init_MapData_nodes(msg_);
  }

private:
  ::slam_msgs::msg::MapData msg_;
};

class Init_MapData_header
{
public:
  Init_MapData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapData_graph header(::slam_msgs::msg::MapData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MapData_graph(msg_);
  }

private:
  ::slam_msgs::msg::MapData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::slam_msgs::msg::MapData>()
{
  return slam_msgs::msg::builder::Init_MapData_header();
}

}  // namespace slam_msgs

#endif  // SLAM_MSGS__MSG__DETAIL__MAP_DATA__BUILDER_HPP_

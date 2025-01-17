// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from slam_msgs:msg/MapGraph.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__TRAITS_HPP_
#define SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "slam_msgs/msg/detail/map_graph__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'poses'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace slam_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MapGraph & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: poses_id
  {
    if (msg.poses_id.size() == 0) {
      out << "poses_id: []";
    } else {
      out << "poses_id: [";
      size_t pending_items = msg.poses_id.size();
      for (auto item : msg.poses_id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: poses
  {
    if (msg.poses.size() == 0) {
      out << "poses: []";
    } else {
      out << "poses: [";
      size_t pending_items = msg.poses.size();
      for (auto item : msg.poses) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MapGraph & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: poses_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.poses_id.size() == 0) {
      out << "poses_id: []\n";
    } else {
      out << "poses_id:\n";
      for (auto item : msg.poses_id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: poses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.poses.size() == 0) {
      out << "poses: []\n";
    } else {
      out << "poses:\n";
      for (auto item : msg.poses) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MapGraph & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace slam_msgs

namespace rosidl_generator_traits
{

[[deprecated("use slam_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const slam_msgs::msg::MapGraph & msg,
  std::ostream & out, size_t indentation = 0)
{
  slam_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use slam_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const slam_msgs::msg::MapGraph & msg)
{
  return slam_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<slam_msgs::msg::MapGraph>()
{
  return "slam_msgs::msg::MapGraph";
}

template<>
inline const char * name<slam_msgs::msg::MapGraph>()
{
  return "slam_msgs/msg/MapGraph";
}

template<>
struct has_fixed_size<slam_msgs::msg::MapGraph>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<slam_msgs::msg::MapGraph>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<slam_msgs::msg::MapGraph>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__TRAITS_HPP_

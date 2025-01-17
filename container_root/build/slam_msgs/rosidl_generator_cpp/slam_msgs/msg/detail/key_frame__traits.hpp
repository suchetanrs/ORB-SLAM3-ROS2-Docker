// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from slam_msgs:msg/KeyFrame.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__KEY_FRAME__TRAITS_HPP_
#define SLAM_MSGS__MSG__DETAIL__KEY_FRAME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "slam_msgs/msg/detail/key_frame__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'word_pts'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace slam_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const KeyFrame & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: word_pts
  {
    if (msg.word_pts.size() == 0) {
      out << "word_pts: []";
    } else {
      out << "word_pts: [";
      size_t pending_items = msg.word_pts.size();
      for (auto item : msg.word_pts) {
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
  const KeyFrame & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: word_pts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.word_pts.size() == 0) {
      out << "word_pts: []\n";
    } else {
      out << "word_pts:\n";
      for (auto item : msg.word_pts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const KeyFrame & msg, bool use_flow_style = false)
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
  const slam_msgs::msg::KeyFrame & msg,
  std::ostream & out, size_t indentation = 0)
{
  slam_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use slam_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const slam_msgs::msg::KeyFrame & msg)
{
  return slam_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<slam_msgs::msg::KeyFrame>()
{
  return "slam_msgs::msg::KeyFrame";
}

template<>
inline const char * name<slam_msgs::msg::KeyFrame>()
{
  return "slam_msgs/msg/KeyFrame";
}

template<>
struct has_fixed_size<slam_msgs::msg::KeyFrame>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<slam_msgs::msg::KeyFrame>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<slam_msgs::msg::KeyFrame>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SLAM_MSGS__MSG__DETAIL__KEY_FRAME__TRAITS_HPP_

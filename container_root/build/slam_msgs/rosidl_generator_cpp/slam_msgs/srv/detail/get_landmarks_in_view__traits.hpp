// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from slam_msgs:srv/GetLandmarksInView.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__TRAITS_HPP_
#define SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "slam_msgs/srv/detail/get_landmarks_in_view__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace slam_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetLandmarksInView_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: max_angle_pose_observation
  {
    out << "max_angle_pose_observation: ";
    rosidl_generator_traits::value_to_yaml(msg.max_angle_pose_observation, out);
    out << ", ";
  }

  // member: max_dist_pose_observation
  {
    out << "max_dist_pose_observation: ";
    rosidl_generator_traits::value_to_yaml(msg.max_dist_pose_observation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetLandmarksInView_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: max_angle_pose_observation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_angle_pose_observation: ";
    rosidl_generator_traits::value_to_yaml(msg.max_angle_pose_observation, out);
    out << "\n";
  }

  // member: max_dist_pose_observation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_dist_pose_observation: ";
    rosidl_generator_traits::value_to_yaml(msg.max_dist_pose_observation, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetLandmarksInView_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace slam_msgs

namespace rosidl_generator_traits
{

[[deprecated("use slam_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const slam_msgs::srv::GetLandmarksInView_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  slam_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use slam_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const slam_msgs::srv::GetLandmarksInView_Request & msg)
{
  return slam_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<slam_msgs::srv::GetLandmarksInView_Request>()
{
  return "slam_msgs::srv::GetLandmarksInView_Request";
}

template<>
inline const char * name<slam_msgs::srv::GetLandmarksInView_Request>()
{
  return "slam_msgs/srv/GetLandmarksInView_Request";
}

template<>
struct has_fixed_size<slam_msgs::srv::GetLandmarksInView_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<slam_msgs::srv::GetLandmarksInView_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<slam_msgs::srv::GetLandmarksInView_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'map_points'
#include "slam_msgs/msg/detail/map_point__traits.hpp"

namespace slam_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetLandmarksInView_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: map_points
  {
    if (msg.map_points.size() == 0) {
      out << "map_points: []";
    } else {
      out << "map_points: [";
      size_t pending_items = msg.map_points.size();
      for (auto item : msg.map_points) {
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
  const GetLandmarksInView_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: map_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.map_points.size() == 0) {
      out << "map_points: []\n";
    } else {
      out << "map_points:\n";
      for (auto item : msg.map_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetLandmarksInView_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace slam_msgs

namespace rosidl_generator_traits
{

[[deprecated("use slam_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const slam_msgs::srv::GetLandmarksInView_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  slam_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use slam_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const slam_msgs::srv::GetLandmarksInView_Response & msg)
{
  return slam_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<slam_msgs::srv::GetLandmarksInView_Response>()
{
  return "slam_msgs::srv::GetLandmarksInView_Response";
}

template<>
inline const char * name<slam_msgs::srv::GetLandmarksInView_Response>()
{
  return "slam_msgs/srv/GetLandmarksInView_Response";
}

template<>
struct has_fixed_size<slam_msgs::srv::GetLandmarksInView_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<slam_msgs::srv::GetLandmarksInView_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<slam_msgs::srv::GetLandmarksInView_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<slam_msgs::srv::GetLandmarksInView>()
{
  return "slam_msgs::srv::GetLandmarksInView";
}

template<>
inline const char * name<slam_msgs::srv::GetLandmarksInView>()
{
  return "slam_msgs/srv/GetLandmarksInView";
}

template<>
struct has_fixed_size<slam_msgs::srv::GetLandmarksInView>
  : std::integral_constant<
    bool,
    has_fixed_size<slam_msgs::srv::GetLandmarksInView_Request>::value &&
    has_fixed_size<slam_msgs::srv::GetLandmarksInView_Response>::value
  >
{
};

template<>
struct has_bounded_size<slam_msgs::srv::GetLandmarksInView>
  : std::integral_constant<
    bool,
    has_bounded_size<slam_msgs::srv::GetLandmarksInView_Request>::value &&
    has_bounded_size<slam_msgs::srv::GetLandmarksInView_Response>::value
  >
{
};

template<>
struct is_service<slam_msgs::srv::GetLandmarksInView>
  : std::true_type
{
};

template<>
struct is_service_request<slam_msgs::srv::GetLandmarksInView_Request>
  : std::true_type
{
};

template<>
struct is_service_response<slam_msgs::srv::GetLandmarksInView_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from slam_msgs:srv/GetMap.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__SRV__DETAIL__GET_MAP__TRAITS_HPP_
#define SLAM_MSGS__SRV__DETAIL__GET_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "slam_msgs/srv/detail/get_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace slam_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetMap_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: tracked_points
  {
    out << "tracked_points: ";
    rosidl_generator_traits::value_to_yaml(msg.tracked_points, out);
    out << ", ";
  }

  // member: kf_id_for_landmarks
  {
    if (msg.kf_id_for_landmarks.size() == 0) {
      out << "kf_id_for_landmarks: []";
    } else {
      out << "kf_id_for_landmarks: [";
      size_t pending_items = msg.kf_id_for_landmarks.size();
      for (auto item : msg.kf_id_for_landmarks) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const GetMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tracked_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tracked_points: ";
    rosidl_generator_traits::value_to_yaml(msg.tracked_points, out);
    out << "\n";
  }

  // member: kf_id_for_landmarks
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.kf_id_for_landmarks.size() == 0) {
      out << "kf_id_for_landmarks: []\n";
    } else {
      out << "kf_id_for_landmarks:\n";
      for (auto item : msg.kf_id_for_landmarks) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetMap_Request & msg, bool use_flow_style = false)
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
  const slam_msgs::srv::GetMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  slam_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use slam_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const slam_msgs::srv::GetMap_Request & msg)
{
  return slam_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<slam_msgs::srv::GetMap_Request>()
{
  return "slam_msgs::srv::GetMap_Request";
}

template<>
inline const char * name<slam_msgs::srv::GetMap_Request>()
{
  return "slam_msgs/srv/GetMap_Request";
}

template<>
struct has_fixed_size<slam_msgs::srv::GetMap_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<slam_msgs::srv::GetMap_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<slam_msgs::srv::GetMap_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'data'
#include "slam_msgs/msg/detail/map_data__traits.hpp"

namespace slam_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetMap_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    out << "data: ";
    to_flow_style_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data:\n";
    to_block_style_yaml(msg.data, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetMap_Response & msg, bool use_flow_style = false)
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
  const slam_msgs::srv::GetMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  slam_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use slam_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const slam_msgs::srv::GetMap_Response & msg)
{
  return slam_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<slam_msgs::srv::GetMap_Response>()
{
  return "slam_msgs::srv::GetMap_Response";
}

template<>
inline const char * name<slam_msgs::srv::GetMap_Response>()
{
  return "slam_msgs/srv/GetMap_Response";
}

template<>
struct has_fixed_size<slam_msgs::srv::GetMap_Response>
  : std::integral_constant<bool, has_fixed_size<slam_msgs::msg::MapData>::value> {};

template<>
struct has_bounded_size<slam_msgs::srv::GetMap_Response>
  : std::integral_constant<bool, has_bounded_size<slam_msgs::msg::MapData>::value> {};

template<>
struct is_message<slam_msgs::srv::GetMap_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<slam_msgs::srv::GetMap>()
{
  return "slam_msgs::srv::GetMap";
}

template<>
inline const char * name<slam_msgs::srv::GetMap>()
{
  return "slam_msgs/srv/GetMap";
}

template<>
struct has_fixed_size<slam_msgs::srv::GetMap>
  : std::integral_constant<
    bool,
    has_fixed_size<slam_msgs::srv::GetMap_Request>::value &&
    has_fixed_size<slam_msgs::srv::GetMap_Response>::value
  >
{
};

template<>
struct has_bounded_size<slam_msgs::srv::GetMap>
  : std::integral_constant<
    bool,
    has_bounded_size<slam_msgs::srv::GetMap_Request>::value &&
    has_bounded_size<slam_msgs::srv::GetMap_Response>::value
  >
{
};

template<>
struct is_service<slam_msgs::srv::GetMap>
  : std::true_type
{
};

template<>
struct is_service_request<slam_msgs::srv::GetMap_Request>
  : std::true_type
{
};

template<>
struct is_service_response<slam_msgs::srv::GetMap_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SLAM_MSGS__SRV__DETAIL__GET_MAP__TRAITS_HPP_

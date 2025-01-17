// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from slam_msgs:srv/GetMap.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__SRV__DETAIL__GET_MAP__BUILDER_HPP_
#define SLAM_MSGS__SRV__DETAIL__GET_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "slam_msgs/srv/detail/get_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace slam_msgs
{

namespace srv
{

namespace builder
{

class Init_GetMap_Request_kf_id_for_landmarks
{
public:
  explicit Init_GetMap_Request_kf_id_for_landmarks(::slam_msgs::srv::GetMap_Request & msg)
  : msg_(msg)
  {}
  ::slam_msgs::srv::GetMap_Request kf_id_for_landmarks(::slam_msgs::srv::GetMap_Request::_kf_id_for_landmarks_type arg)
  {
    msg_.kf_id_for_landmarks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::slam_msgs::srv::GetMap_Request msg_;
};

class Init_GetMap_Request_tracked_points
{
public:
  Init_GetMap_Request_tracked_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetMap_Request_kf_id_for_landmarks tracked_points(::slam_msgs::srv::GetMap_Request::_tracked_points_type arg)
  {
    msg_.tracked_points = std::move(arg);
    return Init_GetMap_Request_kf_id_for_landmarks(msg_);
  }

private:
  ::slam_msgs::srv::GetMap_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::slam_msgs::srv::GetMap_Request>()
{
  return slam_msgs::srv::builder::Init_GetMap_Request_tracked_points();
}

}  // namespace slam_msgs


namespace slam_msgs
{

namespace srv
{

namespace builder
{

class Init_GetMap_Response_data
{
public:
  Init_GetMap_Response_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::slam_msgs::srv::GetMap_Response data(::slam_msgs::srv::GetMap_Response::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::slam_msgs::srv::GetMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::slam_msgs::srv::GetMap_Response>()
{
  return slam_msgs::srv::builder::Init_GetMap_Response_data();
}

}  // namespace slam_msgs

#endif  // SLAM_MSGS__SRV__DETAIL__GET_MAP__BUILDER_HPP_

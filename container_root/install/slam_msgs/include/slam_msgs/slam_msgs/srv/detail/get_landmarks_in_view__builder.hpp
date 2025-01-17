// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from slam_msgs:srv/GetLandmarksInView.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__BUILDER_HPP_
#define SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "slam_msgs/srv/detail/get_landmarks_in_view__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace slam_msgs
{

namespace srv
{

namespace builder
{

class Init_GetLandmarksInView_Request_max_dist_pose_observation
{
public:
  explicit Init_GetLandmarksInView_Request_max_dist_pose_observation(::slam_msgs::srv::GetLandmarksInView_Request & msg)
  : msg_(msg)
  {}
  ::slam_msgs::srv::GetLandmarksInView_Request max_dist_pose_observation(::slam_msgs::srv::GetLandmarksInView_Request::_max_dist_pose_observation_type arg)
  {
    msg_.max_dist_pose_observation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::slam_msgs::srv::GetLandmarksInView_Request msg_;
};

class Init_GetLandmarksInView_Request_max_angle_pose_observation
{
public:
  explicit Init_GetLandmarksInView_Request_max_angle_pose_observation(::slam_msgs::srv::GetLandmarksInView_Request & msg)
  : msg_(msg)
  {}
  Init_GetLandmarksInView_Request_max_dist_pose_observation max_angle_pose_observation(::slam_msgs::srv::GetLandmarksInView_Request::_max_angle_pose_observation_type arg)
  {
    msg_.max_angle_pose_observation = std::move(arg);
    return Init_GetLandmarksInView_Request_max_dist_pose_observation(msg_);
  }

private:
  ::slam_msgs::srv::GetLandmarksInView_Request msg_;
};

class Init_GetLandmarksInView_Request_pose
{
public:
  Init_GetLandmarksInView_Request_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetLandmarksInView_Request_max_angle_pose_observation pose(::slam_msgs::srv::GetLandmarksInView_Request::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_GetLandmarksInView_Request_max_angle_pose_observation(msg_);
  }

private:
  ::slam_msgs::srv::GetLandmarksInView_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::slam_msgs::srv::GetLandmarksInView_Request>()
{
  return slam_msgs::srv::builder::Init_GetLandmarksInView_Request_pose();
}

}  // namespace slam_msgs


namespace slam_msgs
{

namespace srv
{

namespace builder
{

class Init_GetLandmarksInView_Response_map_points
{
public:
  Init_GetLandmarksInView_Response_map_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::slam_msgs::srv::GetLandmarksInView_Response map_points(::slam_msgs::srv::GetLandmarksInView_Response::_map_points_type arg)
  {
    msg_.map_points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::slam_msgs::srv::GetLandmarksInView_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::slam_msgs::srv::GetLandmarksInView_Response>()
{
  return slam_msgs::srv::builder::Init_GetLandmarksInView_Response_map_points();
}

}  // namespace slam_msgs

#endif  // SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__BUILDER_HPP_

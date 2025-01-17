// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from slam_msgs:srv/GetLandmarksInView.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__STRUCT_H_
#define SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/GetLandmarksInView in the package slam_msgs.
typedef struct slam_msgs__srv__GetLandmarksInView_Request
{
  geometry_msgs__msg__Pose pose;
  /// this is the max angle between the given pose
  /// and the previous keyframe pose from which
  /// the landmark was observed. (in rad)
  /// max(Δyaw, Δroll, Δpitch) is considered as the angle of interest.
  /// setting it to > pi will disregard the angle of observation.
  float max_angle_pose_observation;
  /// this is the max distance between the given pose
  /// and the previous keyframe pose from which
  /// the landmark was observed. (in m)
  /// if you wish to get landmarks until atleast x m from the pose, this value must be x.
  float max_dist_pose_observation;
} slam_msgs__srv__GetLandmarksInView_Request;

// Struct for a sequence of slam_msgs__srv__GetLandmarksInView_Request.
typedef struct slam_msgs__srv__GetLandmarksInView_Request__Sequence
{
  slam_msgs__srv__GetLandmarksInView_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} slam_msgs__srv__GetLandmarksInView_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'map_points'
#include "slam_msgs/msg/detail/map_point__struct.h"

/// Struct defined in srv/GetLandmarksInView in the package slam_msgs.
typedef struct slam_msgs__srv__GetLandmarksInView_Response
{
  slam_msgs__msg__MapPoint__Sequence map_points;
} slam_msgs__srv__GetLandmarksInView_Response;

// Struct for a sequence of slam_msgs__srv__GetLandmarksInView_Response.
typedef struct slam_msgs__srv__GetLandmarksInView_Response__Sequence
{
  slam_msgs__srv__GetLandmarksInView_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} slam_msgs__srv__GetLandmarksInView_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SLAM_MSGS__SRV__DETAIL__GET_LANDMARKS_IN_VIEW__STRUCT_H_

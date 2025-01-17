// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from slam_msgs:msg/KeyFrame.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__KEY_FRAME__STRUCT_H_
#define SLAM_MSGS__MSG__DETAIL__KEY_FRAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'word_pts'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/KeyFrame in the package slam_msgs.
typedef struct slam_msgs__msg__KeyFrame
{
  int32_t id;
  geometry_msgs__msg__Point__Sequence word_pts;
} slam_msgs__msg__KeyFrame;

// Struct for a sequence of slam_msgs__msg__KeyFrame.
typedef struct slam_msgs__msg__KeyFrame__Sequence
{
  slam_msgs__msg__KeyFrame * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} slam_msgs__msg__KeyFrame__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SLAM_MSGS__MSG__DETAIL__KEY_FRAME__STRUCT_H_

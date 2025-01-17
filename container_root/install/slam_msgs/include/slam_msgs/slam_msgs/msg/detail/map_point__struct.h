// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from slam_msgs:msg/MapPoint.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__MAP_POINT__STRUCT_H_
#define SLAM_MSGS__MSG__DETAIL__MAP_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'observing_keyframes'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/MapPoint in the package slam_msgs.
typedef struct slam_msgs__msg__MapPoint
{
  geometry_msgs__msg__Point position;
  geometry_msgs__msg__Pose__Sequence observing_keyframes;
} slam_msgs__msg__MapPoint;

// Struct for a sequence of slam_msgs__msg__MapPoint.
typedef struct slam_msgs__msg__MapPoint__Sequence
{
  slam_msgs__msg__MapPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} slam_msgs__msg__MapPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SLAM_MSGS__MSG__DETAIL__MAP_POINT__STRUCT_H_

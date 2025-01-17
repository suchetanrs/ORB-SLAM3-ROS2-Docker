// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from slam_msgs:msg/MapGraph.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__STRUCT_H_
#define SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'poses_id'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'poses'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in msg/MapGraph in the package slam_msgs.
typedef struct slam_msgs__msg__MapGraph
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__int32__Sequence poses_id;
  geometry_msgs__msg__PoseStamped__Sequence poses;
} slam_msgs__msg__MapGraph;

// Struct for a sequence of slam_msgs__msg__MapGraph.
typedef struct slam_msgs__msg__MapGraph__Sequence
{
  slam_msgs__msg__MapGraph * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} slam_msgs__msg__MapGraph__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SLAM_MSGS__MSG__DETAIL__MAP_GRAPH__STRUCT_H_

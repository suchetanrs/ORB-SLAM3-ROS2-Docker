// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from slam_msgs:msg/MapData.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__MSG__DETAIL__MAP_DATA__STRUCT_H_
#define SLAM_MSGS__MSG__DETAIL__MAP_DATA__STRUCT_H_

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
// Member 'graph'
#include "slam_msgs/msg/detail/map_graph__struct.h"
// Member 'nodes'
#include "slam_msgs/msg/detail/key_frame__struct.h"

/// Struct defined in msg/MapData in the package slam_msgs.
typedef struct slam_msgs__msg__MapData
{
  std_msgs__msg__Header header;
  /// optimized graph
  slam_msgs__msg__MapGraph graph;
  /// graph data
  slam_msgs__msg__KeyFrame__Sequence nodes;
} slam_msgs__msg__MapData;

// Struct for a sequence of slam_msgs__msg__MapData.
typedef struct slam_msgs__msg__MapData__Sequence
{
  slam_msgs__msg__MapData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} slam_msgs__msg__MapData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SLAM_MSGS__MSG__DETAIL__MAP_DATA__STRUCT_H_

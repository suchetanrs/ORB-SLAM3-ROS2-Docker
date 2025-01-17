// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from slam_msgs:srv/GetMap.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__SRV__DETAIL__GET_MAP__STRUCT_H_
#define SLAM_MSGS__SRV__DETAIL__GET_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'kf_id_for_landmarks'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/GetMap in the package slam_msgs.
typedef struct slam_msgs__srv__GetMap_Request
{
  bool tracked_points;
  rosidl_runtime_c__int32__Sequence kf_id_for_landmarks;
} slam_msgs__srv__GetMap_Request;

// Struct for a sequence of slam_msgs__srv__GetMap_Request.
typedef struct slam_msgs__srv__GetMap_Request__Sequence
{
  slam_msgs__srv__GetMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} slam_msgs__srv__GetMap_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "slam_msgs/msg/detail/map_data__struct.h"

/// Struct defined in srv/GetMap in the package slam_msgs.
typedef struct slam_msgs__srv__GetMap_Response
{
  slam_msgs__msg__MapData data;
} slam_msgs__srv__GetMap_Response;

// Struct for a sequence of slam_msgs__srv__GetMap_Response.
typedef struct slam_msgs__srv__GetMap_Response__Sequence
{
  slam_msgs__srv__GetMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} slam_msgs__srv__GetMap_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SLAM_MSGS__SRV__DETAIL__GET_MAP__STRUCT_H_

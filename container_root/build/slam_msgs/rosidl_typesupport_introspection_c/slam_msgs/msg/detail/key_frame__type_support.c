// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from slam_msgs:msg/KeyFrame.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "slam_msgs/msg/detail/key_frame__rosidl_typesupport_introspection_c.h"
#include "slam_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "slam_msgs/msg/detail/key_frame__functions.h"
#include "slam_msgs/msg/detail/key_frame__struct.h"


// Include directives for member types
// Member `word_pts`
#include "geometry_msgs/msg/point.h"
// Member `word_pts`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  slam_msgs__msg__KeyFrame__init(message_memory);
}

void slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_fini_function(void * message_memory)
{
  slam_msgs__msg__KeyFrame__fini(message_memory);
}

size_t slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__size_function__KeyFrame__word_pts(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__get_const_function__KeyFrame__word_pts(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__get_function__KeyFrame__word_pts(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__fetch_function__KeyFrame__word_pts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__get_const_function__KeyFrame__word_pts(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__assign_function__KeyFrame__word_pts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__get_function__KeyFrame__word_pts(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__resize_function__KeyFrame__word_pts(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_message_member_array[2] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs__msg__KeyFrame, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "word_pts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs__msg__KeyFrame, word_pts),  // bytes offset in struct
    NULL,  // default value
    slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__size_function__KeyFrame__word_pts,  // size() function pointer
    slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__get_const_function__KeyFrame__word_pts,  // get_const(index) function pointer
    slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__get_function__KeyFrame__word_pts,  // get(index) function pointer
    slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__fetch_function__KeyFrame__word_pts,  // fetch(index, &value) function pointer
    slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__assign_function__KeyFrame__word_pts,  // assign(index, value) function pointer
    slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__resize_function__KeyFrame__word_pts  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_message_members = {
  "slam_msgs__msg",  // message namespace
  "KeyFrame",  // message name
  2,  // number of fields
  sizeof(slam_msgs__msg__KeyFrame),
  slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_message_member_array,  // message members
  slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_init_function,  // function to initialize message memory (memory has to be allocated)
  slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_message_type_support_handle = {
  0,
  &slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_slam_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slam_msgs, msg, KeyFrame)() {
  slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_message_type_support_handle.typesupport_identifier) {
    slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &slam_msgs__msg__KeyFrame__rosidl_typesupport_introspection_c__KeyFrame_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

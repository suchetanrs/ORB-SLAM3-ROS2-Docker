// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from slam_msgs:srv/GetLandmarksInView.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "slam_msgs/srv/detail/get_landmarks_in_view__rosidl_typesupport_introspection_c.h"
#include "slam_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "slam_msgs/srv/detail/get_landmarks_in_view__functions.h"
#include "slam_msgs/srv/detail/get_landmarks_in_view__struct.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  slam_msgs__srv__GetLandmarksInView_Request__init(message_memory);
}

void slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_fini_function(void * message_memory)
{
  slam_msgs__srv__GetLandmarksInView_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_message_member_array[3] = {
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs__srv__GetLandmarksInView_Request, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_angle_pose_observation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs__srv__GetLandmarksInView_Request, max_angle_pose_observation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_dist_pose_observation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs__srv__GetLandmarksInView_Request, max_dist_pose_observation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_message_members = {
  "slam_msgs__srv",  // message namespace
  "GetLandmarksInView_Request",  // message name
  3,  // number of fields
  sizeof(slam_msgs__srv__GetLandmarksInView_Request),
  slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_message_member_array,  // message members
  slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_message_type_support_handle = {
  0,
  &slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_slam_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slam_msgs, srv, GetLandmarksInView_Request)() {
  slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_message_type_support_handle.typesupport_identifier) {
    slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &slam_msgs__srv__GetLandmarksInView_Request__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "slam_msgs/srv/detail/get_landmarks_in_view__rosidl_typesupport_introspection_c.h"
// already included above
// #include "slam_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "slam_msgs/srv/detail/get_landmarks_in_view__functions.h"
// already included above
// #include "slam_msgs/srv/detail/get_landmarks_in_view__struct.h"


// Include directives for member types
// Member `map_points`
#include "slam_msgs/msg/map_point.h"
// Member `map_points`
#include "slam_msgs/msg/detail/map_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  slam_msgs__srv__GetLandmarksInView_Response__init(message_memory);
}

void slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_fini_function(void * message_memory)
{
  slam_msgs__srv__GetLandmarksInView_Response__fini(message_memory);
}

size_t slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__size_function__GetLandmarksInView_Response__map_points(
  const void * untyped_member)
{
  const slam_msgs__msg__MapPoint__Sequence * member =
    (const slam_msgs__msg__MapPoint__Sequence *)(untyped_member);
  return member->size;
}

const void * slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__get_const_function__GetLandmarksInView_Response__map_points(
  const void * untyped_member, size_t index)
{
  const slam_msgs__msg__MapPoint__Sequence * member =
    (const slam_msgs__msg__MapPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__get_function__GetLandmarksInView_Response__map_points(
  void * untyped_member, size_t index)
{
  slam_msgs__msg__MapPoint__Sequence * member =
    (slam_msgs__msg__MapPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__fetch_function__GetLandmarksInView_Response__map_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const slam_msgs__msg__MapPoint * item =
    ((const slam_msgs__msg__MapPoint *)
    slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__get_const_function__GetLandmarksInView_Response__map_points(untyped_member, index));
  slam_msgs__msg__MapPoint * value =
    (slam_msgs__msg__MapPoint *)(untyped_value);
  *value = *item;
}

void slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__assign_function__GetLandmarksInView_Response__map_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  slam_msgs__msg__MapPoint * item =
    ((slam_msgs__msg__MapPoint *)
    slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__get_function__GetLandmarksInView_Response__map_points(untyped_member, index));
  const slam_msgs__msg__MapPoint * value =
    (const slam_msgs__msg__MapPoint *)(untyped_value);
  *item = *value;
}

bool slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__resize_function__GetLandmarksInView_Response__map_points(
  void * untyped_member, size_t size)
{
  slam_msgs__msg__MapPoint__Sequence * member =
    (slam_msgs__msg__MapPoint__Sequence *)(untyped_member);
  slam_msgs__msg__MapPoint__Sequence__fini(member);
  return slam_msgs__msg__MapPoint__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_message_member_array[1] = {
  {
    "map_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs__srv__GetLandmarksInView_Response, map_points),  // bytes offset in struct
    NULL,  // default value
    slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__size_function__GetLandmarksInView_Response__map_points,  // size() function pointer
    slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__get_const_function__GetLandmarksInView_Response__map_points,  // get_const(index) function pointer
    slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__get_function__GetLandmarksInView_Response__map_points,  // get(index) function pointer
    slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__fetch_function__GetLandmarksInView_Response__map_points,  // fetch(index, &value) function pointer
    slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__assign_function__GetLandmarksInView_Response__map_points,  // assign(index, value) function pointer
    slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__resize_function__GetLandmarksInView_Response__map_points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_message_members = {
  "slam_msgs__srv",  // message namespace
  "GetLandmarksInView_Response",  // message name
  1,  // number of fields
  sizeof(slam_msgs__srv__GetLandmarksInView_Response),
  slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_message_member_array,  // message members
  slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_message_type_support_handle = {
  0,
  &slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_slam_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slam_msgs, srv, GetLandmarksInView_Response)() {
  slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slam_msgs, msg, MapPoint)();
  if (!slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_message_type_support_handle.typesupport_identifier) {
    slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &slam_msgs__srv__GetLandmarksInView_Response__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "slam_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "slam_msgs/srv/detail/get_landmarks_in_view__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers slam_msgs__srv__detail__get_landmarks_in_view__rosidl_typesupport_introspection_c__GetLandmarksInView_service_members = {
  "slam_msgs__srv",  // service namespace
  "GetLandmarksInView",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // slam_msgs__srv__detail__get_landmarks_in_view__rosidl_typesupport_introspection_c__GetLandmarksInView_Request_message_type_support_handle,
  NULL  // response message
  // slam_msgs__srv__detail__get_landmarks_in_view__rosidl_typesupport_introspection_c__GetLandmarksInView_Response_message_type_support_handle
};

static rosidl_service_type_support_t slam_msgs__srv__detail__get_landmarks_in_view__rosidl_typesupport_introspection_c__GetLandmarksInView_service_type_support_handle = {
  0,
  &slam_msgs__srv__detail__get_landmarks_in_view__rosidl_typesupport_introspection_c__GetLandmarksInView_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slam_msgs, srv, GetLandmarksInView_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slam_msgs, srv, GetLandmarksInView_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_slam_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slam_msgs, srv, GetLandmarksInView)() {
  if (!slam_msgs__srv__detail__get_landmarks_in_view__rosidl_typesupport_introspection_c__GetLandmarksInView_service_type_support_handle.typesupport_identifier) {
    slam_msgs__srv__detail__get_landmarks_in_view__rosidl_typesupport_introspection_c__GetLandmarksInView_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)slam_msgs__srv__detail__get_landmarks_in_view__rosidl_typesupport_introspection_c__GetLandmarksInView_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slam_msgs, srv, GetLandmarksInView_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, slam_msgs, srv, GetLandmarksInView_Response)()->data;
  }

  return &slam_msgs__srv__detail__get_landmarks_in_view__rosidl_typesupport_introspection_c__GetLandmarksInView_service_type_support_handle;
}

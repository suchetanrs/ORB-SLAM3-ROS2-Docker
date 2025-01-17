// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from slam_msgs:srv/GetLandmarksInView.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "slam_msgs/srv/detail/get_landmarks_in_view__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace slam_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetLandmarksInView_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) slam_msgs::srv::GetLandmarksInView_Request(_init);
}

void GetLandmarksInView_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<slam_msgs::srv::GetLandmarksInView_Request *>(message_memory);
  typed_message->~GetLandmarksInView_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetLandmarksInView_Request_message_member_array[3] = {
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Pose>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs::srv::GetLandmarksInView_Request, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "max_angle_pose_observation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs::srv::GetLandmarksInView_Request, max_angle_pose_observation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "max_dist_pose_observation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs::srv::GetLandmarksInView_Request, max_dist_pose_observation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetLandmarksInView_Request_message_members = {
  "slam_msgs::srv",  // message namespace
  "GetLandmarksInView_Request",  // message name
  3,  // number of fields
  sizeof(slam_msgs::srv::GetLandmarksInView_Request),
  GetLandmarksInView_Request_message_member_array,  // message members
  GetLandmarksInView_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetLandmarksInView_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetLandmarksInView_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetLandmarksInView_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace slam_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<slam_msgs::srv::GetLandmarksInView_Request>()
{
  return &::slam_msgs::srv::rosidl_typesupport_introspection_cpp::GetLandmarksInView_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, slam_msgs, srv, GetLandmarksInView_Request)() {
  return &::slam_msgs::srv::rosidl_typesupport_introspection_cpp::GetLandmarksInView_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "slam_msgs/srv/detail/get_landmarks_in_view__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace slam_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetLandmarksInView_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) slam_msgs::srv::GetLandmarksInView_Response(_init);
}

void GetLandmarksInView_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<slam_msgs::srv::GetLandmarksInView_Response *>(message_memory);
  typed_message->~GetLandmarksInView_Response();
}

size_t size_function__GetLandmarksInView_Response__map_points(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<slam_msgs::msg::MapPoint> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetLandmarksInView_Response__map_points(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<slam_msgs::msg::MapPoint> *>(untyped_member);
  return &member[index];
}

void * get_function__GetLandmarksInView_Response__map_points(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<slam_msgs::msg::MapPoint> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetLandmarksInView_Response__map_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const slam_msgs::msg::MapPoint *>(
    get_const_function__GetLandmarksInView_Response__map_points(untyped_member, index));
  auto & value = *reinterpret_cast<slam_msgs::msg::MapPoint *>(untyped_value);
  value = item;
}

void assign_function__GetLandmarksInView_Response__map_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<slam_msgs::msg::MapPoint *>(
    get_function__GetLandmarksInView_Response__map_points(untyped_member, index));
  const auto & value = *reinterpret_cast<const slam_msgs::msg::MapPoint *>(untyped_value);
  item = value;
}

void resize_function__GetLandmarksInView_Response__map_points(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<slam_msgs::msg::MapPoint> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetLandmarksInView_Response_message_member_array[1] = {
  {
    "map_points",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<slam_msgs::msg::MapPoint>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs::srv::GetLandmarksInView_Response, map_points),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetLandmarksInView_Response__map_points,  // size() function pointer
    get_const_function__GetLandmarksInView_Response__map_points,  // get_const(index) function pointer
    get_function__GetLandmarksInView_Response__map_points,  // get(index) function pointer
    fetch_function__GetLandmarksInView_Response__map_points,  // fetch(index, &value) function pointer
    assign_function__GetLandmarksInView_Response__map_points,  // assign(index, value) function pointer
    resize_function__GetLandmarksInView_Response__map_points  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetLandmarksInView_Response_message_members = {
  "slam_msgs::srv",  // message namespace
  "GetLandmarksInView_Response",  // message name
  1,  // number of fields
  sizeof(slam_msgs::srv::GetLandmarksInView_Response),
  GetLandmarksInView_Response_message_member_array,  // message members
  GetLandmarksInView_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetLandmarksInView_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetLandmarksInView_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetLandmarksInView_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace slam_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<slam_msgs::srv::GetLandmarksInView_Response>()
{
  return &::slam_msgs::srv::rosidl_typesupport_introspection_cpp::GetLandmarksInView_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, slam_msgs, srv, GetLandmarksInView_Response)() {
  return &::slam_msgs::srv::rosidl_typesupport_introspection_cpp::GetLandmarksInView_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "slam_msgs/srv/detail/get_landmarks_in_view__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace slam_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers GetLandmarksInView_service_members = {
  "slam_msgs::srv",  // service namespace
  "GetLandmarksInView",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<slam_msgs::srv::GetLandmarksInView>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t GetLandmarksInView_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetLandmarksInView_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace slam_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<slam_msgs::srv::GetLandmarksInView>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::slam_msgs::srv::rosidl_typesupport_introspection_cpp::GetLandmarksInView_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::slam_msgs::srv::GetLandmarksInView_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::slam_msgs::srv::GetLandmarksInView_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, slam_msgs, srv, GetLandmarksInView)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<slam_msgs::srv::GetLandmarksInView>();
}

#ifdef __cplusplus
}
#endif

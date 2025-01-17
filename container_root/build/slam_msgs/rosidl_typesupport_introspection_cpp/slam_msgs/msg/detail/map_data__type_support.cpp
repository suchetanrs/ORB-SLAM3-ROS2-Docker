// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from slam_msgs:msg/MapData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "slam_msgs/msg/detail/map_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace slam_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MapData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) slam_msgs::msg::MapData(_init);
}

void MapData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<slam_msgs::msg::MapData *>(message_memory);
  typed_message->~MapData();
}

size_t size_function__MapData__nodes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<slam_msgs::msg::KeyFrame> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MapData__nodes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<slam_msgs::msg::KeyFrame> *>(untyped_member);
  return &member[index];
}

void * get_function__MapData__nodes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<slam_msgs::msg::KeyFrame> *>(untyped_member);
  return &member[index];
}

void fetch_function__MapData__nodes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const slam_msgs::msg::KeyFrame *>(
    get_const_function__MapData__nodes(untyped_member, index));
  auto & value = *reinterpret_cast<slam_msgs::msg::KeyFrame *>(untyped_value);
  value = item;
}

void assign_function__MapData__nodes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<slam_msgs::msg::KeyFrame *>(
    get_function__MapData__nodes(untyped_member, index));
  const auto & value = *reinterpret_cast<const slam_msgs::msg::KeyFrame *>(untyped_value);
  item = value;
}

void resize_function__MapData__nodes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<slam_msgs::msg::KeyFrame> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MapData_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs::msg::MapData, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "graph",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<slam_msgs::msg::MapGraph>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs::msg::MapData, graph),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "nodes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<slam_msgs::msg::KeyFrame>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(slam_msgs::msg::MapData, nodes),  // bytes offset in struct
    nullptr,  // default value
    size_function__MapData__nodes,  // size() function pointer
    get_const_function__MapData__nodes,  // get_const(index) function pointer
    get_function__MapData__nodes,  // get(index) function pointer
    fetch_function__MapData__nodes,  // fetch(index, &value) function pointer
    assign_function__MapData__nodes,  // assign(index, value) function pointer
    resize_function__MapData__nodes  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MapData_message_members = {
  "slam_msgs::msg",  // message namespace
  "MapData",  // message name
  3,  // number of fields
  sizeof(slam_msgs::msg::MapData),
  MapData_message_member_array,  // message members
  MapData_init_function,  // function to initialize message memory (memory has to be allocated)
  MapData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MapData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MapData_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace slam_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<slam_msgs::msg::MapData>()
{
  return &::slam_msgs::msg::rosidl_typesupport_introspection_cpp::MapData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, slam_msgs, msg, MapData)() {
  return &::slam_msgs::msg::rosidl_typesupport_introspection_cpp::MapData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

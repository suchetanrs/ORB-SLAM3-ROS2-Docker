// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from slam_msgs:srv/GetMap.idl
// generated code does not contain a copyright notice

#ifndef SLAM_MSGS__SRV__DETAIL__GET_MAP__FUNCTIONS_H_
#define SLAM_MSGS__SRV__DETAIL__GET_MAP__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "slam_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "slam_msgs/srv/detail/get_map__struct.h"

/// Initialize srv/GetMap message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * slam_msgs__srv__GetMap_Request
 * )) before or use
 * slam_msgs__srv__GetMap_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Request__init(slam_msgs__srv__GetMap_Request * msg);

/// Finalize srv/GetMap message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
void
slam_msgs__srv__GetMap_Request__fini(slam_msgs__srv__GetMap_Request * msg);

/// Create srv/GetMap message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * slam_msgs__srv__GetMap_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
slam_msgs__srv__GetMap_Request *
slam_msgs__srv__GetMap_Request__create();

/// Destroy srv/GetMap message.
/**
 * It calls
 * slam_msgs__srv__GetMap_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
void
slam_msgs__srv__GetMap_Request__destroy(slam_msgs__srv__GetMap_Request * msg);

/// Check for srv/GetMap message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Request__are_equal(const slam_msgs__srv__GetMap_Request * lhs, const slam_msgs__srv__GetMap_Request * rhs);

/// Copy a srv/GetMap message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Request__copy(
  const slam_msgs__srv__GetMap_Request * input,
  slam_msgs__srv__GetMap_Request * output);

/// Initialize array of srv/GetMap messages.
/**
 * It allocates the memory for the number of elements and calls
 * slam_msgs__srv__GetMap_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Request__Sequence__init(slam_msgs__srv__GetMap_Request__Sequence * array, size_t size);

/// Finalize array of srv/GetMap messages.
/**
 * It calls
 * slam_msgs__srv__GetMap_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
void
slam_msgs__srv__GetMap_Request__Sequence__fini(slam_msgs__srv__GetMap_Request__Sequence * array);

/// Create array of srv/GetMap messages.
/**
 * It allocates the memory for the array and calls
 * slam_msgs__srv__GetMap_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
slam_msgs__srv__GetMap_Request__Sequence *
slam_msgs__srv__GetMap_Request__Sequence__create(size_t size);

/// Destroy array of srv/GetMap messages.
/**
 * It calls
 * slam_msgs__srv__GetMap_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
void
slam_msgs__srv__GetMap_Request__Sequence__destroy(slam_msgs__srv__GetMap_Request__Sequence * array);

/// Check for srv/GetMap message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Request__Sequence__are_equal(const slam_msgs__srv__GetMap_Request__Sequence * lhs, const slam_msgs__srv__GetMap_Request__Sequence * rhs);

/// Copy an array of srv/GetMap messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Request__Sequence__copy(
  const slam_msgs__srv__GetMap_Request__Sequence * input,
  slam_msgs__srv__GetMap_Request__Sequence * output);

/// Initialize srv/GetMap message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * slam_msgs__srv__GetMap_Response
 * )) before or use
 * slam_msgs__srv__GetMap_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Response__init(slam_msgs__srv__GetMap_Response * msg);

/// Finalize srv/GetMap message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
void
slam_msgs__srv__GetMap_Response__fini(slam_msgs__srv__GetMap_Response * msg);

/// Create srv/GetMap message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * slam_msgs__srv__GetMap_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
slam_msgs__srv__GetMap_Response *
slam_msgs__srv__GetMap_Response__create();

/// Destroy srv/GetMap message.
/**
 * It calls
 * slam_msgs__srv__GetMap_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
void
slam_msgs__srv__GetMap_Response__destroy(slam_msgs__srv__GetMap_Response * msg);

/// Check for srv/GetMap message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Response__are_equal(const slam_msgs__srv__GetMap_Response * lhs, const slam_msgs__srv__GetMap_Response * rhs);

/// Copy a srv/GetMap message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Response__copy(
  const slam_msgs__srv__GetMap_Response * input,
  slam_msgs__srv__GetMap_Response * output);

/// Initialize array of srv/GetMap messages.
/**
 * It allocates the memory for the number of elements and calls
 * slam_msgs__srv__GetMap_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Response__Sequence__init(slam_msgs__srv__GetMap_Response__Sequence * array, size_t size);

/// Finalize array of srv/GetMap messages.
/**
 * It calls
 * slam_msgs__srv__GetMap_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
void
slam_msgs__srv__GetMap_Response__Sequence__fini(slam_msgs__srv__GetMap_Response__Sequence * array);

/// Create array of srv/GetMap messages.
/**
 * It allocates the memory for the array and calls
 * slam_msgs__srv__GetMap_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
slam_msgs__srv__GetMap_Response__Sequence *
slam_msgs__srv__GetMap_Response__Sequence__create(size_t size);

/// Destroy array of srv/GetMap messages.
/**
 * It calls
 * slam_msgs__srv__GetMap_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
void
slam_msgs__srv__GetMap_Response__Sequence__destroy(slam_msgs__srv__GetMap_Response__Sequence * array);

/// Check for srv/GetMap message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Response__Sequence__are_equal(const slam_msgs__srv__GetMap_Response__Sequence * lhs, const slam_msgs__srv__GetMap_Response__Sequence * rhs);

/// Copy an array of srv/GetMap messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_slam_msgs
bool
slam_msgs__srv__GetMap_Response__Sequence__copy(
  const slam_msgs__srv__GetMap_Response__Sequence * input,
  slam_msgs__srv__GetMap_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SLAM_MSGS__SRV__DETAIL__GET_MAP__FUNCTIONS_H_

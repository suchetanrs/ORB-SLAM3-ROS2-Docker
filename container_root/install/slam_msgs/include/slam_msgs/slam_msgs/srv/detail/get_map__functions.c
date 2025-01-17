// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from slam_msgs:srv/GetMap.idl
// generated code does not contain a copyright notice
#include "slam_msgs/srv/detail/get_map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `kf_id_for_landmarks`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
slam_msgs__srv__GetMap_Request__init(slam_msgs__srv__GetMap_Request * msg)
{
  if (!msg) {
    return false;
  }
  // tracked_points
  // kf_id_for_landmarks
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->kf_id_for_landmarks, 0)) {
    slam_msgs__srv__GetMap_Request__fini(msg);
    return false;
  }
  return true;
}

void
slam_msgs__srv__GetMap_Request__fini(slam_msgs__srv__GetMap_Request * msg)
{
  if (!msg) {
    return;
  }
  // tracked_points
  // kf_id_for_landmarks
  rosidl_runtime_c__int32__Sequence__fini(&msg->kf_id_for_landmarks);
}

bool
slam_msgs__srv__GetMap_Request__are_equal(const slam_msgs__srv__GetMap_Request * lhs, const slam_msgs__srv__GetMap_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tracked_points
  if (lhs->tracked_points != rhs->tracked_points) {
    return false;
  }
  // kf_id_for_landmarks
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->kf_id_for_landmarks), &(rhs->kf_id_for_landmarks)))
  {
    return false;
  }
  return true;
}

bool
slam_msgs__srv__GetMap_Request__copy(
  const slam_msgs__srv__GetMap_Request * input,
  slam_msgs__srv__GetMap_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // tracked_points
  output->tracked_points = input->tracked_points;
  // kf_id_for_landmarks
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->kf_id_for_landmarks), &(output->kf_id_for_landmarks)))
  {
    return false;
  }
  return true;
}

slam_msgs__srv__GetMap_Request *
slam_msgs__srv__GetMap_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetMap_Request * msg = (slam_msgs__srv__GetMap_Request *)allocator.allocate(sizeof(slam_msgs__srv__GetMap_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slam_msgs__srv__GetMap_Request));
  bool success = slam_msgs__srv__GetMap_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slam_msgs__srv__GetMap_Request__destroy(slam_msgs__srv__GetMap_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slam_msgs__srv__GetMap_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slam_msgs__srv__GetMap_Request__Sequence__init(slam_msgs__srv__GetMap_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetMap_Request * data = NULL;

  if (size) {
    data = (slam_msgs__srv__GetMap_Request *)allocator.zero_allocate(size, sizeof(slam_msgs__srv__GetMap_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slam_msgs__srv__GetMap_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slam_msgs__srv__GetMap_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
slam_msgs__srv__GetMap_Request__Sequence__fini(slam_msgs__srv__GetMap_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      slam_msgs__srv__GetMap_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

slam_msgs__srv__GetMap_Request__Sequence *
slam_msgs__srv__GetMap_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetMap_Request__Sequence * array = (slam_msgs__srv__GetMap_Request__Sequence *)allocator.allocate(sizeof(slam_msgs__srv__GetMap_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slam_msgs__srv__GetMap_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slam_msgs__srv__GetMap_Request__Sequence__destroy(slam_msgs__srv__GetMap_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slam_msgs__srv__GetMap_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slam_msgs__srv__GetMap_Request__Sequence__are_equal(const slam_msgs__srv__GetMap_Request__Sequence * lhs, const slam_msgs__srv__GetMap_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slam_msgs__srv__GetMap_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slam_msgs__srv__GetMap_Request__Sequence__copy(
  const slam_msgs__srv__GetMap_Request__Sequence * input,
  slam_msgs__srv__GetMap_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slam_msgs__srv__GetMap_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    slam_msgs__srv__GetMap_Request * data =
      (slam_msgs__srv__GetMap_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slam_msgs__srv__GetMap_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          slam_msgs__srv__GetMap_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!slam_msgs__srv__GetMap_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `data`
#include "slam_msgs/msg/detail/map_data__functions.h"

bool
slam_msgs__srv__GetMap_Response__init(slam_msgs__srv__GetMap_Response * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!slam_msgs__msg__MapData__init(&msg->data)) {
    slam_msgs__srv__GetMap_Response__fini(msg);
    return false;
  }
  return true;
}

void
slam_msgs__srv__GetMap_Response__fini(slam_msgs__srv__GetMap_Response * msg)
{
  if (!msg) {
    return;
  }
  // data
  slam_msgs__msg__MapData__fini(&msg->data);
}

bool
slam_msgs__srv__GetMap_Response__are_equal(const slam_msgs__srv__GetMap_Response * lhs, const slam_msgs__srv__GetMap_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  if (!slam_msgs__msg__MapData__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
slam_msgs__srv__GetMap_Response__copy(
  const slam_msgs__srv__GetMap_Response * input,
  slam_msgs__srv__GetMap_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  if (!slam_msgs__msg__MapData__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

slam_msgs__srv__GetMap_Response *
slam_msgs__srv__GetMap_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetMap_Response * msg = (slam_msgs__srv__GetMap_Response *)allocator.allocate(sizeof(slam_msgs__srv__GetMap_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slam_msgs__srv__GetMap_Response));
  bool success = slam_msgs__srv__GetMap_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slam_msgs__srv__GetMap_Response__destroy(slam_msgs__srv__GetMap_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slam_msgs__srv__GetMap_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slam_msgs__srv__GetMap_Response__Sequence__init(slam_msgs__srv__GetMap_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetMap_Response * data = NULL;

  if (size) {
    data = (slam_msgs__srv__GetMap_Response *)allocator.zero_allocate(size, sizeof(slam_msgs__srv__GetMap_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slam_msgs__srv__GetMap_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slam_msgs__srv__GetMap_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
slam_msgs__srv__GetMap_Response__Sequence__fini(slam_msgs__srv__GetMap_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      slam_msgs__srv__GetMap_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

slam_msgs__srv__GetMap_Response__Sequence *
slam_msgs__srv__GetMap_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetMap_Response__Sequence * array = (slam_msgs__srv__GetMap_Response__Sequence *)allocator.allocate(sizeof(slam_msgs__srv__GetMap_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slam_msgs__srv__GetMap_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slam_msgs__srv__GetMap_Response__Sequence__destroy(slam_msgs__srv__GetMap_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slam_msgs__srv__GetMap_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slam_msgs__srv__GetMap_Response__Sequence__are_equal(const slam_msgs__srv__GetMap_Response__Sequence * lhs, const slam_msgs__srv__GetMap_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slam_msgs__srv__GetMap_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slam_msgs__srv__GetMap_Response__Sequence__copy(
  const slam_msgs__srv__GetMap_Response__Sequence * input,
  slam_msgs__srv__GetMap_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slam_msgs__srv__GetMap_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    slam_msgs__srv__GetMap_Response * data =
      (slam_msgs__srv__GetMap_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slam_msgs__srv__GetMap_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          slam_msgs__srv__GetMap_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!slam_msgs__srv__GetMap_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from slam_msgs:msg/MapData.idl
// generated code does not contain a copyright notice
#include "slam_msgs/msg/detail/map_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `graph`
#include "slam_msgs/msg/detail/map_graph__functions.h"
// Member `nodes`
#include "slam_msgs/msg/detail/key_frame__functions.h"

bool
slam_msgs__msg__MapData__init(slam_msgs__msg__MapData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    slam_msgs__msg__MapData__fini(msg);
    return false;
  }
  // graph
  if (!slam_msgs__msg__MapGraph__init(&msg->graph)) {
    slam_msgs__msg__MapData__fini(msg);
    return false;
  }
  // nodes
  if (!slam_msgs__msg__KeyFrame__Sequence__init(&msg->nodes, 0)) {
    slam_msgs__msg__MapData__fini(msg);
    return false;
  }
  return true;
}

void
slam_msgs__msg__MapData__fini(slam_msgs__msg__MapData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // graph
  slam_msgs__msg__MapGraph__fini(&msg->graph);
  // nodes
  slam_msgs__msg__KeyFrame__Sequence__fini(&msg->nodes);
}

bool
slam_msgs__msg__MapData__are_equal(const slam_msgs__msg__MapData * lhs, const slam_msgs__msg__MapData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // graph
  if (!slam_msgs__msg__MapGraph__are_equal(
      &(lhs->graph), &(rhs->graph)))
  {
    return false;
  }
  // nodes
  if (!slam_msgs__msg__KeyFrame__Sequence__are_equal(
      &(lhs->nodes), &(rhs->nodes)))
  {
    return false;
  }
  return true;
}

bool
slam_msgs__msg__MapData__copy(
  const slam_msgs__msg__MapData * input,
  slam_msgs__msg__MapData * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // graph
  if (!slam_msgs__msg__MapGraph__copy(
      &(input->graph), &(output->graph)))
  {
    return false;
  }
  // nodes
  if (!slam_msgs__msg__KeyFrame__Sequence__copy(
      &(input->nodes), &(output->nodes)))
  {
    return false;
  }
  return true;
}

slam_msgs__msg__MapData *
slam_msgs__msg__MapData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__msg__MapData * msg = (slam_msgs__msg__MapData *)allocator.allocate(sizeof(slam_msgs__msg__MapData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slam_msgs__msg__MapData));
  bool success = slam_msgs__msg__MapData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slam_msgs__msg__MapData__destroy(slam_msgs__msg__MapData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slam_msgs__msg__MapData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slam_msgs__msg__MapData__Sequence__init(slam_msgs__msg__MapData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__msg__MapData * data = NULL;

  if (size) {
    data = (slam_msgs__msg__MapData *)allocator.zero_allocate(size, sizeof(slam_msgs__msg__MapData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slam_msgs__msg__MapData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slam_msgs__msg__MapData__fini(&data[i - 1]);
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
slam_msgs__msg__MapData__Sequence__fini(slam_msgs__msg__MapData__Sequence * array)
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
      slam_msgs__msg__MapData__fini(&array->data[i]);
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

slam_msgs__msg__MapData__Sequence *
slam_msgs__msg__MapData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__msg__MapData__Sequence * array = (slam_msgs__msg__MapData__Sequence *)allocator.allocate(sizeof(slam_msgs__msg__MapData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slam_msgs__msg__MapData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slam_msgs__msg__MapData__Sequence__destroy(slam_msgs__msg__MapData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slam_msgs__msg__MapData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slam_msgs__msg__MapData__Sequence__are_equal(const slam_msgs__msg__MapData__Sequence * lhs, const slam_msgs__msg__MapData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slam_msgs__msg__MapData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slam_msgs__msg__MapData__Sequence__copy(
  const slam_msgs__msg__MapData__Sequence * input,
  slam_msgs__msg__MapData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slam_msgs__msg__MapData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    slam_msgs__msg__MapData * data =
      (slam_msgs__msg__MapData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slam_msgs__msg__MapData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          slam_msgs__msg__MapData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!slam_msgs__msg__MapData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from slam_msgs:msg/MapPoint.idl
// generated code does not contain a copyright notice
#include "slam_msgs/msg/detail/map_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `observing_keyframes`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
slam_msgs__msg__MapPoint__init(slam_msgs__msg__MapPoint * msg)
{
  if (!msg) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    slam_msgs__msg__MapPoint__fini(msg);
    return false;
  }
  // observing_keyframes
  if (!geometry_msgs__msg__Pose__Sequence__init(&msg->observing_keyframes, 0)) {
    slam_msgs__msg__MapPoint__fini(msg);
    return false;
  }
  return true;
}

void
slam_msgs__msg__MapPoint__fini(slam_msgs__msg__MapPoint * msg)
{
  if (!msg) {
    return;
  }
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // observing_keyframes
  geometry_msgs__msg__Pose__Sequence__fini(&msg->observing_keyframes);
}

bool
slam_msgs__msg__MapPoint__are_equal(const slam_msgs__msg__MapPoint * lhs, const slam_msgs__msg__MapPoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // observing_keyframes
  if (!geometry_msgs__msg__Pose__Sequence__are_equal(
      &(lhs->observing_keyframes), &(rhs->observing_keyframes)))
  {
    return false;
  }
  return true;
}

bool
slam_msgs__msg__MapPoint__copy(
  const slam_msgs__msg__MapPoint * input,
  slam_msgs__msg__MapPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // observing_keyframes
  if (!geometry_msgs__msg__Pose__Sequence__copy(
      &(input->observing_keyframes), &(output->observing_keyframes)))
  {
    return false;
  }
  return true;
}

slam_msgs__msg__MapPoint *
slam_msgs__msg__MapPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__msg__MapPoint * msg = (slam_msgs__msg__MapPoint *)allocator.allocate(sizeof(slam_msgs__msg__MapPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slam_msgs__msg__MapPoint));
  bool success = slam_msgs__msg__MapPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slam_msgs__msg__MapPoint__destroy(slam_msgs__msg__MapPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slam_msgs__msg__MapPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slam_msgs__msg__MapPoint__Sequence__init(slam_msgs__msg__MapPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__msg__MapPoint * data = NULL;

  if (size) {
    data = (slam_msgs__msg__MapPoint *)allocator.zero_allocate(size, sizeof(slam_msgs__msg__MapPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slam_msgs__msg__MapPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slam_msgs__msg__MapPoint__fini(&data[i - 1]);
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
slam_msgs__msg__MapPoint__Sequence__fini(slam_msgs__msg__MapPoint__Sequence * array)
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
      slam_msgs__msg__MapPoint__fini(&array->data[i]);
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

slam_msgs__msg__MapPoint__Sequence *
slam_msgs__msg__MapPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__msg__MapPoint__Sequence * array = (slam_msgs__msg__MapPoint__Sequence *)allocator.allocate(sizeof(slam_msgs__msg__MapPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slam_msgs__msg__MapPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slam_msgs__msg__MapPoint__Sequence__destroy(slam_msgs__msg__MapPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slam_msgs__msg__MapPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slam_msgs__msg__MapPoint__Sequence__are_equal(const slam_msgs__msg__MapPoint__Sequence * lhs, const slam_msgs__msg__MapPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slam_msgs__msg__MapPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slam_msgs__msg__MapPoint__Sequence__copy(
  const slam_msgs__msg__MapPoint__Sequence * input,
  slam_msgs__msg__MapPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slam_msgs__msg__MapPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    slam_msgs__msg__MapPoint * data =
      (slam_msgs__msg__MapPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slam_msgs__msg__MapPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          slam_msgs__msg__MapPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!slam_msgs__msg__MapPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

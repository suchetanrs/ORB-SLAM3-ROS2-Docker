// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from slam_msgs:msg/KeyFrame.idl
// generated code does not contain a copyright notice
#include "slam_msgs/msg/detail/key_frame__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `word_pts`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
slam_msgs__msg__KeyFrame__init(slam_msgs__msg__KeyFrame * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // word_pts
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->word_pts, 0)) {
    slam_msgs__msg__KeyFrame__fini(msg);
    return false;
  }
  return true;
}

void
slam_msgs__msg__KeyFrame__fini(slam_msgs__msg__KeyFrame * msg)
{
  if (!msg) {
    return;
  }
  // id
  // word_pts
  geometry_msgs__msg__Point__Sequence__fini(&msg->word_pts);
}

bool
slam_msgs__msg__KeyFrame__are_equal(const slam_msgs__msg__KeyFrame * lhs, const slam_msgs__msg__KeyFrame * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // word_pts
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->word_pts), &(rhs->word_pts)))
  {
    return false;
  }
  return true;
}

bool
slam_msgs__msg__KeyFrame__copy(
  const slam_msgs__msg__KeyFrame * input,
  slam_msgs__msg__KeyFrame * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // word_pts
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->word_pts), &(output->word_pts)))
  {
    return false;
  }
  return true;
}

slam_msgs__msg__KeyFrame *
slam_msgs__msg__KeyFrame__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__msg__KeyFrame * msg = (slam_msgs__msg__KeyFrame *)allocator.allocate(sizeof(slam_msgs__msg__KeyFrame), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slam_msgs__msg__KeyFrame));
  bool success = slam_msgs__msg__KeyFrame__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slam_msgs__msg__KeyFrame__destroy(slam_msgs__msg__KeyFrame * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slam_msgs__msg__KeyFrame__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slam_msgs__msg__KeyFrame__Sequence__init(slam_msgs__msg__KeyFrame__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__msg__KeyFrame * data = NULL;

  if (size) {
    data = (slam_msgs__msg__KeyFrame *)allocator.zero_allocate(size, sizeof(slam_msgs__msg__KeyFrame), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slam_msgs__msg__KeyFrame__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slam_msgs__msg__KeyFrame__fini(&data[i - 1]);
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
slam_msgs__msg__KeyFrame__Sequence__fini(slam_msgs__msg__KeyFrame__Sequence * array)
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
      slam_msgs__msg__KeyFrame__fini(&array->data[i]);
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

slam_msgs__msg__KeyFrame__Sequence *
slam_msgs__msg__KeyFrame__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__msg__KeyFrame__Sequence * array = (slam_msgs__msg__KeyFrame__Sequence *)allocator.allocate(sizeof(slam_msgs__msg__KeyFrame__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slam_msgs__msg__KeyFrame__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slam_msgs__msg__KeyFrame__Sequence__destroy(slam_msgs__msg__KeyFrame__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slam_msgs__msg__KeyFrame__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slam_msgs__msg__KeyFrame__Sequence__are_equal(const slam_msgs__msg__KeyFrame__Sequence * lhs, const slam_msgs__msg__KeyFrame__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slam_msgs__msg__KeyFrame__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slam_msgs__msg__KeyFrame__Sequence__copy(
  const slam_msgs__msg__KeyFrame__Sequence * input,
  slam_msgs__msg__KeyFrame__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slam_msgs__msg__KeyFrame);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    slam_msgs__msg__KeyFrame * data =
      (slam_msgs__msg__KeyFrame *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slam_msgs__msg__KeyFrame__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          slam_msgs__msg__KeyFrame__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!slam_msgs__msg__KeyFrame__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

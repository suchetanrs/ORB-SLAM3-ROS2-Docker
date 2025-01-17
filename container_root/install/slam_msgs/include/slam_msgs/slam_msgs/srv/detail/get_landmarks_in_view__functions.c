// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from slam_msgs:srv/GetLandmarksInView.idl
// generated code does not contain a copyright notice
#include "slam_msgs/srv/detail/get_landmarks_in_view__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
slam_msgs__srv__GetLandmarksInView_Request__init(slam_msgs__srv__GetLandmarksInView_Request * msg)
{
  if (!msg) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    slam_msgs__srv__GetLandmarksInView_Request__fini(msg);
    return false;
  }
  // max_angle_pose_observation
  // max_dist_pose_observation
  msg->max_dist_pose_observation = 6.0f;
  return true;
}

void
slam_msgs__srv__GetLandmarksInView_Request__fini(slam_msgs__srv__GetLandmarksInView_Request * msg)
{
  if (!msg) {
    return;
  }
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // max_angle_pose_observation
  // max_dist_pose_observation
}

bool
slam_msgs__srv__GetLandmarksInView_Request__are_equal(const slam_msgs__srv__GetLandmarksInView_Request * lhs, const slam_msgs__srv__GetLandmarksInView_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // max_angle_pose_observation
  if (lhs->max_angle_pose_observation != rhs->max_angle_pose_observation) {
    return false;
  }
  // max_dist_pose_observation
  if (lhs->max_dist_pose_observation != rhs->max_dist_pose_observation) {
    return false;
  }
  return true;
}

bool
slam_msgs__srv__GetLandmarksInView_Request__copy(
  const slam_msgs__srv__GetLandmarksInView_Request * input,
  slam_msgs__srv__GetLandmarksInView_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // max_angle_pose_observation
  output->max_angle_pose_observation = input->max_angle_pose_observation;
  // max_dist_pose_observation
  output->max_dist_pose_observation = input->max_dist_pose_observation;
  return true;
}

slam_msgs__srv__GetLandmarksInView_Request *
slam_msgs__srv__GetLandmarksInView_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetLandmarksInView_Request * msg = (slam_msgs__srv__GetLandmarksInView_Request *)allocator.allocate(sizeof(slam_msgs__srv__GetLandmarksInView_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slam_msgs__srv__GetLandmarksInView_Request));
  bool success = slam_msgs__srv__GetLandmarksInView_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slam_msgs__srv__GetLandmarksInView_Request__destroy(slam_msgs__srv__GetLandmarksInView_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slam_msgs__srv__GetLandmarksInView_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slam_msgs__srv__GetLandmarksInView_Request__Sequence__init(slam_msgs__srv__GetLandmarksInView_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetLandmarksInView_Request * data = NULL;

  if (size) {
    data = (slam_msgs__srv__GetLandmarksInView_Request *)allocator.zero_allocate(size, sizeof(slam_msgs__srv__GetLandmarksInView_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slam_msgs__srv__GetLandmarksInView_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slam_msgs__srv__GetLandmarksInView_Request__fini(&data[i - 1]);
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
slam_msgs__srv__GetLandmarksInView_Request__Sequence__fini(slam_msgs__srv__GetLandmarksInView_Request__Sequence * array)
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
      slam_msgs__srv__GetLandmarksInView_Request__fini(&array->data[i]);
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

slam_msgs__srv__GetLandmarksInView_Request__Sequence *
slam_msgs__srv__GetLandmarksInView_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetLandmarksInView_Request__Sequence * array = (slam_msgs__srv__GetLandmarksInView_Request__Sequence *)allocator.allocate(sizeof(slam_msgs__srv__GetLandmarksInView_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slam_msgs__srv__GetLandmarksInView_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slam_msgs__srv__GetLandmarksInView_Request__Sequence__destroy(slam_msgs__srv__GetLandmarksInView_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slam_msgs__srv__GetLandmarksInView_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slam_msgs__srv__GetLandmarksInView_Request__Sequence__are_equal(const slam_msgs__srv__GetLandmarksInView_Request__Sequence * lhs, const slam_msgs__srv__GetLandmarksInView_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slam_msgs__srv__GetLandmarksInView_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slam_msgs__srv__GetLandmarksInView_Request__Sequence__copy(
  const slam_msgs__srv__GetLandmarksInView_Request__Sequence * input,
  slam_msgs__srv__GetLandmarksInView_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slam_msgs__srv__GetLandmarksInView_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    slam_msgs__srv__GetLandmarksInView_Request * data =
      (slam_msgs__srv__GetLandmarksInView_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slam_msgs__srv__GetLandmarksInView_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          slam_msgs__srv__GetLandmarksInView_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!slam_msgs__srv__GetLandmarksInView_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `map_points`
#include "slam_msgs/msg/detail/map_point__functions.h"

bool
slam_msgs__srv__GetLandmarksInView_Response__init(slam_msgs__srv__GetLandmarksInView_Response * msg)
{
  if (!msg) {
    return false;
  }
  // map_points
  if (!slam_msgs__msg__MapPoint__Sequence__init(&msg->map_points, 0)) {
    slam_msgs__srv__GetLandmarksInView_Response__fini(msg);
    return false;
  }
  return true;
}

void
slam_msgs__srv__GetLandmarksInView_Response__fini(slam_msgs__srv__GetLandmarksInView_Response * msg)
{
  if (!msg) {
    return;
  }
  // map_points
  slam_msgs__msg__MapPoint__Sequence__fini(&msg->map_points);
}

bool
slam_msgs__srv__GetLandmarksInView_Response__are_equal(const slam_msgs__srv__GetLandmarksInView_Response * lhs, const slam_msgs__srv__GetLandmarksInView_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // map_points
  if (!slam_msgs__msg__MapPoint__Sequence__are_equal(
      &(lhs->map_points), &(rhs->map_points)))
  {
    return false;
  }
  return true;
}

bool
slam_msgs__srv__GetLandmarksInView_Response__copy(
  const slam_msgs__srv__GetLandmarksInView_Response * input,
  slam_msgs__srv__GetLandmarksInView_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // map_points
  if (!slam_msgs__msg__MapPoint__Sequence__copy(
      &(input->map_points), &(output->map_points)))
  {
    return false;
  }
  return true;
}

slam_msgs__srv__GetLandmarksInView_Response *
slam_msgs__srv__GetLandmarksInView_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetLandmarksInView_Response * msg = (slam_msgs__srv__GetLandmarksInView_Response *)allocator.allocate(sizeof(slam_msgs__srv__GetLandmarksInView_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slam_msgs__srv__GetLandmarksInView_Response));
  bool success = slam_msgs__srv__GetLandmarksInView_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slam_msgs__srv__GetLandmarksInView_Response__destroy(slam_msgs__srv__GetLandmarksInView_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slam_msgs__srv__GetLandmarksInView_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slam_msgs__srv__GetLandmarksInView_Response__Sequence__init(slam_msgs__srv__GetLandmarksInView_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetLandmarksInView_Response * data = NULL;

  if (size) {
    data = (slam_msgs__srv__GetLandmarksInView_Response *)allocator.zero_allocate(size, sizeof(slam_msgs__srv__GetLandmarksInView_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slam_msgs__srv__GetLandmarksInView_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slam_msgs__srv__GetLandmarksInView_Response__fini(&data[i - 1]);
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
slam_msgs__srv__GetLandmarksInView_Response__Sequence__fini(slam_msgs__srv__GetLandmarksInView_Response__Sequence * array)
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
      slam_msgs__srv__GetLandmarksInView_Response__fini(&array->data[i]);
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

slam_msgs__srv__GetLandmarksInView_Response__Sequence *
slam_msgs__srv__GetLandmarksInView_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_msgs__srv__GetLandmarksInView_Response__Sequence * array = (slam_msgs__srv__GetLandmarksInView_Response__Sequence *)allocator.allocate(sizeof(slam_msgs__srv__GetLandmarksInView_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slam_msgs__srv__GetLandmarksInView_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slam_msgs__srv__GetLandmarksInView_Response__Sequence__destroy(slam_msgs__srv__GetLandmarksInView_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slam_msgs__srv__GetLandmarksInView_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slam_msgs__srv__GetLandmarksInView_Response__Sequence__are_equal(const slam_msgs__srv__GetLandmarksInView_Response__Sequence * lhs, const slam_msgs__srv__GetLandmarksInView_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slam_msgs__srv__GetLandmarksInView_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slam_msgs__srv__GetLandmarksInView_Response__Sequence__copy(
  const slam_msgs__srv__GetLandmarksInView_Response__Sequence * input,
  slam_msgs__srv__GetLandmarksInView_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slam_msgs__srv__GetLandmarksInView_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    slam_msgs__srv__GetLandmarksInView_Response * data =
      (slam_msgs__srv__GetLandmarksInView_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slam_msgs__srv__GetLandmarksInView_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          slam_msgs__srv__GetLandmarksInView_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!slam_msgs__srv__GetLandmarksInView_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

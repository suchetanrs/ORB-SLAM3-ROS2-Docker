// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from slam_msgs:srv/GetLandmarksInView.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "slam_msgs/srv/detail/get_landmarks_in_view__struct.h"
#include "slam_msgs/srv/detail/get_landmarks_in_view__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool slam_msgs__srv__get_landmarks_in_view__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("slam_msgs.srv._get_landmarks_in_view.GetLandmarksInView_Request", full_classname_dest, 63) == 0);
  }
  slam_msgs__srv__GetLandmarksInView_Request * ros_message = _ros_message;
  {  // pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // max_angle_pose_observation
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_angle_pose_observation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_angle_pose_observation = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_dist_pose_observation
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_dist_pose_observation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_dist_pose_observation = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * slam_msgs__srv__get_landmarks_in_view__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GetLandmarksInView_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("slam_msgs.srv._get_landmarks_in_view");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GetLandmarksInView_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  slam_msgs__srv__GetLandmarksInView_Request * ros_message = (slam_msgs__srv__GetLandmarksInView_Request *)raw_ros_message;
  {  // pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_angle_pose_observation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_angle_pose_observation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_angle_pose_observation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_dist_pose_observation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_dist_pose_observation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_dist_pose_observation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "slam_msgs/srv/detail/get_landmarks_in_view__struct.h"
// already included above
// #include "slam_msgs/srv/detail/get_landmarks_in_view__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "slam_msgs/msg/detail/map_point__functions.h"
// end nested array functions include
bool slam_msgs__msg__map_point__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * slam_msgs__msg__map_point__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool slam_msgs__srv__get_landmarks_in_view__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("slam_msgs.srv._get_landmarks_in_view.GetLandmarksInView_Response", full_classname_dest, 64) == 0);
  }
  slam_msgs__srv__GetLandmarksInView_Response * ros_message = _ros_message;
  {  // map_points
    PyObject * field = PyObject_GetAttrString(_pymsg, "map_points");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'map_points'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!slam_msgs__msg__MapPoint__Sequence__init(&(ros_message->map_points), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create slam_msgs__msg__MapPoint__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    slam_msgs__msg__MapPoint * dest = ros_message->map_points.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!slam_msgs__msg__map_point__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * slam_msgs__srv__get_landmarks_in_view__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GetLandmarksInView_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("slam_msgs.srv._get_landmarks_in_view");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GetLandmarksInView_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  slam_msgs__srv__GetLandmarksInView_Response * ros_message = (slam_msgs__srv__GetLandmarksInView_Response *)raw_ros_message;
  {  // map_points
    PyObject * field = NULL;
    size_t size = ros_message->map_points.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    slam_msgs__msg__MapPoint * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->map_points.data[i]);
      PyObject * pyitem = slam_msgs__msg__map_point__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "map_points", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

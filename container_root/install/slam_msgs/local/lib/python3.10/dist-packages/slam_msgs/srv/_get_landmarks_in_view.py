# generated from rosidl_generator_py/resource/_idl.py.em
# with input from slam_msgs:srv/GetLandmarksInView.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetLandmarksInView_Request(type):
    """Metaclass of message 'GetLandmarksInView_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('slam_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'slam_msgs.srv.GetLandmarksInView_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_landmarks_in_view__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_landmarks_in_view__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_landmarks_in_view__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_landmarks_in_view__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_landmarks_in_view__request

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'MAX_DIST_POSE_OBSERVATION__DEFAULT': 6.0,
        }

    @property
    def MAX_DIST_POSE_OBSERVATION__DEFAULT(cls):
        """Return default value for message field 'max_dist_pose_observation'."""
        return 6.0


class GetLandmarksInView_Request(metaclass=Metaclass_GetLandmarksInView_Request):
    """Message class 'GetLandmarksInView_Request'."""

    __slots__ = [
        '_pose',
        '_max_angle_pose_observation',
        '_max_dist_pose_observation',
    ]

    _fields_and_field_types = {
        'pose': 'geometry_msgs/Pose',
        'max_angle_pose_observation': 'float',
        'max_dist_pose_observation': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Pose
        self.pose = kwargs.get('pose', Pose())
        self.max_angle_pose_observation = kwargs.get('max_angle_pose_observation', float())
        self.max_dist_pose_observation = kwargs.get(
            'max_dist_pose_observation', GetLandmarksInView_Request.MAX_DIST_POSE_OBSERVATION__DEFAULT)

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.pose != other.pose:
            return False
        if self.max_angle_pose_observation != other.max_angle_pose_observation:
            return False
        if self.max_dist_pose_observation != other.max_dist_pose_observation:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose' field must be a sub message of type 'Pose'"
        self._pose = value

    @builtins.property
    def max_angle_pose_observation(self):
        """Message field 'max_angle_pose_observation'."""
        return self._max_angle_pose_observation

    @max_angle_pose_observation.setter
    def max_angle_pose_observation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_angle_pose_observation' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'max_angle_pose_observation' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._max_angle_pose_observation = value

    @builtins.property
    def max_dist_pose_observation(self):
        """Message field 'max_dist_pose_observation'."""
        return self._max_dist_pose_observation

    @max_dist_pose_observation.setter
    def max_dist_pose_observation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_dist_pose_observation' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'max_dist_pose_observation' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._max_dist_pose_observation = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetLandmarksInView_Response(type):
    """Metaclass of message 'GetLandmarksInView_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('slam_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'slam_msgs.srv.GetLandmarksInView_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_landmarks_in_view__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_landmarks_in_view__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_landmarks_in_view__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_landmarks_in_view__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_landmarks_in_view__response

            from slam_msgs.msg import MapPoint
            if MapPoint.__class__._TYPE_SUPPORT is None:
                MapPoint.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetLandmarksInView_Response(metaclass=Metaclass_GetLandmarksInView_Response):
    """Message class 'GetLandmarksInView_Response'."""

    __slots__ = [
        '_map_points',
    ]

    _fields_and_field_types = {
        'map_points': 'sequence<slam_msgs/MapPoint>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['slam_msgs', 'msg'], 'MapPoint')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.map_points = kwargs.get('map_points', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.map_points != other.map_points:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def map_points(self):
        """Message field 'map_points'."""
        return self._map_points

    @map_points.setter
    def map_points(self, value):
        if __debug__:
            from slam_msgs.msg import MapPoint
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, MapPoint) for v in value) and
                 True), \
                "The 'map_points' field must be a set or sequence and each value of type 'MapPoint'"
        self._map_points = value


class Metaclass_GetLandmarksInView(type):
    """Metaclass of service 'GetLandmarksInView'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('slam_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'slam_msgs.srv.GetLandmarksInView')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_landmarks_in_view

            from slam_msgs.srv import _get_landmarks_in_view
            if _get_landmarks_in_view.Metaclass_GetLandmarksInView_Request._TYPE_SUPPORT is None:
                _get_landmarks_in_view.Metaclass_GetLandmarksInView_Request.__import_type_support__()
            if _get_landmarks_in_view.Metaclass_GetLandmarksInView_Response._TYPE_SUPPORT is None:
                _get_landmarks_in_view.Metaclass_GetLandmarksInView_Response.__import_type_support__()


class GetLandmarksInView(metaclass=Metaclass_GetLandmarksInView):
    from slam_msgs.srv._get_landmarks_in_view import GetLandmarksInView_Request as Request
    from slam_msgs.srv._get_landmarks_in_view import GetLandmarksInView_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')

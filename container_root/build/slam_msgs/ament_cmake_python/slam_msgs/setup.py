from setuptools import find_packages
from setuptools import setup

setup(
    name='slam_msgs',
    version='1.0.0',
    packages=find_packages(
        include=('slam_msgs', 'slam_msgs.*')),
)

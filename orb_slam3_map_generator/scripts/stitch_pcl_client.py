#!/usr/bin/env python3

import sys
import rclpy
from rclpy.node import Node

# Import the service type from slam_msgs package
from slam_msgs.srv import GetGlobalPointCloud


class GlobalPointCloudClient(Node):
    def __init__(self):
        super().__init__('global_point_cloud_client')

        # Create a client for the 'trigger_global_cloud' service
        self.client = self.create_client(GetGlobalPointCloud, 'trigger_global_cloud')

        # Wait for the service to be available
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service "trigger_global_cloud" not available, waiting...')

        self.get_logger().info('Service "trigger_global_cloud" is available.')

    def send_request(self, request_params):
        """Send a request to the 'trigger_global_cloud' service."""
        req = GetGlobalPointCloud.Request()

        # Populate the request fields with provided parameters
        req.global_voxel_resolution = request_params.get('global_voxel_resolution', 0.1)
        req.local_voxel_resolution = request_params.get('local_voxel_resolution', 0.05)
        req.z_thresh_max = request_params.get('z_thresh_max', 1.5)
        req.get_grayscale = request_params.get('get_grayscale', False)

        self.get_logger().info('Sending request to trigger_global_cloud service...')
        future = self.client.call_async(req)
        return future


def main(args=None):
    rclpy.init(args=args)

    client_node = GlobalPointCloudClient()

    # Define request parameters
    # !!!!! EDIT THESE IF NEEDED !!!!! 
    request_parameters = {
        'global_voxel_resolution': 0.05,
        'local_voxel_resolution': 0.05,
        'z_thresh_max': 0.8,
        'get_grayscale': False
    }

    future = client_node.send_request(request_parameters)

    # Spin until the future is complete
    while rclpy.ok():
        rclpy.spin_once(client_node)
        if future.done():
            try:
                response = future.result()
            except Exception as e:
                client_node.get_logger().error(f'Service call failed: {e}')
            else:
                if response.response:
                    client_node.get_logger().info('Global point cloud triggered successfully.')
                else:
                    client_node.get_logger().info('Failed to trigger global point cloud.')
            break

    # Shutdown the node
    client_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

import rclpy
from rclpy.node import Node
from slam_msgs.srv import GetMap
from geometry_msgs.msg import PoseArray, Pose, Point

class MapServiceClient(Node):

    def __init__(self):
        super().__init__('map_service_client')
        self.client = self.create_client(GetMap, '/robot_0/orb_slam3_get_map_data')
        self.publisher_ = self.create_publisher(PoseArray, '/pose_array_topic', 10)
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.request_map_data()

    def publish_pose_array(self, word_pts):
        pose_array_msg = PoseArray()
        pose_array_msg.header.frame_id = 'map'  # Set the frame ID as per your requirement

        for point in word_pts:
            pose = Pose()
            pose.position = point
            pose.orientation.w = 1.0  # Assuming default orientation
            pose_array_msg.poses.append(pose)

        self.publisher_.publish(pose_array_msg)
        self.get_logger().info('Published PoseArray message with {} poses'.format(len(pose_array_msg.poses)))

    def request_map_data(self):
        request = GetMap.Request()
        request.tracked_points = True
        request.kf_id_for_landmarks = [67,68,69]
        future = self.client.call_async(request)
        future.add_done_callback(self.callback)

    def callback(self, future):
        try:
            response = future.result()
            self.get_logger().info('Received map data: {}'.format(len(response.data.graph.poses)))
            for node in response.data.nodes:
                self.publish_pose_array(node.word_pts)
                self.get_logger().info('Pose ID: {}'.format(len(node.word_pts)))
            # self.get_logger().info('The number of keyframes: {}'.format(len(response.data.nodes)))
        except Exception as e:
            self.get_logger().error('Service call failed %r' % (e,))

def main(args=None):
    rclpy.init(args=args)
    map_service_client = MapServiceClient()
    rclpy.spin(map_service_client)
    map_service_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

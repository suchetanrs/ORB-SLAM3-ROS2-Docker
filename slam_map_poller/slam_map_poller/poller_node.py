import rclpy
from rclpy.node import Node
from slam_msgs.srv import GetAllLandmarksInMap

class MapPoller(Node):
    def __init__(self):
        super().__init__('map_poller')
        rate = self.declare_parameter('poll_rate', 1.0).value
        self.cli = self.create_client(GetAllLandmarksInMap, 'orb_slam3/get_all_landmarks_in_map')
        self.timer = self.create_timer(1.0 / rate, self.call_service)

    def call_service(self):
        if not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn('service not available')
            return

        req = GetAllLandmarksInMap.Request()
        req.request = True
        self.cli.call_async(req)

def main(args=None):
    rclpy.init(args=args)
    node = MapPoller()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()


#include "../include/drone_control.h"
#include "../include/ros_client.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "offboard_ctrl");
  ros::NodeHandle *nh = new ros::NodeHandle();

  ROSClient ros_client(nh);
  DroneControl drone_control(&ros_client);

  drone_control.offboardMode();
  drone_control.takeOff();

  drone_control.hover(5);

  drone_control.land();
  // drone_control.disarm();
  return 0;
}

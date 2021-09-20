// Actividad 2
// Crear un nodo que se suscriba al tópico de odometría del robot (/odom), con la
// finalidad de ubicar la posición actual del robot.

#include "ros/ros.h"
#include <nav_msgs/Odometry.h>

void chatterCallback(const nav_msgs::Odometry::ConstPtr &msg) {
  auto position = msg->pose.pose.position;
  ROS_INFO("x: [%f]", position.x);
}
int main(int argc, char **argv) {
  ros::init(argc, argv, "listener_odom");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/odom", 1000, chatterCallback);
  ros::spin();
  return 0;
}
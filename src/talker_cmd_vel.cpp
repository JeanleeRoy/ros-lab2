// Actividad 3
// Crear un nodo que publique mensajes al tópico de comando de velocidades
// (/cmd_vel), con la finalidad de mover el robot.

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <sstream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker_cmd_vel");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  // loop rate = cuantas veces por segundo ejecutar el codigo
  ros::Rate loop_rate(1);
  while (ros::ok()) {
    geometry_msgs::Twist msg;
    msg.linear.x = 0.1; // 0.1 metros por segundo
    // output
    ROS_INFO("%f", msg.linear.x);
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
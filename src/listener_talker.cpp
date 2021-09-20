// Actividad 5
// Crear un nodo publicador y suscriptor que pueda mover al robot móvil 
// un metro hacia adelante del mismo (Un metro en el eje X).

#include "ros/ros.h"
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <sstream>

double x = 0;

void callback(const nav_msgs::Odometry::ConstPtr &msg) {
  x = msg->pose.pose.position.x;
  ROS_INFO("x: [%f]", x);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "listener_talker");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/odom", 1000, callback);

  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

  // loop rate = cuantas veces por segundo ejecutar el codigo
  ros::Rate loop_rate(10);

  while (ros::ok()) {
    geometry_msgs::Twist msg;

    if (x >= 5) {
        msg.linear.x = 0.0;
        ROS_INFO("stop");
    } else {
        msg.linear.x = 2; // 0.1 metros por segundo
    }
    
    ROS_INFO("linear.x: %f", msg.linear.x);
    pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

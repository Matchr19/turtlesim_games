#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/TeleportAbsolute.h"
#include "turtlesim/TeleportRelative.h"


int main(int argc, char *argv[]) {
  ros::init(argc, argv, "lecture2_move_turtle");

  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

  geometry_msgs::Twist msg;

  while(ros::ok())
  {

//Different ways of moving the turtlesim: i. Teleport Absolute, ii. Teleport Relative, iii. continously 

/*
  ros::ServiceClient client = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");

  ros::Duration(0.5).sleep();

  turtlesim::TeleportAbsolute srv;
  srv.request.x = 1.0;
  srv.request.y = 10.0;
  client.call(srv);
  ros::Duration(0.5).sleep();

  srv.request.x = 10.0;
  srv.request.y = 10.0;
  client.call(srv);
  ros::Duration(0.5).sleep();

  srv.request.x = 10.0;
  srv.request.y = 5.0;
  client.call(srv);
  ros::Duration(0.5).sleep();

  srv.request.x = 1.0;
  srv.request.y = 5.0;
  client.call(srv);
  ros::Duration(0.5).sleep();

  srv.request.x = 1.0;
  srv.request.y = 10.0;
  client.call(srv);
*/

/*
  ros::ServiceClient client = nh.serviceClient<turtlesim::TeleportRelative>("/turtle1/teleport_relative");

  ros::Duration(0.5).sleep();

  turtlesim::TeleportRelative srv;
  srv.request.linear= 1.0;
  srv.request.angular = 0.0;
  client.call(srv);
  ros::Duration(0.5).sleep();
*/

    msg.linear.x = 1.0;
    msg.angular.z = 0.0;

    /*vi tilføjer antal af runder vi ønsker loopen skal køre*/
   
    int rounds=0;

    do{

    std::cout <<"number of rounds:";
    std::cin >> rounds;
}while (rounds<=0);




    while(ros::ok()&& rounds<0)
    {
    cmd_vel_pub.publish(msg);
    ros::Duration(1.5).sleep();
    rounds--;
    }

  }

  return 0;
}
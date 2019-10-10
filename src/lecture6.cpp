#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/TeleportAbsolute.h"
#include "turtlesim/TeleportRelative.h"


int main(int argc, char *argv[]) {
  ros::init(argc, argv, "lecture2_move_turtle");

  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

  geometry_msgs::Twist msg;
  msg.linear.x = 1.0;
  msg.angular.z = 0.0;

  int rounds = 0;


    char c;
    int size=5;
    int commands[size]={0};
    int amount[size]={0};

    



  for (int i=0; i<size; i++ ){
     std::cout << "\n" << i+1 <<" command 1- forward, -1 backward, 2 turn left, -2 turn right: ";
     std::cin >> commands[i];

     std::cout << "nHow often:";
     std::cin>> amount[i];

     std::cout << "nTry again(y/n):";
     std::cin>> c;

     if (c!='y'){
        i=size;
     }
  

  } while(rounds<=0);
 
  while(ros::ok())
  {
      for(int i=0; i<size; i++){
          if (commands[i]==1){
              msg.linear.x=1.0;
              msg.angular.z=0.0;
          }else if (commands[i]==-1){
              msg.linear.x=-1.0;
              msg.angular.z=0.0;
          }else if(commands[i]==2){
              msg.linear.x=0.0;
              msg.angular.z=0.1;
          }else if(commands[i]==-2){
              msg.linear.x=0.0;
              msg.angular.z=-0.1;
          }  
      
    while( amount[i]>0){
    cmd_vel_pub.publish(msg);
    ros::Duration(1.5).sleep();
    amount[i]--;
    }
      }

  

  return 0;
}
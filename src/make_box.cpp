#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/SetPen.h>
#include <time.h>
#include <stdlib.h>

//intialisering af in and output

int red =1;

//test commit 
int penwidth = 20;

int red = 0;
int green = 0;
int blue = 0;

int x_size = 3;
int y_size = 3;

int x_size1 = 3;
int y_size1 = 3;

int offset = 5.5;



int main(int argc, char *argv[]) {
  ros::init(argc, argv, "move_turtlesim");
  srand (time(NULL));

  red = rand() % 255 + 1;
  green = rand() % 255 + 1;
  blue = rand() % 255 + 1;
  std::cout << red << std::endl;


  penwidth = rand() % 50 + 1;



  float box_size = ros::param::param("~box_size", 9.0);

  ros::NodeHandle nh;

  ros::service::waitForService("/turtle1/teleport_absolute", -1);

  ros::ServiceClient teleport_client = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
  ros::ServiceClient pen_client = nh.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");






  turtlesim::SetPen pen_srv;
  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  turtlesim::TeleportAbsolute srv;
  srv.request.x = offset-box_size/2;
  srv.request.y = offset-box_size/2;
  teleport_client.call(srv);

  for (int i = 1; i <= rand() % 4 + 1; i++)
  {

  x_size1 = rand() % 10 + 1;
  y_size1 = rand() % 5 + 1;
  pen_srv.request.off = false;
  pen_srv.request.width = penwidth;
  pen_srv.request.r = red;
  pen_srv.request.g = green;
  pen_srv.request.b = blue;
  pen_client.call(pen_srv);

  srv.request.x = x_size1-box_size/2;
  srv.request.y = y_size1+box_size/2;
  teleport_client.call(srv);
  }
  srv.request.x = 3-box_size/2;
  srv.request.y = 3+box_size/2;

  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  srv.request.x = x_size1;
  srv.request.y = y_size1;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 10;
  pen_srv.request.r = 255;
  pen_srv.request.g = 0;
  pen_srv.request.b = 0;
  pen_client.call(pen_srv);

  return 0;

  
 


}

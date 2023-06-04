#include <ros/ros.h>
#include <beginner_tutorials/NamedPoint.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub =
    n.advertise<beginner_tutorials::NamedPoint>("chatter", 1000);
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    beginner_tutorials::NamedPoint msg;

    msg.name = "Hello world";
    msg.point.x = 1;
    msg.point.y = 2;
    msg.point.z = 3;

    ROS_INFO_STREAM(msg);
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

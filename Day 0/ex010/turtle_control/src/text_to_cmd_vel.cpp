#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"


class subscribeAndPublish{
public:
  subscribeAndPublish(){
    speed_command_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
    sub = n.subscribe("cmd_text", 1000, &subscribeAndPublish::speedCommands, this);

  }
  void speedCommands(const std_msgs::String::ConstPtr& command) {
    geometry_msgs::Twist msg;
    if (command->data == "turn_right"){
        msg.linear.x = 0;
        msg.angular.z = -1.5;
      } else if (command->data == "turn_left"){
        msg.linear.x = 0;
        msg.angular.z = 1.5;
      }
      else if (command->data == "move_forward"){
        msg.linear.x = 1;
        msg.angular.z = 0;
      } else if (command->data == "move_backward"){
        msg.linear.x = -1;
        msg.angular.z = 0;
      }
      speed_command_pub.publish(msg);
  }
private:
  ros::NodeHandle n;
  ros::Publisher speed_command_pub;
  ros::Subscriber sub;
};



int main(int argc, char **argv)
{

  ros::init(argc, argv, "text_to_cmd_vel");

   subscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}

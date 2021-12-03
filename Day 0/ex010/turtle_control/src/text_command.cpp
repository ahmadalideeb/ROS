#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "text_command");

  ros::NodeHandle n;

  ros::Publisher cmd_text_pub = n.advertise<std_msgs::String>("cmd_text", 1000);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {

    std_msgs::String command;
    std::cout << "enter command" << '\n';
    getline(std::cin, command.data);

    if ((command.data != "turn_right") && (command.data != "turn_left") && (command.data != "move_forward") && (command.data != "move_backward"))
      ROS_WARN("Wrong Command");
    else
    {
      cmd_text_pub.publish(command);
    }

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}

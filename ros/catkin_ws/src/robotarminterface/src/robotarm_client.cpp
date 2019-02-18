#include "ros/ros.h"
#include <iostream>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>

#include "robotarminterface/ServoAction.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "servo_actionclient");

  if(argc != 2)
  {
    ROS_INFO("%d",argc);
    ROS_WARN("Usage: servo_actionclient <goal>");
    return 1;
  }

  actionlib::SimpleActionClient<robotarminterface::ServoAction> actionClient("servo_action", true);

  ROS_INFO("Waiting for servo action server to start.");
  actionClient.waitForServer();

  ROS_INFO("Servo action server available, sending goal.");

  robotarminterface::ServoGoal goal;
  goal.pulsewidth = static_cast<unsigned short>(atoi(argv[1]));
  ROS_INFO("Sending target pulsewidth: %d",goal.pulsewidth);
  actionClient.sendGoal(goal);

  return 0;
}
#include "highlevel.h"
#include "robotarminterface/lowlevel.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "highlevel");
  ROS_INFO("Starting Servo high level driver");

  highlevel highLevelDriver("highlevel");

  while(ros::ok())
  {
    ros::spin();
  }
  return 0;
}

void highlevel::mRobotarmCallback(const robotarminterface::robotarmConstPtr& aRobotarmMessage)
{
  ROS_INFO("Handling command, Position %d, Time %d", aRobotarmMessage->position, aRobotarmMessage->time);  
}
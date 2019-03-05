#include "highlevel.h"
#include "robotarminterface/lowlevel.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "highlevel");
  ROS_INFO("Starting Servo high level driver");

  highlevel lHighlevelDriver;

  ros::spin();

  return 0;
}

highlevel::highlevel()
{
  mSubscriber = mNodeHandler.subscribe("robotarm", 1000, &highlevel::robotarmCallback, this);
}

highlevel::~highlevel()
{
}

void highlevel::robotarmCallback(const robotarminterface::robotarmConstPtr& aRobotarmMessage)
{
  std::cout << "Callback" << std::endl;
  ROS_INFO("Handling command, Position %d, Time %d", aRobotarmMessage->position, aRobotarmMessage->time);
  mLowLevelDriver.moveServoToPos(aRobotarmMessage->servoId, aRobotarmMessage->position, aRobotarmMessage->time);
}
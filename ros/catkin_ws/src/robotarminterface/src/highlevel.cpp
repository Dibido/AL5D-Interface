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
  mSingleServoSubscriber = mNodeHandler.subscribe("singleServo", 1000, &highlevel::singleServoCallback, this);
}

highlevel::~highlevel()
{
}

void highlevel::singleServoCallback(const robotarminterface::singleServoConstPtr& aRobotarmMessage)
{
  std::cout << "Callback" << std::endl;
  ROS_INFO("Handling command, Position %d, Time %d", aRobotarmMessage->position, aRobotarmMessage->time);
  // mLowLevelDriver.moveServosToPos(aRobotarmMessage->servoId, aRobotarmMessage->position, aRobotarmMessage->time);
}
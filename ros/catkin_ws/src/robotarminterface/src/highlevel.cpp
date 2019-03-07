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
  mAllServoSubscriber = mNodeHandler.subscribe("allServo", 1000, &highlevel::allServoCallback, this);
  mArmPositionSubscriber = mNodeHandler.subscribe("armPosition", 1000, &highlevel::armPositionCallback, this);
}

highlevel::~highlevel()
{
}

void highlevel::singleServoCallback(const robotarminterface::singleServoConstPtr& aSingleServoMessage)
{
  ROS_INFO("Handling command, Position %d, Time %d", aSingleServoMessage->position, aSingleServoMessage->time);
  mLowLevelDriver.moveServoToPos(aSingleServoMessage->servoId, aSingleServoMessage->position, aSingleServoMessage->time);
}

void highlevel::allServoCallback(const robotarminterface::allServoConstPtr& aAllServoMessage)
{
  ROS_INFO("Handling allServo Command");
  std::vector<unsigned int> lPins;
  lPins.push_back(aAllServoMessage->Servo0.servoId);
  lPins.push_back(aAllServoMessage->Servo1.servoId);
  lPins.push_back(aAllServoMessage->Servo2.servoId);
  lPins.push_back(aAllServoMessage->Servo3.servoId);
  lPins.push_back(aAllServoMessage->Servo4.servoId);
  std::vector<unsigned int> lDegrees;
  lDegrees.push_back(aAllServoMessage->Servo0.position);
  lDegrees.push_back(aAllServoMessage->Servo1.position);
  lDegrees.push_back(aAllServoMessage->Servo2.position);
  lDegrees.push_back(aAllServoMessage->Servo3.position);
  lDegrees.push_back(aAllServoMessage->Servo4.position);
  unsigned int lMillis = aAllServoMessage->time;
  mLowLevelDriver.moveServosToPos(lPins, lDegrees, lMillis);
}

void highlevel::armPositionCallback(const robotarminterface::armPositionConstPtr& aArmPositionMessage)
{
  ROS_INFO("Handling armPosition command, position : %s, time : %d", aArmPositionMessage->positionName.c_str(), aArmPositionMessage->time);

}
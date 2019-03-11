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
  mStopSingleServoSubscriber = mNodeHandler.subscribe("stopSingleServo", 1000, &highlevel::stopSingleServoCallback, this);
  mAllServoSubscriber = mNodeHandler.subscribe("allServo", 1000, &highlevel::allServoCallback, this);
  mStopAllServoSubscriber = mNodeHandler.subscribe("stopAllServo", 1000, &highlevel::stopAllServoCallback, this);
  mArmPositionSubscriber = mNodeHandler.subscribe("armPosition", 1000, &highlevel::armPositionCallback, this);

  mInitializeTime = 3000;

  mParkPosition.servoIds = {0,1,2,3,4,5};
  mParkPosition.servoDegrees = {90, 130, 130, 30, 180, 90};
  mReadyPosition.servoIds = {0,1,2,3,4,5};
  mReadyPosition.servoDegrees = {90, 130, 110, 80, 0, 90};
  mStraightPosition.servoIds = {0,1,2,3,4,5};
  mStraightPosition.servoDegrees = {90, 90, 10, 90 ,90 ,90};

  initializeArm();
}

void highlevel::initializeArm()
{
  //Go to park
  mLowLevelDriver.moveServosToPos(mParkPosition.servoIds, mParkPosition.servoDegrees, mInitializeTime);
}

highlevel::~highlevel()
{
}

void highlevel::singleServoCallback(const robotarminterface::singleServoConstPtr& aSingleServoMessage)
{
  ROS_INFO("Handling command, Position %d, Time %d", aSingleServoMessage->position, aSingleServoMessage->time);
  std::vector<unsigned int> lPins;
  lPins.push_back(aSingleServoMessage->servoId);
  std::vector<unsigned int> lDegrees;
  lDegrees.push_back(aSingleServoMessage->position);
  unsigned int lMillis = aSingleServoMessage->time;
  mLowLevelDriver.moveServosToPos(lPins, lDegrees, lMillis);
}

void highlevel::stopSingleServoCallback(const robotarminterface::stopSingleServoConstPtr& aStopSingleServoMessage)
{
  ROS_INFO("Handling stop command, Id %d", aStopSingleServoMessage->servoId);
  std::vector<unsigned int> lPins;
  lPins.push_back(aStopSingleServoMessage->servoId);
  mLowLevelDriver.stopServos(lPins);
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
  lPins.push_back(aAllServoMessage->Servo5.servoId);
  std::vector<unsigned int> lDegrees;
  lDegrees.push_back(aAllServoMessage->Servo0.position);
  lDegrees.push_back(aAllServoMessage->Servo1.position);
  lDegrees.push_back(aAllServoMessage->Servo2.position);
  lDegrees.push_back(aAllServoMessage->Servo3.position);
  lDegrees.push_back(aAllServoMessage->Servo4.position);
  lDegrees.push_back(aAllServoMessage->Servo5.position);
  unsigned int lMillis = aAllServoMessage->time;
  mLowLevelDriver.moveServosToPos(lPins, lDegrees, lMillis);
}

void highlevel::stopAllServoCallback(const robotarminterface::stopAllServoConstPtr& aStopAllServoMessage)
{
  ROS_INFO("Handling stopAllServo Command");
  std::vector<unsigned int> lPins;
  lPins.push_back(aStopAllServoMessage->Servo0);
  lPins.push_back(aStopAllServoMessage->Servo1);
  lPins.push_back(aStopAllServoMessage->Servo2);
  lPins.push_back(aStopAllServoMessage->Servo3);
  lPins.push_back(aStopAllServoMessage->Servo4);
  lPins.push_back(aStopAllServoMessage->Servo5);
  mLowLevelDriver.stopServos(lPins);
}

void highlevel::armPositionCallback(const robotarminterface::armPositionConstPtr& aArmPositionMessage)
{
  ROS_INFO("Handling armPosition command, position : %s, time : %d", aArmPositionMessage->positionName.c_str(), aArmPositionMessage->time);
  if (aArmPositionMessage->positionName == "park")
  {
    mLowLevelDriver.moveServosToPos(mParkPosition.servoIds, mParkPosition.servoDegrees, aArmPositionMessage->time);
  }
  else if (aArmPositionMessage->positionName == "ready")
  {
    mLowLevelDriver.moveServosToPos(mReadyPosition.servoIds, mReadyPosition.servoDegrees, aArmPositionMessage->time);
  }
  else if (aArmPositionMessage->positionName == "straight")
  {
    mLowLevelDriver.moveServosToPos(mStraightPosition.servoIds, mStraightPosition.servoDegrees, aArmPositionMessage->time);
  }
}
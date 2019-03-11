/**
 * @file highlevel.h
 * @author dibran
 * @brief the high level driver for the robotarm
 * @version 0.1
 * @date 2019-02-18
 * @copyright Copyright (c) 2019
 */
#ifndef HIGHLEVEL_H_
#define HIGHLEVEL_H_

#include "ros/ros.h"

#include "robotarminterface/lowlevel.hpp"
#include "robotarminterface/singleServo.h"
#include "robotarminterface/stopSingleServo.h"
#include "robotarminterface/allServo.h"
#include "robotarminterface/stopAllServo.h"
#include "robotarminterface/armPosition.h"

#include <iostream>
#include <sstream>

struct robotarmPosition
{
  std::vector<unsigned int> servoIds;
  std::vector<unsigned int> servoDegrees;
};

class highlevel
{
protected:
  ros::NodeHandle mNodeHandler;
  lowlevel mLowLevelDriver;
  ros::Subscriber mSingleServoSubscriber;
  ros::Subscriber mStopSingleServoSubscriber;
  ros::Subscriber mAllServoSubscriber;
  ros::Subscriber mStopAllServoSubscriber;
  ros::Subscriber mArmPositionSubscriber;

  robotarmPosition mParkPosition;
  robotarmPosition mReadyPosition;
  robotarmPosition mStraightPosition;

public:
  
  highlevel();
  highlevel(unsigned int aBaudRate);
  virtual ~highlevel();

  void setBaudRate(unsigned int aBaudRate);

private:

  /**
   * @brief Time to take to go to the park position
   */
  unsigned int mInitializeTime;

  unsigned int mBaudRate;

  void singleServoCallback(const robotarminterface::singleServoConstPtr& aSingleServoMessage);
  void stopSingleServoCallback(const robotarminterface::stopSingleServoConstPtr& aStopSingleServoMessage);
  void allServoCallback(const robotarminterface::allServoConstPtr& aSingleServoMessage);
  void stopAllServoCallback(const robotarminterface::stopAllServoConstPtr& aStopAllServoMessage);
  void armPositionCallback(const robotarminterface::armPositionConstPtr& aSingleServoMessage);

  /**
   * @brief Initializes the arm
   */
  void initializeArm();

  void subscribeTopics();

  void initializeValues();

  
};

#endif
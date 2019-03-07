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
#include "robotarminterface/allServo.h"
#include "robotarminterface/armPosition.h"

#include <iostream>
#include <sstream>

class highlevel
{
protected:
  ros::NodeHandle mNodeHandler;
  lowlevel mLowLevelDriver;
  ros::Subscriber mSingleServoSubscriber;
  ros::Subscriber mAllServoSubscriber;
  ros::Subscriber mArmPositionSubscriber;

public:
  
  highlevel();
  virtual ~highlevel();

private:
  void singleServoCallback(const robotarminterface::singleServoConstPtr& aSingleServoMessage);
  void allServoCallback(const robotarminterface::allServoConstPtr& aSingleServoMessage);
  void armPositionCallback(const robotarminterface::armPositionConstPtr& aSingleServoMessage);
};

#endif
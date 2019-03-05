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
#include "robotarminterface/robotarm.h"

#include <iostream>
#include <sstream>

class highlevel
{
protected:
  ros::NodeHandle mNodeHandler;
  lowlevel mLowLevelDriver;
  ros::Subscriber mSubscriber; 

public:
  
  highlevel();

  virtual ~highlevel();

private:
  void robotarmCallback(const robotarminterface::robotarmConstPtr& aRobotarmMessage);
};

#endif
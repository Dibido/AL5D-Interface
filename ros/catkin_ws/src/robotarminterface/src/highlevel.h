/**
 * @file highlevel.h
 * @author your name (you@domain.com)
 * @brief the high level driver for the robotarm
 * @version 0.1
 * @date 2019-02-18
 * @copyright Copyright (c) 2019
 */

#ifndef HIGHLEVEL_H_
#define HIGHLEVEL_H_

#include "highlevel.h"
#include "ros/ros.h"
#include "std_msgs/UInt16.h"
#include <actionlib/server/simple_action_server.h>

#include "robotarminterface/ServoAction.h"
#include "robotarminterface/lowlevel.hpp"

#include <iostream>
#include <sstream>

class highlevel
{
protected:
  ros::NodeHandle nh;
  actionlib::SimpleActionServer<robotarminterface::ServoAction> actionServer;
  robotarminterface::ServoFeedback feedback;
  robotarminterface::ServoResult result;

  std::string action_name;
  unsigned short goal;
  lowlevel lowLevelDriver;

public:
  highlevel(std::string name)
  : actionServer(nh, name, boost::bind(&highlevel::executeCallback, this, _1), false),
    action_name(name)
  {
    actionServer.registerPreemptCallback(boost::bind(&highlevel::preemptCallback, this));
    actionServer.start();
  }
  ~highlevel(void)
  {
  }

  void executeCallback(const robotarminterface::ServoGoalConstPtr &goal);

  void preemptCallback();
};

#endif
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
#include "robotarminterface/moveServos.h"
#include "robotarminterface/stopServos.h"
#include "robotarminterface/armPosition.h"

#include <iostream>
#include <sstream>

/**
 * @brief Robotarmposition stores the current configuration of the robotarm
 * @param servoIds - The id's of the servo's
 * @param servoDegrees - The degrees that the servo's are in
 */
struct robotarmPosition
{
  std::vector<unsigned int> servoIds;
  std::vector<int> servoDegrees;
};

class highlevel
{
protected:
  ros::NodeHandle mNodeHandler;
  lowlevel mLowLevelDriver;
  ros::Subscriber mSingleServoSubscriber;
  ros::Subscriber mStopSingleServoSubscriber;
  ros::Subscriber mMoveServosSubscriber;
  ros::Subscriber mStopServosSubscriber;
  ros::Subscriber mArmPositionSubscriber;

  robotarmPosition mParkPosition;
  robotarmPosition mReadyPosition;
  robotarmPosition mStraightPosition;

public:
  
  highlevel();
  highlevel(unsigned int aBaudRate);
  virtual ~highlevel();

  /**
   * @brief Set the Baud Rate
   * @param aBaudRate - The baudrate to set
   */
  void setBaudRate(unsigned int aBaudRate);

private:

  /**
   * @brief Time to take to go to the park position
   */
  unsigned int mInitializeTime;
  /**
   * @brief The currently set baudrate
   */
  unsigned int mBaudRate;

  // Message callbacks
  void singleServoCallback(const robotarminterface::singleServoConstPtr& aSingleServoMessage);
  void stopSingleServoCallback(const robotarminterface::stopSingleServoConstPtr& aStopSingleServoMessage);
  void moveServosCallback(const robotarminterface::moveServosConstPtr& aSingleServoMessage);
  void stopServosCallback(const robotarminterface::stopServosConstPtr& aStopAllServoMessage);
  void armPositionCallback(const robotarminterface::armPositionConstPtr& aSingleServoMessage);

  /**
   * @brief Initializes the arm by going to the park position
   */
  void initializeArm();

  /**
   * @brief subscribes to the necessary topics
   */
  void subscribeTopics();

  /**
   * @brief Initializes the position and timing values
   */
  void initializeValues();
};

#endif
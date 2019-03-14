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
#include <ros/console.h>

#include "robotarminterface/lowlevel.hpp"
#include "robotarminterface/singleServo.h"
#include "robotarminterface/stopSingleServo.h"
#include "robotarminterface/moveServos.h"
#include "robotarminterface/stopServos.h"
#include "robotarminterface/armPosition.h"

#include <signal.h>

#include <iostream>
#include <sstream>
#include <chrono>

#define DEFAULT_BAUDRATE 115200

/**
 * @brief Robotarmposition stores the current configuration of the robotarm
 * @param servoIds - The id's of the servo's
 * @param servoDegrees - The degrees that the servo's are in
 * @param time - Defines period (in ms) it should take for the robot to move to the right position
 */
struct robotarmPosition
{
  std::vector<unsigned int> servoIds;
  std::vector<int> servoDegrees;
  uint32_t time;

  robotarmPosition() : time(0)
  {
  }

  robotarmPosition(const robotarmPosition& aRobotarmPosition) : servoIds(aRobotarmPosition.servoIds), servoDegrees(aRobotarmPosition.servoDegrees), time(aRobotarmPosition.time)
  {
  }
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
   * @brief Is used to catch ctrl-c event to kill the application
   */
  static void signalHandler(int aSignal);

  /**
   * @brief Set the Baud Rate
   * @param aBaudRate - The baudrate to set
   */
  void setBaudRate(unsigned int aBaudRate);

  /**
   * @brief Base function used to keep the highlevel active, is a blocking function all logic shud be handled within it.
   */
  void run();

private:
  
  /**
   * @brief False intitially, becomes true as soon as atleast one valid move command has been sent to the robot by serial
   */
  bool mMoveCommandSent;

  /**
   * @brief False initially, whether the system is in the ready state
   */
  bool mIsReady;

  /**
   * @brief False initially, should become true when the robot completed its first move to park position
   */
  bool mIsInitialized;

  // List of all servo ids
  std::vector<unsigned int> mServoIds;

  // Any move commands received by message get stored in this queue of commands
  std::vector<robotarmPosition> mMoveCommands;
  
  /**
   * @brief Time to take to go to the park position
   */
  unsigned int mInitializeTime;

  /**
   * @brief The currently set baudrate
   */
  unsigned int mBaudRate;

  /**
   * @brief Expected period of time to complete the last sent valid move. Is 0 until the first valid move is sent to the lowlevel.
   */
   uint32_t mLastMoveTimeMS;

  /**
   * @brief Start time of last sent valid move command.
   */
   std::chrono::high_resolution_clock::time_point mLastMoveStartTime;

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

  /**
   * @brief Checks if new commands from the mMoveCommands should be sent to the low level driver
   */
  void handleMoveCommands();
  
  /**
   * @brief Checks if the period needed to complete last sent valid move has expired
   */
  bool lastMovePeriodExpired() const;
};

#endif
#include "ros/ros.h"
#include <iostream>

#include "robotarminterface/singleServo.h"
#include "robotarminterface/stopSingleServo.h"
#include "robotarminterface/allServo.h"
#include "robotarminterface/stopAllServo.h"
#include "robotarminterface/armPosition.h"


int main(int argc, char** argv)
{
  ros::init(argc, argv, "servo_client");

  ros::NodeHandle lNodeHandler;
  ros::Publisher lSingleServoPublisher = lNodeHandler.advertise<robotarminterface::singleServo>("singleServo", 1000);
  ros::Publisher lStopSingleServoPublisher = lNodeHandler.advertise<robotarminterface::stopSingleServo>("stopSingleServo", 1000);
  ros::Publisher lAllServoPublisher = lNodeHandler.advertise<robotarminterface::allServo>("allServo", 1000);
  ros::Publisher lStopAllServoPublisher = lNodeHandler.advertise<robotarminterface::stopAllServo>("stopAllServo", 1000);
  ros::Publisher lArmPositionPublisher = lNodeHandler.advertise<robotarminterface::armPosition>("armPosition", 1000);

  if(ros::ok())
  {
    sleep(1);
    //Create message
    robotarminterface::singleServo lSingleServoMessage;
    lSingleServoMessage.servoId = 0;
    lSingleServoMessage.position = 0;
    lSingleServoMessage.time = 200;
    //Send message
    ROS_INFO("Sending ServoPos");
    lSingleServoPublisher.publish(lSingleServoMessage);
    ros::spinOnce();
    sleep(0.5);

    robotarminterface::allServo lAllServoMessage;
    robotarminterface::servoPosition lServoPosition;

    lServoPosition.servoId = 0;
    lServoPosition.position = 90;
    lAllServoMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 1;
    lServoPosition.position = 130;
    lAllServoMessage.servos.push_back(lServoPosition);
    
    lServoPosition.servoId = 2;
    lServoPosition.position = 110;
    lAllServoMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 3;
    lServoPosition.position = 80;
    lAllServoMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 4;
    lServoPosition.position = 180;
    lAllServoMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 5;
    lServoPosition.position = 90;
    lAllServoMessage.servos.push_back(lServoPosition);

    lAllServoMessage.time = 2000;
    ROS_INFO("Sending allServoPos");
    //Send message
    lAllServoPublisher.publish(lAllServoMessage);
    ros::spinOnce();
    sleep(5);

    robotarminterface::armPosition lArmPositionMessage;
    lArmPositionMessage.positionName = "park";
    lArmPositionMessage.time = 1000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();
    sleep(2);

    lArmPositionMessage.positionName = "ready";
    lArmPositionMessage.time = 1000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();
    sleep(2);

    lArmPositionMessage.positionName = "straight";
    lArmPositionMessage.time = 5000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();
    sleep(1);

    robotarminterface::stopAllServo lStopServosMessage;
    lStopServosMessage.Servo0 = 0;
    lStopServosMessage.Servo1 = 1;
    lStopServosMessage.Servo2 = 2;
    lStopServosMessage.Servo3 = 3;
    lStopServosMessage.Servo4 = 4;
    lStopServosMessage.Servo5 = 5;
    //Send message
    // lStopAllServoPublisher.publish(lStopServosMessage);
    ros::spinOnce();
    sleep(1);
  }
  else
  {
    ROS_ERROR("Ros core not ok");
  }
  return 0;
}
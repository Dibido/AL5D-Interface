#include "ros/ros.h"
#include <iostream>

#include "robotarminterface/singleServo.h"
#include "robotarminterface/allServo.h"
#include "robotarminterface/armPosition.h"


int main(int argc, char** argv)
{
  ros::init(argc, argv, "servo_client");

  ros::NodeHandle lNodeHandler;
  ros::Publisher lSingleServoPublisher = lNodeHandler.advertise<robotarminterface::singleServo>("singleServo", 1000);
  ros::Publisher lAllServoPublisher = lNodeHandler.advertise<robotarminterface::allServo>("allServo", 1000);
  ros::Publisher lArmPositionPublisher = lNodeHandler.advertise<robotarminterface::armPosition>("armPosition", 1000);

  if(ros::ok())
  {
    //Create message
    robotarminterface::singleServo lSingleServoMessage;
    lSingleServoMessage.servoId = 0;
    lSingleServoMessage.position = 90;
    lSingleServoMessage.time = 200;
    //Show command
    ROS_INFO("Sending data, ServoId : %d, Position : %d, Time : %d", lSingleServoMessage.servoId, lSingleServoMessage.position, lSingleServoMessage.time);
    while(lSingleServoPublisher.getNumSubscribers() == 0)
    {
      //Wait for subs
    }
    //Send message
    lSingleServoPublisher.publish(lSingleServoMessage);
    ros::spinOnce();
    sleep(5);

    robotarminterface::allServo lAllServoMessage;
    lAllServoMessage.Servo0.servoId = 0;
    lAllServoMessage.Servo0.position = 90;
    lAllServoMessage.Servo1.servoId = 1;
    lAllServoMessage.Servo1.position = 130;
    lAllServoMessage.Servo2.servoId = 2;
    lAllServoMessage.Servo2.position = 150;
    lAllServoMessage.Servo3.servoId = 3;
    lAllServoMessage.Servo3.position = 90;
    lAllServoMessage.Servo4.servoId = 4;
    lAllServoMessage.Servo4.position = 90;
    lAllServoMessage.time = 2000;
    ROS_INFO("Sending allServoPos");
    while(lAllServoPublisher.getNumSubscribers() == 0)
    {
      //Wait for subs
    }
    //Send message
    lAllServoPublisher.publish(lAllServoMessage);
    ros::spinOnce();
    sleep(5);

    robotarminterface::armPosition lArmPositionMessage;
    lArmPositionMessage.positionName = "park";
    lArmPositionMessage.time = 2000;
    ROS_INFO("Sending armPosition");
    while(lArmPositionPublisher.getNumSubscribers() == 0)
    {
      //Wait for subs
    }
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();
    sleep(5);
  }
  else
  {
    ROS_ERROR("Ros core not ok");
  }
  return 0;
}
#include "ros/ros.h"
#include <iostream>

#include "robotarminterface/singleServo.h"
#include "robotarminterface/stopSingleServo.h"
#include "robotarminterface/moveServos.h"
#include "robotarminterface/stopServos.h"
#include "robotarminterface/armPosition.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "servo_client");

  ros::NodeHandle lNodeHandler;
  ros::Publisher lSingleServoPublisher = lNodeHandler.advertise<robotarminterface::singleServo>("singleServo", 1000);
  ros::Publisher lStopSingleServoPublisher = lNodeHandler.advertise<robotarminterface::stopSingleServo>("stopSingleServo", 1000);
  ros::Publisher lMoveServosPublisher = lNodeHandler.advertise<robotarminterface::moveServos>("moveServos", 1000);
  ros::Publisher lStopServosPublisher = lNodeHandler.advertise<robotarminterface::stopServos>("stopServos", 1000);
  ros::Publisher lArmPositionPublisher = lNodeHandler.advertise<robotarminterface::armPosition>("armPosition", 1000);

  if (ros::ok())
  {
    robotarminterface::moveServos lMoveServosMessage;
    robotarminterface::servoPosition lServoPosition;

    // Park position, slightly different
    /*
    lServoPosition.servoId = 0;
    lServoPosition.position = 90;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 1;
    lServoPosition.position = 30;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 2;
    lServoPosition.position = 135;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 3;
    lServoPosition.position = -80;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 4;
    lServoPosition.position = 180;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 5;
    lServoPosition.position = 0;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lMoveServosMessage.time = 1000;
    ROS_INFO("Sending allServoPos");
    //Send message
    lMoveServosPublisher.publish(lMoveServosMessage);
    ros::spinOnce();
    */

    robotarminterface::armPosition lArmPositionMessage;
    lArmPositionMessage.positionName = "straight";
    lArmPositionMessage.time = 2000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();
    sleep(5);
   
    lArmPositionMessage.positionName = "ready";
    lArmPositionMessage.time = 2000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();
    sleep(1);

    lArmPositionMessage.positionName = "straight";
    lArmPositionMessage.time = 2000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();

    lArmPositionMessage.positionName = "stop";
    lArmPositionMessage.time = 2000;
    ROS_INFO("Sending stop");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();

    lArmPositionMessage.positionName = "ready";
    lArmPositionMessage.time = 2000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();

    lArmPositionMessage.positionName = "straight";
    lArmPositionMessage.time = 2000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();
    sleep(10);

    lArmPositionMessage.positionName = "release";
    lArmPositionMessage.time = 2000;
    ROS_INFO("Sending release");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();

    lArmPositionMessage.positionName = "park";
    lArmPositionMessage.time = 2000;
    ROS_INFO("Sending armPosition ready");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();
    sleep(2);

    lArmPositionMessage.positionName = "straight";
    lArmPositionMessage.time = 2000;
    ROS_INFO("Sending armPosition straight");
    //Send message
    lArmPositionPublisher.publish(lArmPositionMessage);
    ros::spinOnce();

    sleep(2);
    lArmPositionMessage.positionName = "shutdown";
    lArmPositionMessage.time = 20013403;
    lArmPositionPublisher.publish(lArmPositionMessage);

    robotarminterface::stopServos lStopServosMessage;
    lStopServosMessage.servoIds.push_back(0);
    lStopServosMessage.servoIds.push_back(1);
    lStopServosMessage.servoIds.push_back(2);
    //lStopServosMessage.servoIds.push_back(3);
    //lStopServosMessage.servoIds.push_back(4);
    //lStopServosMessage.servoIds.push_back(5);
    //Send message
    //lStopServosPublisher.publish(lStopServosMessage);
    ros::spinOnce();
    sleep(0.5);
  }
  else
  {
    ROS_ERROR("Ros core not ok");
  }
  return 0;
}
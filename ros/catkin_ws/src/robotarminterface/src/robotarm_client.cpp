#include "ros/ros.h"
#include <iostream>

#include "robotarminterface/singleServo.h"
#include "robotarminterface/stopSingleServo.h"
#include "robotarminterface/moveServos.h"
#include "robotarminterface/stopServos.h"
#include "robotarminterface/armInstruction.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "servo_client");

  ros::NodeHandle lNodeHandler;
  ros::Publisher lSingleServoPublisher = lNodeHandler.advertise<robotarminterface::singleServo>("singleServo", 1000);
  ros::Publisher lStopSingleServoPublisher = lNodeHandler.advertise<robotarminterface::stopSingleServo>("stopSingleServo", 1000);
  ros::Publisher lMoveServosPublisher = lNodeHandler.advertise<robotarminterface::moveServos>("moveServos", 1000);
  ros::Publisher lStopServosPublisher = lNodeHandler.advertise<robotarminterface::stopServos>("stopServos", 1000);
  ros::Publisher lArmInstructionPublisher = lNodeHandler.advertise<robotarminterface::armInstruction>("armInstructionPosition", 1000);

  if (ros::ok())
  {
    // Delay, as messages might not get accross right after starting
    sleep(2);

    robotarminterface::armInstruction lArmInstructionMessage;

    // Move to ready
    lArmInstructionMessage.instruction = "ready";
    lArmInstructionMessage.time = 2000;
    ROS_INFO("Sending armPosition ready");
    //Send message
    lArmInstructionPublisher.publish(lArmInstructionMessage);
    ros::spinOnce();
    sleep(3);

    // Move to straight
    lArmInstructionMessage.instruction = "straight";
    lArmInstructionMessage.time = 2000;
    ROS_INFO("Sending armPosition straight");
    //Send message
    lArmInstructionPublisher.publish(lArmInstructionMessage);
    ros::spinOnce();
    sleep(3);
  
    robotarminterface::moveServos lMoveServosMessage;
    robotarminterface::servoPosition lServoPosition;

    // Sequence of 3 different locations
    lServoPosition.servoId = 0;
    lServoPosition.position = 90;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 1;
    lServoPosition.position = 30;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 2;
    lServoPosition.position = 65;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 3;
    lServoPosition.position = -60;
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

    // Sequence of 3 different locations
    lServoPosition.servoId = 0;
    lServoPosition.position = -50;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 1;
    lServoPosition.position = 20;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 2;
    lServoPosition.position = 65;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 3;
    lServoPosition.position = -60;
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

    // Sequence of 3 different locations
    lServoPosition.servoId = 0;
    lServoPosition.position = 50;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 1;
    lServoPosition.position = 20;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 2;
    lServoPosition.position = 90;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 3;
    lServoPosition.position = -60;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 4;
    lServoPosition.position = 0;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lServoPosition.servoId = 5;
    lServoPosition.position = 0;
    lMoveServosMessage.servos.push_back(lServoPosition);

    lMoveServosMessage.time = 1000;
    ROS_INFO("Sending allServoPos");

    //Send message
    lMoveServosPublisher.publish(lMoveServosMessage);
    ros::spinOnce();

    // Go to ready
    lArmInstructionMessage.instruction = "ready";
    lArmInstructionMessage.time = 2000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmInstructionPublisher.publish(lArmInstructionMessage);
    ros::spinOnce();
    sleep(10);

    // Move slowly towards straight
    lArmInstructionMessage.instruction = "straight";
    lArmInstructionMessage.time = 5000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmInstructionPublisher.publish(lArmInstructionMessage);
    ros::spinOnce();
    sleep(2.5);
 
    // Send stop command, so robot stops halfway~ during its transition to straight
    lArmInstructionMessage.instruction = "stop";
    lArmInstructionMessage.time = 5000;
    ROS_INFO("Sending STOP!");
    //Send message
    lArmInstructionPublisher.publish(lArmInstructionMessage);
    ros::spinOnce();
    sleep(3);

    // Sending 2 move commands, which will be ignored because the robot got stopped and needs to be released first
    lArmInstructionMessage.instruction = "ready";
    lArmInstructionMessage.time = 2000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmInstructionPublisher.publish(lArmInstructionMessage);
    ros::spinOnce();
    sleep(2);

    lArmInstructionMessage.instruction = "straight";
    lArmInstructionMessage.time = 2000;
    ROS_INFO("Sending armPosition");
    //Send message
    lArmInstructionPublisher.publish(lArmInstructionMessage);
    ros::spinOnce();
    sleep(2);

    // Now unlocking the robot again
    lArmInstructionMessage.instruction = "release";
    lArmInstructionMessage.time = 2000;
    ROS_INFO("Sending release");
    //Send message
    lArmInstructionPublisher.publish(lArmInstructionMessage);
    ros::spinOnce();

    lArmInstructionMessage.instruction = "shutdown";
    lArmInstructionMessage.time = 3000;
    ROS_INFO("Sending shutdown");
    lArmInstructionPublisher.publish(lArmInstructionMessage);
    ros::spinOnce();
    sleep(1);
  }
  else
  {
    ROS_ERROR("Ros core not ok");
  }
  return 0;
}
#include "ros/ros.h"
#include <iostream>

#include "robotarminterface/robotarm.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "servo_client");

  ros::NodeHandle lNodeHandler;
  ros::Publisher lRobotarmPublisher = lNodeHandler.advertise<robotarminterface::robotarm>("robotarm", 1000);

  if(argc != 4)
  {
    ROS_WARN("Usage: servo_actionclient [servoId] [position] [time]");
    return 1;
  }
  else
  {
    if(ros::ok())
    {
      //Create message
      robotarminterface::robotarm lMessage;
      lMessage.servoId = atoi(argv[1]);
      lMessage.position = atoi(argv[2]);
      lMessage.time = atoi(argv[3]);
      //Show command
      ROS_INFO("Sending data, ServoId : %d, Position : %d, Time : %d", lMessage.servoId, lMessage.position, lMessage.time);
      while(lRobotarmPublisher.getNumSubscribers() == 0)
      {
        //Wait for subs
      }
      //Send message
      lRobotarmPublisher.publish(lMessage);
      ros::spinOnce();
      sleep(1);
    }
    else
    {
      ROS_ERROR("Ros core not ok");
    }
    
  }
  return 0;
}
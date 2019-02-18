#include "highlevel.h"
#include "robotarminterface/lowlevel.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "servo_action");
  ROS_INFO("Starting Servo Action Server");
  highlevel servo_action_obj(ros::this_node::getName());
  ros::spin();
  return 0;
}

void highlevel::preemptCallback()
{
  ROS_WARN("%s got preempted!", action_name.c_str());
  // result.pulsewidth = servo.getPulseWidth();
  actionServer.setPreempted(result,"I got Preempted");
}

void highlevel::executeCallback(const robotarminterface::ServoGoalConstPtr &goal)
{
  if(!actionServer.isActive() || actionServer.isPreemptRequested())
  {
    return;
  }
  ros::Rate rate(5);
  ROS_INFO("%s is processing the goal %d", action_name.c_str(), goal->pulsewidth);
  while(true){
    if(!ros::ok())
    {
      // result.pulsewidth = servo.getPulseWidth();
      actionServer.setAborted(result,"Aborted");
      ROS_INFO("%s Shutting down",action_name.c_str());
      break;
    }

    if(!actionServer.isActive() || actionServer.isPreemptRequested())
    {
      return;
    }

    // unsigned short currentPW = servo.getPulseWidth();
    if(true)//goal->pulsewidth == currentPW)
    {
      ROS_INFO("%s reached goal %d", action_name.c_str(), goal->pulsewidth);
      actionServer.setSucceeded(result);
    } 
    else
    {
      // servo.setTargetPW(goal->pulsewidth);
      // feedback.pulsewidth = currentPW;
      ROS_INFO("Servo-value %d / %d",feedback.pulsewidth,goal->pulsewidth);
      actionServer.publishFeedback(feedback);
    }
    rate.sleep();
  }
}
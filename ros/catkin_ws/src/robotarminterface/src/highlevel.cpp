#include "highlevel.h"
#include "robotarminterface/lowlevel.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "highlevel");
  ROS_INFO("Starting Servo high level driver");
  highlevel lHighlevelDriver;
  if (argc == 1)
  {
    // Default baudrate, if none is given by user
    lHighlevelDriver.setBaudRate(DEFAULT_BAUDRATE);
  }
  else if (argc == 2)
  {
    lHighlevelDriver.setBaudRate(atoi(argv[1]));
  }
  else
  {
    std::cout << "Usage : higleveldriver [baudrate]" << std::endl;
    exit(0);
  }

  lHighlevelDriver.run();

  return 0;
}

highlevel::highlevel() : mBaudRate(DEFAULT_BAUDRATE), mLastMoveTimeMS(0), mLastMoveStartTime(std::chrono::high_resolution_clock::now())
{
  subscribeTopics();
  initializeValues();
  initializeArm();
}

highlevel::highlevel(unsigned int aBaudRate) : mBaudRate(aBaudRate), mLastMoveTimeMS(0), mLastMoveStartTime(std::chrono::high_resolution_clock::now())
{
  subscribeTopics();
  initializeValues();
  initializeArm();
}

void highlevel::setBaudRate(unsigned int aBaudRate)
{
  mLowLevelDriver.setBaudRate(aBaudRate);
}

void highlevel::subscribeTopics()
{
  mSingleServoSubscriber = mNodeHandler.subscribe("singleServo", 1000, &highlevel::singleServoCallback, this);
  mStopSingleServoSubscriber = mNodeHandler.subscribe("stopSingleServo", 1000, &highlevel::stopSingleServoCallback, this);
  mMoveServosSubscriber = mNodeHandler.subscribe("moveServos", 1000, &highlevel::moveServosCallback, this);
  mStopServosSubscriber = mNodeHandler.subscribe("stopServos", 1000, &highlevel::stopServosCallback, this);
  mArmPositionSubscriber = mNodeHandler.subscribe("armPosition", 1000, &highlevel::armPositionCallback, this);
}

void highlevel::initializeValues()
{
  mInitializeTime = 3000;

  // robot 6
  mParkPosition.servoIds = {0, 1, 2, 3, 4, 5};
  mParkPosition.servoDegrees = {0, 30, 135, -80, 180, 0};
  mReadyPosition.servoIds = {0, 1, 2, 3, 4, 5};
  mReadyPosition.servoDegrees = {0, 30, 120, -20, 0, 0};
  mStraightPosition.servoIds = {0, 1, 2, 3, 4, 5};
  mStraightPosition.servoDegrees = {0, 0, 30, 0, 0, 0};

  mLowLevelDriver.setBaudRate(mBaudRate);
}

void highlevel::initializeArm()
{
  //Go to park
  mLowLevelDriver.moveServosToPos(mParkPosition.servoIds, mParkPosition.servoDegrees, mInitializeTime);
}

highlevel::~highlevel()
{
}

void highlevel::singleServoCallback(const robotarminterface::singleServoConstPtr &aSingleServoMessage)
{
  ROS_INFO("Handling command, Position %d, Time %d", aSingleServoMessage->position, aSingleServoMessage->time);
  std::vector<unsigned int> lPins;
  lPins.push_back(aSingleServoMessage->servoId);
  std::vector<int> lDegrees;
  lDegrees.push_back(aSingleServoMessage->position);
  unsigned int lMillis = aSingleServoMessage->time;
  mLowLevelDriver.moveServosToPos(lPins, lDegrees, lMillis);
}

void highlevel::stopSingleServoCallback(const robotarminterface::stopSingleServoConstPtr &aStopSingleServoMessage)
{
  ROS_INFO("Handling stop command, Id %d", aStopSingleServoMessage->servoId);
  std::vector<unsigned int> lPins;
  lPins.push_back(aStopSingleServoMessage->servoId);
  mLowLevelDriver.stopServos(lPins);
}

void highlevel::moveServosCallback(const robotarminterface::moveServosConstPtr &aMoveServosMessage)
{
  ROS_INFO("Handling moveServos Command");

  robotarmPosition lMoveCommand;

  for (int i = 0; i < aMoveServosMessage->servos.size(); ++i)
  {
    lMoveCommand.servoIds.push_back(aMoveServosMessage->servos[i].servoId);
    lMoveCommand.servoDegrees.push_back(aMoveServosMessage->servos[i].position);
  }

  lMoveCommand.time = aMoveServosMessage->time;

  mMoveCommands.push_back(lMoveCommand);
}

void highlevel::stopServosCallback(const robotarminterface::stopServosConstPtr &aStopServosMessage)
{
  ROS_INFO("Handling stopServos Command");
  mLowLevelDriver.stopServos(aStopServosMessage->servoIds);

  // TO-DO: only clear move commands if ALL servos are stopped (seperate message?)
  mMoveCommands.clear();
}

void highlevel::armPositionCallback(const robotarminterface::armPositionConstPtr &aArmPositionMessage)
{
  ROS_INFO("Handling armPosition command, position : %s, time : %d", aArmPositionMessage->positionName.c_str(), aArmPositionMessage->time);
  if (aArmPositionMessage->positionName == "park")
  {
    mLowLevelDriver.moveServosToPos(mParkPosition.servoIds, mParkPosition.servoDegrees, aArmPositionMessage->time);
  }
  else if (aArmPositionMessage->positionName == "ready")
  {
    mLowLevelDriver.moveServosToPos(mReadyPosition.servoIds, mReadyPosition.servoDegrees, aArmPositionMessage->time);
  }
  else if (aArmPositionMessage->positionName == "straight")
  {
    mLowLevelDriver.moveServosToPos(mStraightPosition.servoIds, mStraightPosition.servoDegrees, aArmPositionMessage->time);
  }
}

void highlevel::run()
{
  while (true)
  {
    ros::spinOnce();
    handleMoveCommands();
  }
}

void highlevel::handleMoveCommands()
{
  // Last move had time to be excuted and there are remainig move commands in queue:
  if (lastMovePeriodExpired() && mMoveCommands.size() > 0)
  {
    // Select first command
    robotarmPosition lNewMoveCommand = mMoveCommands.at(0);

    // Send move command to lowlevel
    bool lValidMove = mLowLevelDriver.moveServosToPos(lNewMoveCommand.servoIds, lNewMoveCommand.servoDegrees, lNewMoveCommand.time);

    // If the command was valid and thus sent to the robot
    if (lValidMove)
    {
      // Remove the command from the list
      mMoveCommands.erase(mMoveCommands.begin());

      // Update times
      mLastMoveStartTime = std::chrono::high_resolution_clock::now();
      mLastMoveTimeMS = lNewMoveCommand.time;
    }
  }
}

bool highlevel::lastMovePeriodExpired() const
{
  auto lTime = std::chrono::high_resolution_clock::now();

  if (std::chrono::duration_cast<std::chrono::milliseconds>(lTime - mLastMoveStartTime).count() > mLastMoveTimeMS)
  {
    return true;
  }

  return false;
}
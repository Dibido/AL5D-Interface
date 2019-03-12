#include "Servo.h"

Servo::Servo(unsigned int aServoId, int aMinDegrees, int aMaxDegrees) : mServoId(aServoId), mMinDegrees(aMinDegrees), mMaxDegrees(aMaxDegrees)
{
}

Servo::~Servo()
{
}

unsigned int Servo::getServoId()
{
  return mServoId;
}

int Servo::getMinDegrees()
{
  return mMinDegrees;
}

int Servo::getMaxDegrees()
{
  return mMaxDegrees;
}
int Servo::getCurrentDegrees()
{
  return mCurrentDegrees;
}
void Servo::setCurrentDegrees(int aDegrees)
{
  mCurrentDegrees = aDegrees;
}
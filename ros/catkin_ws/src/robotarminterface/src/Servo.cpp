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

int Servo::getMinDegrees() const
{
  return mMinDegrees;
}

int Servo::getMaxDegrees() const
{
  return mMaxDegrees;
}
int Servo::getCurrentDegrees() const
{
  return mCurrentDegrees;
}
void Servo::setCurrentDegrees(int aDegrees)
{
  mCurrentDegrees = aDegrees;
}
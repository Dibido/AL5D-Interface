#include "Servo.h"

Servo::Servo(unsigned int aServoId, int aMinDegrees, int aMaxDegrees) : mServoId(aServoId), mMinDegrees(aMinDegrees), mMaxDegrees(aMaxDegrees)
{
}

Servo::~Servo()
{
}

unsigned int Servo::getServoId() const
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

Servo::Servo(const Servo& aOther)
{
  mServoId = aOther.getServoId();
  mMinDegrees = aOther.getMinDegrees();
  mMaxDegrees = aOther.getMaxDegrees();
  mCurrentDegrees = aOther.getCurrentDegrees();
}

Servo::Servo()
{
}

Servo& Servo::operator=(Servo aOther)
{
  if(aOther == *this)
  {
    return *this;
  }
  this->mServoId = aOther.getServoId();
  this->mMinDegrees = aOther.getMinDegrees();
  this->mMaxDegrees = aOther.getMaxDegrees();
  this->mCurrentDegrees = aOther.getCurrentDegrees();
  return *this;
}

bool Servo::operator==(Servo aServo)
{
  return (this->mServoId == aServo.mServoId && this->mMinDegrees == aServo.mMinDegrees && this->mMaxDegrees == aServo.mMaxDegrees && this->mCurrentDegrees == aServo.mCurrentDegrees);
}
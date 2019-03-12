#include "Servo.h"

Servo::Servo(unsigned int aServoId, int aMinDegrees, int aMaxDegrees, int aMinDegreesRange, int aMaxDegreesRange)
  : mServoId(aServoId), mMinDegrees(aMinDegrees), mMaxDegrees(aMaxDegrees), mMinDegreesRange(aMinDegreesRange), mMaxDegreesRange(aMaxDegreesRange)
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

int Servo::getMinDegreesRange() const
{
  return mMinDegreesRange;
}
    
int Servo::getMaxDegreesRange() const
{
  return mMaxDegreesRange;
}

int Servo::getCurrentDegrees() const
{
  return mCurrentDegrees;
}
void Servo::setCurrentDegrees(int aDegrees)
{
  mCurrentDegrees = aDegrees;
}

Servo::Servo(const Servo& other)
{
  mServoId = other.getServoId();
  mMinDegrees = other.getMinDegrees();
  mMaxDegrees = other.getMaxDegrees();
  mMinDegreesRange = other.getMinDegreesRange();
  mMaxDegreesRange = other.getMaxDegreesRange();
  mCurrentDegrees = other.getCurrentDegrees();
}

Servo::Servo()
{
}

Servo& Servo::operator=(Servo other)
{
  if(other == *this)
  {
    return *this;
  }
  this->mServoId = other.getServoId();
  this->mMinDegrees = other.getMinDegrees();
  this->mMaxDegrees = other.getMaxDegrees();
  this->mMinDegreesRange = other.getMinDegreesRange();
  this->mMaxDegreesRange = other.getMaxDegreesRange();
  this->mCurrentDegrees = other.getCurrentDegrees();
  return *this;
}

bool Servo::operator==(Servo aServo)
{
  return (this->mServoId == aServo.mServoId && this->mMinDegrees == aServo.mMinDegrees && this->mMaxDegrees == aServo.mMaxDegrees && this->mCurrentDegrees == aServo.mCurrentDegrees);
}
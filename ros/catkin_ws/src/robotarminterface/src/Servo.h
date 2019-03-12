#ifndef SERVO_H_
#define SERVO_H_

class Servo
{
  public:
    Servo(unsigned int aServoId, int aMinDegrees, int aMaxDegrees);
    virtual ~Servo();

    unsigned int getServoId();
    int getMinDegrees();
    int getMaxDegrees();
    int getCurrentDegrees();
    void setCurrentDegrees(int aDegrees);

  private:
    unsigned int mServoId;
    int mMinDegrees;
    int mMaxDegrees;
    int mCurrentDegrees;
};

#endif
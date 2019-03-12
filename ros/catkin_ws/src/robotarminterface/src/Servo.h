#ifndef SERVO_H_
#define SERVO_H_

class Servo
{
  public:
    Servo(unsigned int aServoId, int aMinDegrees, int aMaxDegrees);
    Servo();
    virtual ~Servo();

    unsigned int getServoId() const;
    int getMinDegrees() const;
    int getMaxDegrees() const;
    int getCurrentDegrees() const;
    void setCurrentDegrees(int aDegrees);

    Servo(const Servo& aOther); // Copy constructor
    Servo& operator=(Servo aOther); // Asignment constructor
    bool operator==(Servo aServo); // Comparison constructor

  private:
    unsigned int mServoId;
    int mMinDegrees;
    int mMaxDegrees;
    int mCurrentDegrees;
};

#endif
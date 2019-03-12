#ifndef SERVO_H_
#define SERVO_H_

class Servo
{
  public:
    Servo(unsigned int aServoId, int aMinDegrees, int aMaxDegrees, int aMinDegreesRange, int aMaxDegreesRange);
    Servo();
    virtual ~Servo();

    unsigned int getServoId() const;
    int getMinDegrees() const;
    int getMaxDegrees() const;
    int getMinDegreesRange() const;
    int getMaxDegreesRange() const;
    int getCurrentDegrees() const;
    void setCurrentDegrees(int aDegrees);

    Servo(const Servo& other); // Copy constructor
    Servo& operator=(Servo other); // Asignment constructor
    bool operator==(Servo aServo); // Comparison constructor

  private:
    unsigned int mServoId;
    int mMinDegrees;
    int mMaxDegrees;
    int mMinDegreesRange;
    int mMaxDegreesRange;
    int mCurrentDegrees;
};

#endif
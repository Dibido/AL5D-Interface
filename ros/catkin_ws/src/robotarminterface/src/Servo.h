#ifndef SERVO_H_
#define SERVO_H_

class Servo
{
  public:
    Servo(unsigned int aServoId, int aMinDegreesLimit, int aMaxDegreesLimit, int aMinDegreesRange, int aMaxDegreesRange);
    Servo();
    virtual ~Servo();

    unsigned int getServoId() const;

    /**
     * @brief Get the min degree limit
     * @return The lower bound of the allowed range
     */
    int getMinDegreesLimit() const;

    /**
     * @brief Get the max degrees limit
     * @return The upper bound of the allowed range
     */
    int getMaxDegreesLimit() const;

    /**
     * @brief Get the min degrees range
     * @return The lower bound of the total range supported by hardware
     */
    int getMinDegreesRange() const;

    /**
     * @brief Get the max degrees range
     * @return The upper bound of the total range supported by hardware
     */
    int getMaxDegreesRange() const;

    /**
     * @brief Get the current degrees, that is the amount of degrees which was last sent as a command to the servo.
     * @return The amount of degrees
     */
    int getCurrentDegrees() const;

    /**
     * @brief Sets the current degrees, is usually called when a move instruction is sent via serial to the servo.
     */
    void setCurrentDegrees(int aDegrees);

    Servo(const Servo& aOther); // Copy constructor
    Servo& operator=(Servo aOther); // Asignment constructor
    bool operator==(Servo aServo); // Comparison constructor

  private:
    unsigned int mServoId;

    // Min/Max degrees limit are the limits defined in software here
    int mMinDegreesLimit;
    int mMaxDegreesLimit;

    // Min/Max degrees range are the limits of the range supported by the hardware
    int mMinDegreesRange;
    int mMaxDegreesRange;
    
    int mCurrentDegrees;
};

#endif
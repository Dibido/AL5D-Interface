/**
 * @file lowlevel.hpp
 * @author your name (you@domain.com)
 * @brief lowlevel interface
 * @version 0.1
 * @date 2019-02-18
 */
#ifndef LOWLEVEL_H_
#define LOWLEVEL_H_

#include <iostream>
#include <vector>
#include <thread>

#include <boost/asio.hpp>

// Min and max move time in milliseconds
#define MIN_MOVE_TIME 100
#define MAX_MOVE_TIME 65535

// The pulsewidth range accepted by the hardware
#define MIN_PULSEWIDTH 500
#define MAX_PULSEWIDTH 2500

class lowlevel
{
  public:

  lowlevel();
  virtual ~lowlevel();

  protected:

  boost::asio::io_service ioservice;
  boost::asio::serial_port serial;

  public:

  inline int addNumbers(int a, int b)
  {
    return a + b;
  }

  /**
   * @brief Sends the command to move a servo to a certain angle in a certain amount if time.
   * @param aPin - The pin number of the servo
   * @param aDegrees - The angle in degrees
   * @param aMillis - The time in milliseconds that will be taken to complete the move
   * (if lower then MIN_MOVE_TIME, MIN_MOVE_TIME is used), same goes for MAX_MOVE_TIME.
   */
  void moveServosToPos(std::vector<unsigned int> aPins, std::vector<unsigned int> aDegrees, unsigned int aMillis);

  /**
   * @brief Converts a given amount of degrees to a corresponding pulsewidth. Uses the MIN/MAX_PULSEWIDTH defines for this.
   * @param aDegrees - The angle in degrees 
   */
  unsigned int convertDegreesToPulsewidth(unsigned int aDegrees) const;

  /**
   * @brief stop the movement of the servos
   * @param aPins  - The pins of the servos
   */
  void stopServos(std::vector<unsigned int> aPins);
  
  /**
   * @brief Sends a command over serial
   * @param aCommand - The command
   */
  void sendSerial(std::string aCommand);

  /**
   * @brief Set the baud rate of the serial
   * @param aBaudRate - The baudrate to set
   */
  void setBaudRate(unsigned int aBaudRate);

  /**
   * @brief Checks the servo range and sets the value to max or min when it exceeds the threshold
   * @param aPin The servo to check
   * @param aDegree The given degree
   */
  int checkServoRange(unsigned int aPin, int aDegree);

  private:

  class Servo {
    public:
      Servo(unsigned int aServoId, int aMinDegree, int aMaxDegree) : mServoId(aServoId), mMinDegree(aMinDegree), mMaxDegree(aMaxDegree) {}
      unsigned int mServoId;
      int mMinDegree;
      int mMaxDegree;
      int mCurrentDegree;
  };

  std::vector<Servo> mServos;
};

#endif
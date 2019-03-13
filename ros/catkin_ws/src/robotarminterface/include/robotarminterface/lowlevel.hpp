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
#include <stdexcept>

#include <boost/asio.hpp>

#include "../src/Servo.h"

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
  /**
   * @brief Sends the command to move a servo to a certain angle in a certain amount if time.
   * @param aPin - The pin number of the servo
   * @param aDegrees - The angle in degrees
   * @param aMillis - The time in milliseconds that will be taken to complete the move
   * (if lower then MIN_MOVE_TIME, MIN_MOVE_TIME is used), same goes for MAX_MOVE_TIME.
   */
  bool moveServosToPos(std::vector<unsigned int> aPins, std::vector<int> aDegrees, unsigned int aMillis);

  /**
   * @brief Converts a given amount of degrees to a corresponding pulsewidth. Uses the MIN/MAX_PULSEWIDTH defines for this.
   * @param aDegrees - The angle in degrees 
   * @param aServo - The servo, is used to check boundaries (min/max range).
   */
  unsigned int convertDegreesToPulsewidth(int aDegrees, Servo& aServo) const;

  /**
   * @brief Checks whether a given amount of degrees is in range
   * @param aDegrees - The given amount of degrees
   * @param aServo - The servo object, which contains a min/max
   * @return Returns true if min <= aDegrees <= max
   */
  bool degreesInRange(int aDegrees, Servo& aServo) const;
  
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
   * @brief Checks whether a servo with given servoId/pin exists
   * @param aPin - The given servoId
   * @return Returns true if there exists a servo in mServos with the given id, returns false otherwise
   */
  bool servoExists(unsigned int aServoId) const;


  /**
   * @brief Get the servo from mServos corresponding with given servo id
   * @param aServoId - The given servo id
   * @return - A pair, a boolean indicating whether a servo with given id existed in mServos or not.
   * If it existed, a copy of that servo is returned. If it didn't exist the boolean will be false, and a default
   * Servo is constructed and returned
   */
   Servo& getServoWithId(unsigned int aServoId);

  private:
  /**
   * @brief A list of servo objects
   */
  std::vector<Servo> mServos;

  /**
   * @brief Maps the value from the input range to the output range
   * @param aDegree - The value to convert
   * @param aInMin - The minimum value of the input range
   * @param aInMax - The maximum value of the input range 
   * @param aOutMin - The minimum value of the output range
   * @param aOutMax - The maximum value of the output range 
   * @return unsigned int - The converted value
   */
  unsigned int mapValues(int aDegree, int aInMin, int aInMax, int aOutMin, int aOutMax) const;
};

#endif
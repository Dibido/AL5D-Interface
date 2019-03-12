#include "robotarminterface/lowlevel.hpp"

lowlevel::lowlevel() : serial(ioservice)
{
  // Set the servo ranges
  mServos.push_back(Servo(0, -90, 90));
  mServos.push_back(Servo(1, -30, 90));
  mServos.push_back(Servo(2, 0, 135));
  mServos.push_back(Servo(3, -90, 90));
  mServos.push_back(Servo(4, 0, 180));
  mServos.push_back(Servo(5, -90, 90));
  // Initializing serial
  boost::system::error_code ec; // choice: without ec Boost.Asio may throw
  serial.open("/dev/ttyUSB0", ec);

  if (!ec)
  {
    serial.set_option(boost::asio::serial_port_base::baud_rate(115200));
    serial.set_option(boost::asio::serial_port::flow_control(boost::asio::serial_port::flow_control::none));
    serial.set_option(boost::asio::serial_port::parity(boost::asio::serial_port::parity::none));
    serial.set_option(boost::asio::serial_port::stop_bits(boost::asio::serial_port::stop_bits::one));
    serial.set_option(boost::asio::serial_port::character_size(boost::asio::serial_port::character_size(8)));
  }
}

lowlevel::~lowlevel()
{
}

void lowlevel::setBaudRate(unsigned int aBaudRate)
{
  boost::system::error_code ec; // without ec Boost.Asio may throw
  if (!ec)
  {
    serial.set_option(boost::asio::serial_port_base::baud_rate(aBaudRate));
  }
}

void lowlevel::moveServosToPos(std::vector<unsigned int> aPins, std::vector<int> aDegrees, unsigned int aMillis)
{
  // Every pin should correspond with a degree value, if this is not the case do nothing (input invalid)
  if (aPins.size() == aDegrees.size())
  {
    bool lValidPins = true;

    // Check if given pins exist
    for (int servoId : aPins)
    {
      if (!servoExists(servoId))
      {
        lValidPins = false;
      }
    }

    if (!lValidPins)
    {
      // The given pins are not valid, do nothing
      std::cout << "Given pins in moveServosToPos are not valid, ignoring command" << std::endl;
    }
    else // If pins are valid
    {

      bool lValidDegrees = true;

      // Check if given degrees are within the min/max of the servos
      for (int i = 0; (i < aDegrees.size()) && lValidDegrees; ++i)
      {
        if (!degreesInRange(aDegrees.at(i), getServoWithId(aPins.at(i))))
        {
          lValidDegrees = false;
          std::cout << "Degree: " << std::to_string(aDegrees.at(i)) << " and servomin: " << std::to_string(getServoWithId(aPins.at(i)).getMinDegrees()) << " and servomax: " << std::to_string(getServoWithId(aPins.at(i)).getMaxDegrees()) << std::endl;
        }
      }

      if (!lValidDegrees)
      {
        // The given degrees are not within the servos range, do nothing
        std::cout << "Not all of the given degrees in moveServosToPos are within the range of the corresponding servos, ignoring command" << std::endl;
      }
      else // Given degrees are valid, continue with procedure
      {
        std::string lCommand = "";

        for (int i = 0; i < aPins.size(); ++i)
        {
          unsigned int lPulseWidth = convertDegreesToPulsewidth(aDegrees.at(i), getServoWithId(aPins.at(i)));

          lCommand.append("#" + std::to_string(aPins.at(i)));
          lCommand.append("P" + std::to_string(lPulseWidth));
        }

        lCommand.append("T" + std::to_string(aMillis));
        lCommand.append("\r");

        std::cout << "Command sent via serial: " << lCommand << std::endl;
        sendSerial(lCommand);
      }
    }
  }
  else
  {
    std::cout << "Error, moveServosToPos invalid command received: Amount of pins does not match amount of degrees " << std::endl;
  }
}

void lowlevel::stopServos(std::vector<unsigned int> aPins)
{
  if (aPins.size() > 0)
  {
    std::string lCommand = "";

    for (int i = 0; i < aPins.size(); ++i) 
    {
      lCommand.append("STOP" + std::to_string(aPins.at(i)));
      lCommand.append("\r");
    }
    std::cout << "sendStop sent via serial: " << lCommand << std::endl;
    sendSerial(lCommand);
  }
}

unsigned int lowlevel::convertDegreesToPulsewidth(int aDegrees, Servo& aServo) const
{
  unsigned int lPulseRange = MAX_PULSEWIDTH - MIN_PULSEWIDTH;

  // Degree range of the servo's
  unsigned int lDegreeRange = 180;
  // std::abs(aServo.getMaxDegrees() - aServo.getMinDegrees());

  double lFactor = (double)(aDegrees) / (double)lDegreeRange;
     std::cout << "lFactor: " << std::to_string(lFactor) << std::endl;

  unsigned int lReturn = MIN_PULSEWIDTH + lPulseRange * lFactor;

  return lReturn;
}

bool lowlevel::degreesInRange(int aDegrees, Servo& aServo) const
{
  bool lReturn = false;

  if ((aDegrees >= aServo.getMinDegrees()) && (aDegrees <= aServo.getMaxDegrees()))
  {
    lReturn = true;
  }

  return lReturn;
}

void lowlevel::sendSerial(std::string aCommand)
{
  boost::asio::streambuf b;
  boost::system::error_code ec;

  std::ostream os(&b);
  os << aCommand << std::endl;

  if (serial.is_open())
  {
    boost::asio::write(serial, b.data());
    std::cout << "written" << std::endl;
    os.flush();
  }
  else
  {
    std::cout << "Unable to open serial, stopping program" << std::endl;
    exit(-1);
  }
}

bool lowlevel::servoExists(unsigned int aServoId) const
{
  bool lReturn = false;

  for (int i = 0; (i < mServos.size()) && (!lReturn); ++i)
  {
    if (mServos.at(i).getServoId() == aServoId)
    {
      lReturn = true;
    }
  }

  return lReturn;
}

Servo& lowlevel::getServoWithId(unsigned int aServoId)
{
  bool lFoundServo = false;

  for (int i = 0; i < mServos.size(); ++i)
  {
    if (mServos.at(i).getServoId() == aServoId)
    {
      lFoundServo = true;
      return mServos.at(i);
    }
  }

  if(!lFoundServo)
  {
    throw std::invalid_argument( "Invalid servoId entered.");
  }
}
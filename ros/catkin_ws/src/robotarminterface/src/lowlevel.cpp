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

int lowlevel::checkServoRange(unsigned int aPin, int aDegree)
{
  bool lServoFound = false;
  int lDegree = 0;
  for (auto lServo : mServos)
  {
    if (aPin == lServo.mServoId)
    {
      lServoFound = true;
      if (aDegree < lServo.mMinDegree)
      {
        lDegree = lServo.mMinDegree;
        std::cout << "Degree too small, pin : " << aPin << " Degree : " << aDegree << std::endl;
      }
      else if (aDegree > lServo.mMaxDegree)
      {
        lDegree = lServo.mMaxDegree;
        std::cout << "Degree too big, pin : " << aPin << " Degree : " << aDegree << std::endl;
      }
      else
      {
        lDegree = aDegree; 
      }
    }
  }
  if (lServoFound == false)
  {
    std::cout << "Unable to find the servo with pinId : " << aPin << std::endl;
  }
  return lDegree;
}

void lowlevel::moveServosToPos(std::vector<unsigned int> aPins, std::vector<unsigned int> aDegrees, unsigned int aMillis)
{
  // Every pin should correspond with a degree value, if this is not the case do nothing (input invalid)
  if (aPins.size() == aDegrees.size())
  {
    std::string lCommand = "";

    for (int i = 0; i < aPins.size(); ++i)
    {
      // Check if the value is in the defined range of motion, if not set the max/min value
      // int lCurrentCheckedDegree = checkServoRange(aPins.at(i), aDegrees.at(i));

      // unsigned int lPulseWidth = convertDegreesToPulsewidth(lCurrentCheckedDegree);
      unsigned int lPulseWidth = convertDegreesToPulsewidth(aDegrees.at(i));

      lCommand.append("#" + std::to_string(aPins.at(i)));
      lCommand.append("P" + std::to_string(lPulseWidth));
    }

    lCommand.append("T" + std::to_string(aMillis));
    lCommand.append("\r");

    std::cout << "Command sent via serial: " << lCommand << std::endl;
    sendSerial(lCommand);
  }
  else
  {
    std::cout << "Error, invalid command recieved." << std::endl;
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


unsigned int lowlevel::convertDegreesToPulsewidth(unsigned int aDegrees, Servo& aServo) const
{
  unsigned int lPulseRange = MAX_PULSEWIDTH - MIN_PULSEWIDTH;

  // Degree range of the servo's
  unsigned int lDegreeRange = std::abs(aServo.getMaxDegrees() - aServo.getMinDegrees());

  double lFactor = (double)aDegrees / (double)lDegreeRange;

  unsigned int lReturn = MIN_PULSEWIDTH + lPulseRange * lFactor;

  return lReturn;
}

bool lowlevel::degreesInRange(unsigned int aDegrees, Servo& aServo) const
{
  bool lReturn = false;

  if((aDegrees >= aServo.getMinDegrees()) && (aDegrees <= aServo.getMaxDegrees()))
  {
    lReturn = false;
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
#include "robotarminterface/lowlevel.hpp"

lowlevel::lowlevel() : serial(ioservice)
{
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
  boost::system::error_code ec; // choice: without ec Boost.Asio may throw
  if (!ec)
  {
  serial.set_option(boost::asio::serial_port_base::baud_rate(aBaudRate));
  }
}

void lowlevel::moveServosToPos(std::vector<unsigned int> aPins, std::vector<unsigned int> aDegrees, unsigned int aMillis)
{
  // Every pin should correspond with a degree value, if this is not the case do nothing (input invalid)
  if (aPins.size() == aDegrees.size())
  {
    std::string lCommand = "";

    for (int i = 0; i < aPins.size(); ++i)
    {
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


unsigned int lowlevel::convertDegreesToPulsewidth(unsigned int aDegrees) const
{
  unsigned int lPulseRange = MAX_PULSEWIDTH - MIN_PULSEWIDTH;

  // TO-DO: Make this variable/define?
  // Degree range of the servo's
  unsigned int lDegreeRange = 180;

  double lFactor = (double)aDegrees / (double)lDegreeRange;

  unsigned int lReturn = MIN_PULSEWIDTH + lPulseRange * lFactor;

  // Bounds checking
  lReturn = (lReturn < MIN_PULSEWIDTH) ? MIN_PULSEWIDTH : lReturn;
  lReturn = (lReturn > MAX_PULSEWIDTH) ? MAX_PULSEWIDTH : lReturn;

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
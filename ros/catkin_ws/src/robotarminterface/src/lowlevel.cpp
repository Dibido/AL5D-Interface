#include "robotarminterface/lowlevel.hpp"

lowlevel::lowlevel() : serial(ioservice)
{
  // Initializing serial
  boost::system::error_code ec; // choice: without ec Boost.Asio may throw
  serial.open("/dev/ttyUSB0", ec);

  if (!ec)
  {
    serial.set_option(boost::asio::serial_port_base::baud_rate(19200));
    serial.set_option(boost::asio::serial_port::flow_control(boost::asio::serial_port::flow_control::none));
    serial.set_option(boost::asio::serial_port::parity(boost::asio::serial_port::parity::none));
    serial.set_option(boost::asio::serial_port::stop_bits(boost::asio::serial_port::stop_bits::one));
    serial.set_option(boost::asio::serial_port::character_size(boost::asio::serial_port::character_size(8)));
  }
}

lowlevel::~lowlevel()
{
}

void lowlevel::moveServoToPos(unsigned int aPin, unsigned int aDegrees, unsigned int aMillis) const
{
  unsigned int lPulseWidth = convertDegreesToPulsewidth(aDegrees);

  std::string lCommand = "#" + std::to_string(aPin);

  lCommand.append("P" + std::to_string(lPulseWidth));
  lCommand.append("T" + std::to_string(aMillis));
  lCommand.append("\r");
}

unsigned int lowlevel::convertDegreesToPulsewidth(unsigned int aDegrees) const
{
  unsigned int lPulseRange = MAX_PULSEWIDTH - MIN_PULSEWIDTH;

  // TO-DO: Make this variable/define?
  // Degree range of the servo's
  unsigned int lDegreeRange = 180;

  double lFactor = aDegrees / lDegreeRange;

  unsigned int lReturn = MIN_PULSEWIDTH + lPulseRange * lFactor;

  // Bounds checking
  lReturn = lReturn < MIN_PULSEWIDTH ? MIN_PULSEWIDTH : lReturn;
  lReturn = lReturn > MAX_PULSEWIDTH ? MAX_PULSEWIDTH : lReturn;

  return lReturn;
}

void lowlevel::sendSerial(const std::string &aCommand) const
{
  boost::asio::streambuf b;
  boost::system::error_code ec;

  std::ostream os(&b);
  os << aCommand << std::endl;

  // serial.open("/dev/ttyUSB0");
  serial.write_some("test");
  
  if (serial.is_open())
  {
    boost::asio::write(serial, b.data());
    std::cout << "written" << std::endl;
    os.flush();
  }
  else
  {
    std::cout << "Unable to open serial";
  }
}
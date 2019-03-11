// Generated by gencpp from file robotarminterface/armPosition.msg
// DO NOT EDIT!


#ifndef ROBOTARMINTERFACE_MESSAGE_ARMPOSITION_H
#define ROBOTARMINTERFACE_MESSAGE_ARMPOSITION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robotarminterface
{
template <class ContainerAllocator>
struct armPosition_
{
  typedef armPosition_<ContainerAllocator> Type;

  armPosition_()
    : positionName()
    , time(0)  {
    }
  armPosition_(const ContainerAllocator& _alloc)
    : positionName(_alloc)
    , time(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _positionName_type;
  _positionName_type positionName;

   typedef uint32_t _time_type;
  _time_type time;





  typedef boost::shared_ptr< ::robotarminterface::armPosition_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robotarminterface::armPosition_<ContainerAllocator> const> ConstPtr;

}; // struct armPosition_

typedef ::robotarminterface::armPosition_<std::allocator<void> > armPosition;

typedef boost::shared_ptr< ::robotarminterface::armPosition > armPositionPtr;
typedef boost::shared_ptr< ::robotarminterface::armPosition const> armPositionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robotarminterface::armPosition_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robotarminterface::armPosition_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robotarminterface

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'robotarminterface': ['/home/owner/git/AL5D-Interface/ros/catkin_ws/src/robotarminterface/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robotarminterface::armPosition_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotarminterface::armPosition_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotarminterface::armPosition_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotarminterface::armPosition_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotarminterface::armPosition_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotarminterface::armPosition_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robotarminterface::armPosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "59ae392b882bffe08a45dc4e0a602b92";
  }

  static const char* value(const ::robotarminterface::armPosition_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x59ae392b882bffe0ULL;
  static const uint64_t static_value2 = 0x8a45dc4e0a602b92ULL;
};

template<class ContainerAllocator>
struct DataType< ::robotarminterface::armPosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robotarminterface/armPosition";
  }

  static const char* value(const ::robotarminterface::armPosition_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robotarminterface::armPosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string positionName\n\
uint32 time\n\
";
  }

  static const char* value(const ::robotarminterface::armPosition_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robotarminterface::armPosition_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.positionName);
      stream.next(m.time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct armPosition_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robotarminterface::armPosition_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robotarminterface::armPosition_<ContainerAllocator>& v)
  {
    s << indent << "positionName: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.positionName);
    s << indent << "time: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.time);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOTARMINTERFACE_MESSAGE_ARMPOSITION_H
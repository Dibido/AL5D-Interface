#include "highlevel.h"
#include "robotarminterface/lowlevel.hpp"

#include <iostream>

int main(int argc, char** argv)
{
  lowlevel low;
  std::cout << low.addNumbers(3, 5) << std::endl;
  return 0;
}
/**
 * @file lowlevel.hpp
 * @author your name (you@domain.com)
 * @brief lowlevel interface
 * @version 0.1
 * @date 2019-02-18
 */
#ifndef LOWLEVEL_H_
#define LOWLEVEL_H_

class lowlevel
{
  public:
  lowlevel();
  virtual ~lowlevel();

  inline int addNumbers(int a, int b)
  {
    return a + b;
  }
};

#endif
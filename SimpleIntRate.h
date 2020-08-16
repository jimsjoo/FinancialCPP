//
// SimpleIntRate.h
#ifndef __OneOuOne__SimpleIntRate__

#define __OneOuOne__SimpleIntRate__
#include <iostream>

class SimpleIntRate {
  public:
    SimpleIntRate(double rate);
//    SimpleIntRate(const SimpleIntRate &v);
//    SimpleIntRate &operator =(const SimpleIntRate &v);
    ~SimpleIntRate();

    double futureValue(double value);
  private:
    double m_rate;
};

inline double SimpleIntRate::futureValue(double value)
{
  double f = value * ( 1 + this->m_rate );
  return f;
}
#endif /* defined(__OneOuOne__SimpleIntRate__) */


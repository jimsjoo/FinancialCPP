// CompoundIntRate.cpp
#include "CompoundIntRate.h"
#include <cmath>

CompoundIntRate::CompoundIntRate(double rate)
  : m_rate(rate)
{
}

CompoundIntRate::~CompoundIntRate()
{
}

//CompoundIntRate::CompoundIntRate(const CompoundIntRate &v)
//  : m_rate(v.m_rate)
//{
//}
//
//CompoundIntRate &CompoundIntRate::operator =(const
//    CompoundIntRate &v)
//{
//  if (this != &v) {
//    this->m_rate = v.m_rate;
//  }
//  return *this;
//}

double CompoundIntRate::futureValueByDiscreteCompounding(double value, int numPeriods)
{
  return value * pow(1 + m_rate, numPeriods);  
}

double CompoundIntRate::futureValueByContinuousCompounding(double value, int numPeriods)
{
  return value * exp(m_rate * numPeriods);  
}

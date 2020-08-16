// Bond.cpp
#include "Bond.h"
#include <iostream>

Bond::Bond(double principal, double coupon, int periods)
  : m_principal(principal),
    m_coupon(coupon),
    m_numPeriods(periods)
{
}

Bond::~Bond()
{
}

//Bond::Bond(const std::string institution,
//  int numPeriods, double principal, double couponValue)
//  : m_institution(institution),
//    m_numPeriods(numPeriods),
//    m_principal(principal),
//    m_coupon(couponValue)
//{
//}
//
//Bond::Bond(const Bond &v)
//  : m_institution(institution),
//    m_numPeriods(v.m_numPeriods),
//    m_principal(v.m_principal),
//    m_coupon(v.m_coupon)
//{
//}
//
//
//Bond &Bond::operator =(const Bond &v)
//{
//  if (this != &v) {
//    this->m_institution = v.m_institution;
//    this->m_principal = v.m_principal;
//    this->m_numPeriods = v.m_numPeriods;
//    this->m_coupon = v.m_coupon;
//  }
//  return *this;
//}

double Bond::interestRate()
{
  std::cout<<"m_coupon: "<<m_coupon<<" m_principal: "<<m_principal<<std::endl;
  return m_coupon / m_principal;
}


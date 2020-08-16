// CashFlow.cpp
#include "CashFlow.h"
#include <cmath>
#include <iostream>

CashFlow::CashFlow(double rate)
  : m_rate(rate)
{
}

CashFlow::~CashFlow()
{
}

//CashFlow::CashFlow(const CashFlow &v)
//  : m_rate(v.m_rate)
//{
//}
//
//CashFlow &CashFlow::operator =(const CashFlow &v)
//{
//  if (this != &v) {
//    this->m_cashFlows = v.m_cashFlows;
//    this->m_timePeriods = v.m_timePeriods;
//    this->m_rate = v.m_rate;
//  }
//  return *this;
//}

void CashFlow::addCashFlow(double value, int timePeriod)
{
  m_cashFlows.push_back(value);
  m_timePeriods.push_back(timePeriod);
}

double CashFlow::presentValue(double futureValue, int timePeriod)
{
  double pValue = futureValue / pow(1+m_rate, timePeriod);
  std::cout << futureValue << 1+m_rate << timePeriod << pValue << std::endl;
  return pValue;
  //return futureValue / pow(1+m_rate, timePeriod);    
}

double CashFlow::presentValue()
{
  double total = 0;
  for (int i=0; i<m_cashFlows.size(); ++i) {
    total += presentValue(m_cashFlows[i], m_timePeriods[i]);
  }
  return total;
}

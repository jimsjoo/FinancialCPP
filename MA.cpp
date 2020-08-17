// MA.cpp
#include "MA.h"
#include <iostream>

MA::MA()
{
}

MA::MA(int numPeriods)
  : m_numPeriods(numPeriods)
{
}

MA::~MA()
{
}

MA::MA(const MA &ma)
  : m_numPeriods(ma.m_numPeriods)
{
}

MA &MA::operator = (const MA &ma)
{
  if (this != &ma) {
    m_numPeriods = ma.m_numPeriods;
    m_prices = ma.m_prices;
  }
  return *this;
}

std::vector<double> MA::sMA(int period)
{
  std::vector<double> ma;
  double sum = 0;
  
  for (int i=0; i<m_prices.size(); ++i) {
    sum += m_prices[i];
    if (i >= period) {
      ma.push_back(sum / period);
      sum -= m_prices[i-period];
    }
  }
  return ma;
}

std::vector<double> MA::eMA(int period)
{
  std::vector<double> ema;
  double sum = 0;
  double multiplier = 2.0 / (period + 1);
  
  for (int i=0; i<m_prices.size(); ++i) {
    sum += m_prices[i];
    if (i == period) {
      ema.push_back(sum / period);
      sum -= m_prices[i-period];
    } else if (i > period) {
      double val = (1-multiplier) * ema.back() + multiplier * m_prices[i];
      ema.push_back(val);
    }
  }
  return ema;
}

void MA::add(double close)
{
  m_prices.push_back(close);
}

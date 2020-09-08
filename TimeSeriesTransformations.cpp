// TimeSeriesTransformations.cpp
#include "TimeSeriesTransformations.h"
#include <algorithm>
#include <functional>

TimeSeriesTransformations::TimeSeriesTransformations()
  : m_prices()
{
}

TimeSeriesTransformations::TimeSeriesTransformations(const TimeSeriesTransformations &s)
  : m_prices(s.m_prices)
{
}

TimeSeriesTransformations::~TimeSeriesTransformations()
{
}

TimeSeriesTransformations &TimeSeriesTransformations::operator=(const TimeSeriesTransformations &v)
{
  if (this != &v)
    {
      m_prices = v.m_prices;
    }
  return *this;
}

void TimeSeriesTransformations::reducePrices(double val)
{
  std::vector<double> neg(m_prices.size());
  std::transform(m_prices.begin(), m_prices.end(), neg.begin(), std::bind2nd(std::minus<double>(), val));
  m_prices.swap(neg);
}

void TimeSeriesTransformations::increasePrices(double val)
{
  std::for_each(m_prices.begin(), m_prices.end(), std::bind1st(std::plus<double>(), val));
}

void TimeSeriesTransformations::removePricesLessThan(double val)
{
  std::remove_if(m_prices.begin(), m_prices.end(), std::bind2nd(std::less<double>(), val));
}

void TimeSeriesTransformations::removePricesGreaterThan(double val)
{
  std::remove_if(m_prices.begin(), m_prices.end(), std::bind2nd(std::greater<double>(), val));
}

double TimeSeriesTransformations::getFirstPriceLessThan(double val)
{
  auto res = std::find_if(m_prices.begin(), m_prices.end(), std::bind2nd(std::less<double>(), val));
  if (res != m_prices.end())
    return *res;
  return 0;
}

void TimeSeriesTransformations::addValue(double val)
{
  m_prices.push_back(val);
}

void TimeSeriesTransformations::addValues(const std::vector<double> &val)
{
  m_prices.insert(m_prices.end(), val.begin(), val.end());
}


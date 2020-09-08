// TimeSeriesTransformations.h
#ifndef __OneOuOne__TimeSeriesAnalysis__
#define __OneOuOne__TimeSeriesAnalysis__
#include <vector>

class TimeSeriesTransformations
{
  public:
    TimeSeriesTransformations();
    TimeSeriesTransformations(const TimeSeriesTransformations &);
    ~TimeSeriesTransformations();
    TimeSeriesTransformations &operator=(const TimeSeriesTransformations &);
    void reducePrices(double val);
    void increasePrices(double val);
    void removePricesLessThan(double val);
    void removePricesGreaterThan(double val);
    double getFirstPriceLessThan(double val);
    void addValue(double val);
    void addValues(const std::vector<double> &val);
    
  private:
    std::vector<double> m_prices;
};
#endif /* defined(__OneOuOne__TimeSeriesAnalysis__) */

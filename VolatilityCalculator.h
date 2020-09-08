// VolatilityCalculator.h
#ifndef __OneOuOne__VolatilityCalculator__
#define __OneOuOne__VolatilityCalculator__
#include <vector>

class VolatilityCalculator
{
  public:
    VolatilityCalculator();
    ~VolatilityCalculator();
    VolatilityCalculator(const VolatilityCalculator &);
    VolatilityCalculator &operator=(const VolatilityCalculator &);
    void addPrice(double price);
    double rangeVolatility();
    double stdDev();
    double mean();
    double avgDailyRange();
    
  private:
    std::vector<double> m_prices;
};
#endif /* defined(__OneOuOne__VolatilityCalculator__) */

// MA.h
#ifndef __OneOuOne__MA__
#define __OneOuOne__MA__
#include <vector>

class MA {
  
  public:
    MA();
    MA(int period);
    MA(const MA &);
    MA &operator = (const MA &);
    ~MA();
    void add(double close);
    std::vector<double> sMA(int period);
    std::vector<double> eMA(int period);
    
  private:
// number of periods used in the calculation
    int m_numPeriods;
    std::vector<double> m_prices;
    
};
#endif /* defined(__OneOuOne__MA__) */

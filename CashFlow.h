// CashFlow.h
#ifndef __OneOuOne__CashFlow__
#define __OneOuOne__CashFlow__

#include <vector>

class CashFlow {
  public:
    CashFlow(double rate);
//    CashFlow(const CashFlow &v);
//    CashFlow &operator =(const CashFlow &v);
    ~CashFlow();
    void addCashFlow(double value, int timePeriod);
    double presentValue();
    
  private:
    std::vector<double> m_cashFlows;
    std::vector<int> m_timePeriods;
    double m_rate;
    double presentValue(double futureValue, int timePeriod);
};
#endif /* defined(__OneOuOne__CashFlow__) */

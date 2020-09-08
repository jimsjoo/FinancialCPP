// TimeSeries.h
#ifndef __OneOuOne__TimeSeries__
#define __OneOuOne__TimeSeries__
#include <vector>

class TimeSeries
{
  public:
    TimeSeries();
    TimeSeries(const TimeSeries &);
    TimeSeries &operator=(const TimeSeries &);
    ~TimeSeries();
    void addValue(double val);
    double stdDev();
    double mean();
    std::size_t size();
    double elem(int i);
    
  private:
    std::vector<double> m_values;
};
#endif /* defined(__OneOuOne__TimeSeries__) */

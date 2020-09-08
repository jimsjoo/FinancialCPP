// Correlation.h
#ifndef __OneOuOne__Correlation__
#define __OneOuOne__Correlation__

class TimeSeries;

class Correlation
{
  public:
    Correlation(TimeSeries &a, TimeSeries &b);
    ~Correlation();
    Correlation(const Correlation &);
    Correlation &operator =(const Correlation &);
    double correlation();
    
  private:
    TimeSeries &m_tsA;
    TimeSeries &m_tsB;
};
#endif /* defined(__OneOuOne__Correlation__) */

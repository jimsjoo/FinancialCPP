// CompoundIntRate.h
#ifndef __OneOuOne__CompoundIntRate__
#define __OneOuOne__CompoundIntRate__

class CompoundIntRate {
  public:
    CompoundIntRate(double rate);
//    CompoundIntRate(const CompoundIntRate &v);
//    CompoundIntRate &operator =(const CompoundIntRate &v);
    ~CompoundIntRate();
    
    double futureValueByDiscreteCompounding(double value, int numPeriods);
    double futureValueByContinuousCompounding(double value, int numPeriods);
  private:
    double m_rate;
};
#endif /* defined(__OneOuOne__CompoundIntRate__) */

// Bond.h
#ifndef __OneOuOne__Bond__
#define __OneOuOne__Bond__

class Bond {
  public:
    Bond(double principal, double coupon, int periods);
//    Bond(const std::string institution, int periods, 
//      double principal, double coupon);
//    Bond(const Bond &v);
//    Bond &operator =(const Bond &v);
    ~Bond();
    double interestRate();
    
  private:
//    std::string m_institution;
    double m_principal;
    double m_coupon;
    int m_numPeriods;
};
#endif /* defined(__OneOuOne__Bond__) */

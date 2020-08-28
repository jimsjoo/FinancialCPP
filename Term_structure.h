#ifndef __OneOuOne__Term_Structure__
#define __OneOuOne__Term_Structure__
#include <vector>
#include <cmath>

class Term_structure {
  public:
    virtual double r(const double& t) ; // yield on zero coupon bond
    virtual double d(const double& t) ; // discount factor/price of zero coupon bond
    virtual double f(const double& t1, const double& t2); // forward rate
    virtual ~Term_structure(){}
    
    double term_structure_yield_from_discount_factor(const double& d_t, const double& t);      
    double term_structure_discount_factor_from_yield(const double& r, const double& t);      
    double term_structure_forward_rate_from_discount_factors(const double& d_t1, const double& d_t2, const double& time);      
    double term_structure_forward_rate_from_yields(const double& r_t1, const double& r_t2, const double& t1, const double& t2);
    
};
#endif



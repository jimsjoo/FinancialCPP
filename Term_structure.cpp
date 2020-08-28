#include "Term_structure.h"
 
double Term_structure::f(const double& t1, const double& t2) {
  const double d1 = d(t1);
  const double d2 = d(t2);
  const double dt = t2-t1;
  return term_structure_forward_rate_from_discount_factors(d1,d2,dt);
};

double Term_structure::r(const double& t) {
  return term_structure_yield_from_discount_factor(d(t),t);
};

double Term_structure::d(const double& t) {
  return term_structure_discount_factor_from_yield(r(t),t);
};

double Term_structure::term_structure_yield_from_discount_factor(const double& d_t, const double& t) {
  return (-log(d_t)/t);
};

double Term_structure::term_structure_discount_factor_from_yield(const double& r, const double& t) {
  return exp(-r*t);
};

double Term_structure::term_structure_forward_rate_from_discount_factors(const double& d_t1, const double& d_t2, const double& time) {
  return (log(d_t1/d_t2))/time;
};

double Term_structure::term_structure_forward_rate_from_yields(const double& r_t1, const double& r_t2, const double& t1, const double& t2) {
  return r_t2*t2/(t2-t1)-r_t1*t1/(t2-t1);
};



#include "Term_structure.h"
 
double Term_structure::yield_from_discount_factor(const double& d_t, const double& t) 
{
  return (-log(d_t)/t);
};

double Term_structure::discount_factor_from_yield(const double& r, const double& t) 
{
  return exp(-r*t);
};

double Term_structure::forward_rate_from_discount_factors(const double& d_t1, const double& d_t2, const double& time) 
{
  return (log(d_t1/d_t2))/time;
};

double Term_structure::forward_rate_from_yields(const double& r_t1, const double& r_t2, const double& t1, const double& t2) 
{
  return r_t2*t2/(t2-t1)-r_t1*t1/(t2-t1);
};

double Term_structure::yield_linearly_interpolated(const double& time) 
{
  // assume the yields are in increasing time to maturity order.
  int no_obs = no_observations();
  if (no_obs<1) return 0;
  
  double t_min = times_[0];
  if (time <= t_min) return yields_[0]; // earlier than lowest obs.
  
  double t_max = times_[no_obs-1];
  if (time >= t_max) return yields_[no_obs-1]; // later than latest obs
  
  int t=1; // find which two observations we are between
  while ( (t<no_obs) && (time>times_[t])) { ++t; };
  double lambda = (times_[t]-time)/(times_[t]-times_[t-1]);
  
  // by ordering assumption, time is between t-1,t
  double r = yields_[t-1] * lambda + yields_[t] * (1.0-lambda);
  return r;
};

void Term_structure::clear()
{
//  times_.erase(times .begin(), times .end());
//  yields_.erase(yields .begin(), yields .end());
  times_.clear();
  yields_.clear();
};

Term_structure::Term_structure(const vector<double>& in_times,const vector<double>& in_yields) 
{
  clear();
  if (in_times.size()!=in_yields.size()) return;
  times_  = vector<double>(in_times.size());
  yields_ = vector<double>(in_yields.size());
  
  for (int i=0;i<in_times.size();i++) {
    times_[i]  = in_times[i];
    yields_[i] = in_yields[i];
  };
};

Term_structure::Term_structure(const Term_structure& term) 
{
  times_  = vector<double> (term.no_observations());
  yields_ = vector<double> (term.no_observations());
  
  for (int i=0;i<term.no_observations();i++){
    times_[i]  = term.times_[i];
    yields_[i] = term.yields_[i];
  };
};

Term_structure& Term_structure::operator= (const Term_structure& term) 
{
  times_  = vector<double> (term.no_observations());
  yields_ = vector<double> (term.no_observations());
  
  for (int i=0;i<term.no_observations();i++){
    times_[i]  = term.times_[i];
    yields_[i] = term.yields_[i];
  };
  return (*this);
};
                
void Term_structure::set_interpolated_observations(vector<double>& in_times, vector<double>& in_yields) 
{
  clear();
  if (in_times.size() != in_yields.size()) return;
  times_  = vector<double>(in_times.size());
  yields_ = vector<double>(in_yields.size());
  
  for (int i=0; i<in_times.size(); i++) {
    times_[i]  = in_times[i];
    yields_[i] = in_yields[i];
  };
};

//double Term_structure::r(const double& T) const {
//  return term structure yield linearly interpolated(T, times , yields );
//};

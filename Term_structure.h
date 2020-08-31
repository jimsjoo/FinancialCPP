#ifndef __OneOuOne__Term_Structure__
#define __OneOuOne__Term_Structure__
#include <vector>
#include <cmath>

using namespace std;

class Term_structure {
  public:
    int no_observations() const { return times_.size(); };
    void set_interpolated_observations(vector<double>& in_times, vector<double>& in_yields);
    double yield_from_discount_factor(const double& d_t, const double& t); 
    double discount_factor_from_yield(const double& r, const double& t);
    double forward_rate_from_discount_factors(const double& d_t1, const double& d_t2, const double& time);
    double forward_rate_from_yields(const double& r_t1, const double& r_t2, const double& t1, const double& t2);
    double yield_linearly_interpolated(const double& time);
    
    Term_structure(){clear();};
    Term_structure(const Term_structure& term);
    Term_structure(const vector<double>& in_times,const vector<double>& in_yields);
    Term_structure& operator= (const Term_structure& term);
    ~Term_structure(){clear();};
    
  private:
    double R_;
    vector<double> times_; // use to keep a list of yields
    vector<double> yields_;
    void clear();
};
#endif





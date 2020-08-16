//
// Cashflows.h
#ifndef __OneOuOne__Cashflows__

#define __OneOuOne__Cashflows__
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

class Cashflows {
  public:
    Cashflows(vector<double> times, vector<double> cflows, double rate);
    ~Cashflows();
    
    double cash_flow_pv_discrete();
    double cash_flow_pv_discrete(const vector<double>& times, const vector<double>& cflows, double& r);
    double cash_flow_irr_discrete();
    
    double cash_flow_pv();
    double cash_flow_pv(const vector<double>& times,const vector<double>& cflow,const double& r);
    double cash_flow_irr();

  private:
    vector<double> m_times;
    vector<double> m_cflows;
    double m_rate;    
};

#endif /* defined(__OneOuOne__Cashflows__) */



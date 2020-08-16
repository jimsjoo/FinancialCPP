#include "Cashflows.h"

Cashflows::Cashflows(vector<double> times, vector<double> cflows, double rate)
  : m_times(times), m_cflows(cflows), m_rate(rate)
{
}

Cashflows::~Cashflows()
{
}

double Cashflows::cash_flow_pv_discrete()
{
  return cash_flow_pv_discrete(m_times, m_cflows, m_rate);
}

double Cashflows::cash_flow_pv_discrete(const vector<double>& times, const vector<double>& cflows, double& r)
{
  double PV=0.0;
  for (int t=0; t<times.size(); t++) {
    PV += cflows[t]/pow(1.0+r, times[t]);
  };
  return PV;
}

double Cashflows::cash_flow_irr_discrete()
{
// simple minded irr function. Will find one root (if it exists.)
// adapted from routine in Numerical Recipes in C.
  const double ERROR=-1e30;

  if (m_times.size()!=m_cflows.size()) return ERROR;

  const double ACCURACY = 1.0e-5;
  const int MAX_ITERATIONS = 50;
  double x1 = 0.0;
  double x2 = 0.2;

// create an initial bracket, with a root somewhere between bot,top
  double f1 = cash_flow_pv_discrete(m_times, m_cflows, x1);
  double f2 = cash_flow_pv_discrete(m_times, m_cflows, x2);

  for (int i=0; i<MAX_ITERATIONS; i++) {
    if ( (f1*f2) < 0.0) {
      break;
    }; //
    if (fabs(f1)<fabs(f2)) {
      f1 = cash_flow_pv_discrete(m_times, m_cflows, x1+=1.6*(x1-x2));
    } else {
      f2 = cash_flow_pv_discrete(m_times, m_cflows, x2+=1.6*(x2-x1));
    };
  };

  if (f2*f1>0.0) {
    return ERROR;
  };

  double f = cash_flow_pv_discrete(m_times, m_cflows, x1);
  double rtb;
  double dx=0;

  if (f<0.0) {
    rtb = x1;
    dx=x2-x1;
  } else {
    rtb = x2;
    dx = x1-x2;
  };
  for (int i=0; i<MAX_ITERATIONS; i++) {
    dx *= 0.5;
    double x_mid = rtb+dx;
    double f_mid = cash_flow_pv_discrete(m_times,m_cflows, x_mid);
    if (f_mid<=0.0) {
      rtb = x_mid;
    }
    if ( (fabs(f_mid)<ACCURACY) || (fabs(dx)<ACCURACY) ) return x_mid;
  };
  return ERROR; // error.
};

double Cashflows::cash_flow_pv()
{
  return cash_flow_pv(m_times, m_cflows, m_rate);
}

double Cashflows::cash_flow_pv(const vector<double>& times,const vector<double>& cflows,const double& r)
{
  double PV=0.0;
  for (int t=0; t<times.size(); t++) {
    PV += cflows[t] * exp(-r*times[t]);
  };
  return PV;
}

double Cashflows::cash_flow_irr()
{
  // simple minded irr function.  Will find one root (if it exists.)
  // adapted from routine in Numerical Recipes in C.
  const double ERROR=-1e30;
  
  if (m_times.size()!=m_cflows.size()) return ERROR;
  const double ACCURACY = 1.0e-5;
  const int MAX_ITERATIONS = 50;
  double x1=0.0;
  double x2 = 0.2;

  // create an initial bracket, with a root somewhere between bot,top
  double f1 = cash_flow_pv(m_times, m_cflows,  x1);
  double f2 = cash_flow_pv(m_times, m_cflows,  x2);
  
  for (int i=0; i<MAX_ITERATIONS; i++) {
    if ( (f1*f2) < 0.0) {
      break;
    }; //
    if (fabs(f1)<fabs(f2)) {
      f1 = cash_flow_pv(m_times, m_cflows, x1+=1.6*(x1-x2));
    } else {
      f2 = cash_flow_pv(m_times, m_cflows, x2+=1.6*(x2-x1));
    };
  };
  if (f2*f1>0.0) {
    return ERROR;
  };
  
  double f = cash_flow_pv(m_times,m_cflows, x1);
  double rtb;
  double dx=0;
  
  if (f<0.0) {
    rtb = x1;
    dx=x2-x1;
  } else {
    rtb = x2;
    dx = x1-x2;
  };
  for (int i=0; i<MAX_ITERATIONS; i++) {
    dx *= 0.5;
    double x_mid = rtb+dx;
    double f_mid = cash_flow_pv(m_times, m_cflows, x_mid);
    if (f_mid<=0.0) {
      rtb = x_mid;
    }
    if ( (fabs(f_mid)<ACCURACY) || (fabs(dx)<ACCURACY) ) return x_mid;
  };
  return ERROR;   // error.
};


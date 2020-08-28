
#include <iostream>
#include <vector>
#include "Cashflows.h"
#include "Bonds.h"
#include "Term_structure_flat.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
  double B;
  double r;
  vector<double> cflows; 
  vector<double> times; 
  
  // Cashflows
  cflows.push_back(-100.0); cflows.push_back(10.0); cflows.push_back(110.0);  
  times.push_back(0.0); times.push_back(1); times.push_back(2);  
  r=0.05;
  
  Cashflows cf1(times, cflows, r);
  cout << "----------------------------" << endl;
  cout << " Present Value Chapter      " << endl;
  cout << "----------------------------" << endl;
  cout << " present value, 5\% discretely compounded interest = " ;
  cout << cf1.cash_flow_pv_discrete() << endl;
  cout << " internal rate of return, discrete compounding = ";  
  cout << cf1.cash_flow_irr_discrete() << endl;
  cout << " present value, 5\% continously compounded interest = " ;
  cout << cf1.cash_flow_pv() << endl;
  cout << " internal rate of return, continous compounding = ";  
  cout << cf1.cash_flow_irr() << endl;  
  
  times.clear();
  cflows.clear();
  
  // Duration  
  cflows.push_back(10); cflows.push_back(10); cflows.push_back(110);
  times.push_back(1); times.push_back(2); times.push_back(3);
  r=0.09;
  
  Cashflows cf2(times, cflows, r);
  Bonds b0(cf2);
  cout << "----------------------------" << endl;
  cout << " Duration                   " << endl;
  cout << "----------------------------" << endl;
  cout << " bonds duration for b0 = " << b0.bonds_duration_discrete() << endl;
  
  Bonds b1(times, cflows, r);  
  
  B = b1.bonds_price_discrete(times, cflows, r);
  cout << " bonds price = " << B << endl;
  cout << " bond duration = " << b1.bonds_duration_discrete(times, cflows, r) << endl;
  cout << " bond macaulay = " << b1.bonds_duration_macaulay_discrete(times, cflows, B) << endl;
  cout << " bond duration modified = " << b1.bonds_duration_modified_discrete(times, cflows, B) << endl;
  cout << " bond convexity =" << b1.bonds_convexity_discrete(times, cflows, r) << endl;
  cout << " new bond price = " << b1.bonds_price_discrete(times, cflows, 0.1)<< endl;

  times.clear();
  cflows.clear();
  
  // Bond price and YTM
  cflows.push_back(10); cflows.push_back(10); cflows.push_back(110);
  times.push_back(1); times.push_back(2); times.push_back(3);
  r=0.09;  
  
  Bonds b2(times, cflows, r);
  B = b2.bonds_price_discrete();
  
  cout << " Bond price, 9 percent discretely compounded interest = " << B << endl;
  cout << " bond yield to maturity = " << b2.bonds_yield_to_maturity_discrete(B) << endl;

  //---------------------------------------------------------------------------------------
  times.clear();
  cflows.clear();
  cflows.push_back(10); cflows.push_back(10); cflows.push_back(110);
  times.push_back(1); times.push_back(2); times.push_back(3);
  r=0.09;
  
  Bonds b3(times, cflows, r);
  B = b3.bonds_price(times, cflows, r);
  
  cout << "----------------------------" << endl;
  cout << " Continously compounded interest" << endl;
  cout << "----------------------------" << endl;  
  cout << " bonds price = " << B << endl;
  cout << " bond duration = " << b3.bonds_duration(times, cflows, r) << endl;
  cout << " bond convexity =" << b3.bonds_convexity(times, cflows, r) << endl;
  cout << " new bond price = " << b3.bonds_price(times, cflows, 0.08) << endl;
  
  Term_structure_flat ts(0.05);
  double t1=1;
  cout << "----------------------------" << endl;
  cout << " Flat term structure example" << endl;
  cout << "----------------------------" << endl;  
  cout << "discount factor t1 = " << t1 << ":" << ts.d(t1) << endl;
  
  double t2=2;
  cout << "discount factor t2 = " << t2 << ":" << ts.d(t2) << endl;
  cout << "spot rate t = " << t1 << ":" << ts.r(t1) << endl;
  cout << "spot rate t = " << t2 << ":" << ts.r(t2) << endl;
  cout << "forward rate from t1= " << t1 << " to t2= " << t2 << ":" << ts.f(t1,t2) << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include "Cashflows.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
  
  vector<double> cflows; 
  cflows.push_back(-100.0); 
  cflows.push_back(10.0); 
  cflows.push_back(110.0);
  
  vector<double> times; 
  times.push_back(0.0); 
  times.push_back(1); 
  times.push_back(2);
  
  double r=0.05;
  
  Cashflows cf(times, cflows, r);
  cout << "----------------------------" << endl;
  cout << " Present Value Chapter " << endl;
  cout << "----------------------------" << endl;
  cout << " present value, 5\% discretely compounded interest = " ;
  cout << cf.cash_flow_pv_discrete() << endl;
  cout << " internal rate of return, discrete compounding = ";  
  cout << cf.cash_flow_irr_discrete() << endl;
  cout << " present value, 5\% continously compounded interest = " ;
  cout << cf.cash_flow_pv() << endl;
  cout << " internal rate of return, continous compounding = ";  
  cout << cf.cash_flow_irr() << endl;
  
	return 0;
}

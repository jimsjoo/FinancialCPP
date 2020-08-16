// main.cpp
#include "CashFlow.h"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
  double rate = 0.08;
  
  CashFlow cfc(rate);  
  
  cfc.addCashFlow(200., 1);
  cfc.addCashFlow(300., 2);
  cfc.addCashFlow(500., 3);
  cfc.addCashFlow(-1000., 4);
  
  double pv = cfc.presentValue();
  std::cout << " The present value is " << pv << std::endl;

  return 0;
}

#include <iostream>
#include "Bond.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
  
//  std::string issuer = argv[1];
  double principal = 100000.;
  double coupon = 5000.;
  int periods = 20;
  
//  BondCalculator bc(issuer, principal, coupon, num_periods);
//  std::cout << "reading information for bond issued by " << issuer << std::endl;
  Bond bc(principal, coupon, periods);
  std::cout << " the internal rate of return is " << bc.interestRate() << std::endl;
	return 0;
}

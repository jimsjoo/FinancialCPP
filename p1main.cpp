/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "SimpleIntRate.h"
#include <iostream>
#include <cstdlib>

using namespace std;
// the main function receives parameters passed to the program
int main(int argc, const char * argv[])
{
  if (argc != 3) {
    cout << "usage: progName <interest rate> <value> " << endl;
    return 1;  
  }
  
  double rate = atof(argv[1]);
  double value = atof(argv[2]);
  
  SimpleIntRate ir(rate);
  double res = ir.futureValue(value);

  cout << "The value by simple interest rate is " <<  res << endl;
  return 0;
}

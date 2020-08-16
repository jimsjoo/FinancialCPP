#include "CompoundIntRate.h"
#include <iostream>
#include <cstdlib>

using namespace std;
// the main function receives parameters passed to the program
int main(int argc, const char * argv[])
{
  if (argc != 4) {
    cout << "usage: progName <interest rate> <present value> <num periods>" << endl;
    return 1;
  }
  
  double rate = atof(argv[1]);
  double value = atof(argv[2]);
  int num_periods = atoi(argv[3]);
  
  CompoundIntRate ir(rate);
  
  double disFv = ir.futureValueByDiscreteCompounding(value, num_periods);
  double conFv = ir.futureValueByContinuousCompounding(value, num_periods);
  
  cout << "The future value by discrete compounding is " << disFv << endl;
  cout << "The future value by continuous compounding is " << conFv << endl;
  return 0;
}

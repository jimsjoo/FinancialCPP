#include <iostream>
#include "CalmarRatio.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
  CalmarRatio<CalmarRatioPerc> ratio(0.110, 3.12);  
  std::cout << "return: " << ratio.getReturn()
    << " drawdown: " << ratio.getDrawDown() << std::endl;
            
  CalmarRatio<CalmarRatioBPS> bpsRatio(480, 2.15);  
  std::cout << "return: " << bpsRatio.getReturn()
    << " drawdown: " << bpsRatio.getDrawDown() << std::endl;
  return 0;
}

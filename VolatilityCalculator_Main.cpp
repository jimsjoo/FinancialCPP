#include <iostream>
#include <ctime>
#include "VolatilityCalculator.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
  double price;
  VolatilityCalculator vc;
  srand((unsigned) time(0));
  
  for (int index = 0; index < 100; index++) {
    int price = (std::rand() % 9900) + 10000;    
    vc.addPrice(price);
  }
  
//  for (;;)
//    {
//      std::cin >> price;
//      if (price == -1)
//        {
//          break;
//        }
//      vc.addPrice(price);
//    }
  std::cout << "range volatility is " << vc.rangeVolatility() << std::endl;
  std::cout << "average daily range is " << vc.avgDailyRange() << std::endl;
  std::cout << "standard deviation is " << vc.stdDev() << std::endl;
  return 0;
}

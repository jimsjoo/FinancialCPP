#include <iostream>
#include <cstdlib>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "MA.h"

// the main function receives parameters passed to the program
// and calls the MA class

//using namespace std;
int main(int argc, const char * argv[])
{
  srand((unsigned) time(0));
  MA ma;
  
  for (int index = 0; index < 100; index++) {
    int randomNumber = (std::rand() % 9900) + 10000;
    std::cout << randomNumber << std::endl;
    ma.add(randomNumber);
  }

  std::vector<double> sma = ma.sMA(5);    
  std::vector<double> ema = ma.eMA(5);

  const int nums = sma.size();
    
  for(int i=0 ; i<nums ; i++){
    std::cout << i << " SMA: " <<  sma[i] << ", EMA: " << ema[i] << std::endl;
  }
  return 0;
}



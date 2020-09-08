#include <iostream>
#include <random>
#include "Correlation.h"
#include "TimeSeries.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
  int price;
  TimeSeries tsa;
  TimeSeries tsb;
  
  std::random_device device;
  std::mt19937_64 generator(device());
  std::uniform_int_distribution<int> distribution(1, 99);

  for (int index = 0; index < 100; index++) {
    tsa.addValue(distribution(generator));
  } 

  for (int index = 0; index < 100; index++) {
    tsb.addValue(distribution(generator));
  } 

  Correlation cCalc(tsa, tsb);
  auto correlation = cCalc.correlation();
  std::cout << "correlation is " << correlation << std::endl;
  return 0;
}

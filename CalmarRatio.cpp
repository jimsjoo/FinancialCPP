// CalmarRatio.cpp
//
#include "CalmarRatio.h"
#include <iostream>

boost::ratio<1, 2> one_half;
boost::ratio<1, 3> one_third;

void createCalmarRatio()
{
  CalmarRatio<CalmarRatioPerc> ratio(0.15, 11);
}

void printRatios()
{
  std::cout << "one_third numerator: " << one_third.num
            << " denominator: " << one_third.den;
}

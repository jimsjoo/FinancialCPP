#include <iostream>
#include <string>
#include "TimeSeriesTransformations.h"
#include "RecommendationsProcessor.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
  RecommendationsProcessor syndayRec;
  
  Recommendation rc1("TSLA", HOLD, 1000);
  Recommendation rc2("AAPL", SELL, 1100);
  Recommendation rc3("AMZN", BUY, 1300);
  
  syndayRec.addRecommendation(rc1);
  syndayRec.addRecommendation(rc2);
  syndayRec.addRecommendation(rc3);
  syndayRec.addRecommendation("TSLA", BUY, 1000);
  syndayRec.addRecommendation("TSLA", BUY, 900);
  syndayRec.addRecommendation("TSLA", BUY, 1000);
  syndayRec.addRecommendation("AAPL", SELL, 1100);
  syndayRec.addRecommendation("AAPL", SELL, 1300);  
  syndayRec.addRecommendation("AMZN", BUY, 1300);  
  
//  std::string tickers[] = {"AAPL", "AMZN", "TSLA"};
  const std::string Rec[]={"BUY", "SELL", "HOLD","NO RECOMMENDATION"};
  for(const auto& t : {"AAPL", "AMZN", "TSLA"} )
  {
    std::cout << t << " Avg Px: " <<  syndayRec.averageTargetPrice(t) << " AvgRecType : " << Rec[syndayRec.averageRecommendation(t)] << std::endl;  
  }

  
//  std::vector<Recommendation> rcs;
//  rcs.emplace_back(rc1);
//  rcs.emplace_back(rc2);
//  
//string tickers[] = {"AAPL", "AMZN", "TSLA"};
//  for(auto& t : tickers )
//  for(auto& r : rcs )
//  {
//    std::cout << r.getRecommendation() << " " <<  r.getTicker() << " " << r.getTarget() << std::endl;  
//  }
  
  
//  TimeSeriesTransformations ts;
//  
//  std::vector<double> vals = {7, 6.4, 2.16, 5, 3, 7};
//  ts.addValues(vals);
//  ts.addValue(6.5);
//  ts.reducePrices(0.5);
//  std::cout << " price is " << ts.getFirstPriceLessThan(6.0) << std::endl;
  
//  system("pause");
	return 0;
}

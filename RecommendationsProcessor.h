// RecommendationsProcessor.h
#ifndef __OneOuOne__RecommendationsProcessor__
#define __OneOuOne__RecommendationsProcessor__
#include <map>
#include <vector>
#include "Recommendation.h"

class RecommendationsProcessor
{
  public:
    RecommendationsProcessor();
    ~RecommendationsProcessor();
    RecommendationsProcessor(const RecommendationsProcessor &);
    RecommendationsProcessor &operator =(const RecommendationsProcessor &);
    void addRecommendation(const std::string &ticker, RecommendationType rec, double targetPrice);
    void addRecommendation(const Recommendation r);
    double averageTargetPrice(const std::string &ticker);
    RecommendationType averageRecommendation(const std::string &ticker);
    
  private:
    std::map<std::string, std::vector<Recommendation> > m_recommendations;
};
#endif /* defined(__OneOuOne__RecommendationsProcessor__) */

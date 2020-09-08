// Recommendation.h
#ifndef __OneOuOne__Recommendation__
#define __OneOuOne__Recommendation__
#include <string>

enum RecommendationType
{
  BUY,
  SELL,
  HOLD,
  NO_RECOMMENDATION
};


class Recommendation
{
  public:
    Recommendation();
    Recommendation(const std::string &ticker, RecommendationType rec, double target);
    ~Recommendation();
    Recommendation(const Recommendation &r);
    Recommendation &operator =(const Recommendation &r);
    double getTarget() const;
    RecommendationType getRecommendation() const;
    std::string getTicker() const;
    
  private:
    std::string m_ticker;
    RecommendationType m_recType;
    double m_target;
};
#endif /* defined(__OneOuOne__Recommendation__) */

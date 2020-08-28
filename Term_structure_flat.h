#ifndef __OneOuOne__Term_Structure_Flat__
#define __OneOuOne__Term_Structure_Flat__

#include "Term_structure.h"

class Term_structure_flat : public Term_structure {
  private:
    double R_ ; // interest rate
    
  public:    
    Term_structure_flat(const double& r);
    virtual ~Term_structure_flat();
    virtual double r(const double& t) const;
    void set_int_rate(const double& r);
};
#endif

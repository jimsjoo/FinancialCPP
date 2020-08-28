#include "Term_structure_flat.h"

Term_structure_flat::Term_structure_flat(const double& r){ R_ = r; };
Term_structure_flat::~Term_structure_flat(){};
double Term_structure_flat::r(const double& T) const { if (T>=0) return R_ ; return 0; };
void Term_structure_flat::set_int_rate(const double& r) { R_ = r; };

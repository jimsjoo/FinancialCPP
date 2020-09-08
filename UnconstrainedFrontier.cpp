#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "newmat10\newmat.h"
#include "newmat10\newmatio.h"                // need matrix output routines

using namespace std;

ReturnMatrix mv_portfolio_given_mean_unconstrained(const Matrix& e, const Matrix& V, const double& r){
  
  int no_assets=e.Nrows();
  
  Matrix ones = Matrix(no_assets,1); 
  
  for (int i=0; i<no_assets; ++i){
    ones.element(i,0) = 1; 
  };
   
  Matrix Vinv = V.i(); // inverse of V
  
  Matrix A = (ones.t()*Vinv*e); 
  double a = A.element(0,0);
  
  Matrix B = e.t()*Vinv*e; 
  double b = B.element(0,0);
  
  Matrix C = ones.t()*Vinv*ones; 
  double c = C.element(0,0);
  
  double d = b*c - a*a;
  
  Matrix Vinv1=Vinv*ones;
  Matrix Vinve=Vinv*e;
  
  Matrix g = (Vinv1*b - Vinve*a)*(1.0/d);
  Matrix h = (Vinve*c - Vinv1*a)*(1.0/d);
  Matrix w = g + h*r;
  
  w.Release();
  return w;
};

int main(int argc, char** argv) {
  cout << "Testing portfolio calculation " << endl;
  Matrix e(2,1);
  e(1,1)=0.05; 
  e(2,1)=0.1;
  
  Matrix V(2,2);
  V(1,1)=1.0; V(2,1)=0.0;
  V(1,2)=0.0; V(2,2)=1.0;
  
  double r=0.075;
  Matrix w = mv_portfolio_given_mean_unconstrained(e,V,r);
  cout << " suggested portfolio: ";
  cout << " w1 = " << w(1,1) << " w2 = " << w(2,1) << endl;
  
	return 0;
}

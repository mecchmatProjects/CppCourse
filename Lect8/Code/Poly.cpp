#include <cstring>       // memmove, memcpy
#include "Poly.h"

Poly::Poly(){
    n=0; a = nullptr;
};

Poly::Poly(unsigned m){
    n = m;
    a = new double[n];
}

Poly::Poly(unsigned n, double* ptr_a){
   this->n =n;
   a = new double[n];
   memmove(a, ptr_a, sizeof(*a)*n);
}

Poly::~Poly(){
   delete[] a;
}

Poly::Poly(const Poly& p){
   n = p.n;
   a = new double[n];
   memmove(a, p.a, n*sizeof(*a));
}


double Poly::value(double x){
   if (n==0) {std::cerr<<"Empty Polynome"; return 0;};
   double res = a[0];
   for(unsigned i=1;i<n;++i){
          res *= x;
          res += a[i];
   }
   return res;
}

void Poly::show(){
     std::clog<<"P{";
     for(unsigned i=0;i<n;++i){
        std::clog<<a[i]<<", ";
     }
     std::clog<<"}\n";
}
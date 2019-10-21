#include "Monomial.h"

Monomial::Monomial()
{
    count++;
}

Monomial::~Monomial()
{
    count--;
}

double Monomial::power(double x, unsigned n){    
    if(n==1) return x;
   
    double res = power(x, n/2);
    if(n & 1){
        return x*res*res;
    }
    return res * res;    
}


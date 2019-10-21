#ifndef POLY_H
#define POLY_H
#include <iostream>

/*
 * Class Polynome
 * */
class Poly{
   unsigned n; ///< size of Polynome
   double* a;  ///< array of Polynome coefficients
public:
    // default constructor: create empty polynome
    Poly();
    /* constructor: create polynome of given size
     * @params:
     * unsigned n - size of polynome
     **/ 
    Poly(unsigned n);
    /* constructor: create polynome with given array
     * P(x) = a_0 * x^n-1 + a_1*x^n-2 + ... + a_n-1 
     * @params:
     * unsigned n - size of polynome
     * double* ptr_a - array of coefficients a_0, a_1,...,a_n
     **/
    Poly(unsigned n, double* ptr_a);
    // destructor: free memory
    ~Poly();
    /* copy-constructor: create another polynome from the given
     * @params:
     * Poly p - polynome 
     */ 
    Poly(const Poly& p);
    /* Calculate the value of the polynome
     * @params:
     * double x - argument of polynome 
     * */
    double value(double x);
    // display polynome
    void show();

};

#endif // POLY_H   (empty line at the end!!!)

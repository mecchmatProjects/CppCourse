#ifndef GRAM_H
#define GRAM_H

/*Class to represent a * x^n - 
 * */
class Monomial{
private:
    int deg;
    double aval;
    static int count;
public:

    Monomial();
    ~Monomial();
    Monomial(int n, double a): deg(n),aval(a){ count++;};
    
    static int show_count(){
            return count;
    }
    
    static double power(double x, unsigned n);
    
    static double pi()
        { return 3.14159265; }
    
    void setDegree(int m){
        deg = m;
    }
    
    void setAval(double p){
        aval = p;
    }
    
    int getDegree(){
        return deg;
    }
    
    double getAval(){
        return aval;
    }
    
    double value(double x){
        return aval*power(x, deg);
    }
    

};


#endif // GRAM_H

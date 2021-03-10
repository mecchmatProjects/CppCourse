#include <stdio.h>
#include <math.h> // fabs(x) == |x|
#include <float.h>

int almost_equal( double d1, double d2){
   return fabs(d1-d2)< DBL_EPSILON * (d1+d2); // 0.000001; // 
}


int main(){
    double d1 = 5.0;
    double d2 = sqrt(5) * sqrt(5);
    printf("d1=%lf d2=%lf\n", d1,d2);
   /*
    if(d1 == d2)
        printf("d1 equals d2\n");
    else
        printf("d1 does not equal d2 !!!!!!!!!!!!!!\n");
   */
   printf("d1=%.15lf d2=%.15lf\n", d1,d2);
    
    if(almost_equal(d1, d2))
        printf("d1 equals d2\n");
    else
        printf("d1 does not equals d2\n");
   
}

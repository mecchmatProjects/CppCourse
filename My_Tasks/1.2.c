//1.2
#include <stdio.h>
#include <math.h>

int main()
{
    float f = pow(10, -4);
    double d = 24.33*0.000023;
    long double ld = pow(10, -4);
    
    printf( "number1 = %.2lf ", f );
	printf( "number2 = %.2lf ", 24.33*0.000023 );
	printf( "number3 = %.2lf ", M_PI ); 
	printf( "number4 = %.2lf ", exp(1));
	printf( "number5 = %.2lf ", log(2));
	
	return 0;
}

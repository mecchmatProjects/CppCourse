/* Optional, but recommended: Documentation section
   i.e. comments, that describe the program, like: 
   First C-style program */
#include <stdio.h> // headers (Link section)
#include <math.h>


#include <locale.h>

#include <float.h>
int main_float() {
   printf("Storage size for float : %ld \n", sizeof(float));
   printf("Minimum float positive value: %E\n", FLT_MIN );
   printf("Maximum float positive value: %E\n", FLT_MAX );
   printf("Precision value: %d\n", FLT_DIG );
   
   return 0;
}

//Definition Section and Global declaration section
int main31() // main function: entry point
{
    /*
    float x; //define real variable 'x'
    scanf("%F",&x); // input 'x'
    double y=sin(x); // expression: calculate y
	printf("Result y=%f\n",y); // output
    
    double z; //define real variable 'x'
    scanf("%lf",&z); // input 'z'
       
    
    printf ("floats: %2.4f %+.0e %G \n", x,x,x);
    printf ("Width trick: %*f \n", 5, y);
    printf ("double: % 2.4f %+.0e %E \n", y,y,y);
    
    printf ("floatsA: %02.4a %+.0a %A \n", y,y,y);*/
    printf("abc=\n");
    double a,b;
    double a1,b1,c1;
    int d,d1;
    
    d = scanf("%5lf%5lf",&a,&b);
    printf("%d vars:\n\n a=%f, b=%e, c=%f",d,a,b,1.0);

    d1 = scanf("a=%5lf%*f, b=%le, c=%lf",&a1,&b1,&c1);
    printf("a%f, b%e, c%f",a,b,1.0);
    printf("---------------- \n");
    printf("| %-.2f | %-.2f | %-.2f | %-.2f |\n",sqrt(1),sqrt(2),sqrt(3),sqrt(4));
    printf("d=%d abc=%f",d1,a1*b1*c1);
    
    
    float x=234.5345345;
    //scanf("%5f",&x);
    
    printf("\n*******%-.1e*******%-3.3f",x,x);
    printf("\n%3.3f*******%03.3f*******",x,x);
    
    
	return 0; // optional
}
 
 
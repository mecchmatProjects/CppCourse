#include <stdio.h>   

typedef union {
          float f;
          struct {
              unsigned int mantissa : 23;
              unsigned int exponent : 8;
              unsigned int sign :     1;
          } parts;
} float_cast;


int isZero(float num) {

    int flag = 0;
    float_cast data;
    data.f = num;

    // Check both exponent and mantissa parts
    if(data.parts.exponent == 0u && data.parts.mantissa == 0u) {
       flag = 1;
    } else {
       flag = 0;
   }

   return(flag);
}

void test() {
     int i =0;
     float e = 1.f, small = 1.f;
     for(i = 0; i < 40; i++) {
         e *= 10.f;
         small = 1.f/e;
         printf("\nis %e zero? : %d", small, isZero(small));
     }
     return;
}

int main() {

   float num1 = 0.f, num2 = -0.f, num3 = 1.2f;

   printf("\n is zero of %f -> %d", num1, isZero(num1));
   printf("\n is zero of %f -> %d", num2, isZero(num2));
   printf("\n is zero of %f -> %d", num3, isZero(num3));

   return(0);
}

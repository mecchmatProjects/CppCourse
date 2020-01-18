#include <stdio.h>
#include <inttypes.h>

#include <limits.h>

void fun_int_consts(void)
{
    
    //    int x = 0xE+2;   // error
    int y = 0xa+2;   // OK
    int z = 0xE +2;  // OK
    int q = (0xE)+2; // OK
    
    printf("123 = %d\n", 123);
    printf("0123 = %d\n", 0123);
    printf("0x123 = %d\n", 0x123);
    printf("12345678901234567890ull = %llu\n", 12345678901234567890ull);
    // the type is a 64-bit type (unsigned long long or possibly unsigned long)
    // even without a long suffix
    printf("12345678901234567890u = %"PRIu64"\n", 12345678901234567890u);
//  printf("%lld\n", -9223372036854775808); // ERROR
// the value 9223372036854775808 cannot fit in signed long long, which is the
// biggest type allowed for unsuffixed decimal integer constant
    printf("%llu\n", -9223372036854775808ull );
    // unary minus applied to unsigned value subtracts it from 2^64,
    // this gives unsigned 9223372036854775808 
    printf("%lld\n", -9223372036854775807ull - 1);
    // correct way to form signed value -9223372036854775808
}


int fun_num_limits() {

   printf("The number of bits in a byte %d\n", CHAR_BIT);

   printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
   printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
   printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

   printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
   printf("The maximum value of SHORT INT = %d\n", SHRT_MAX); 

   printf("The minimum value of INT = %d\n", INT_MIN);
   printf("The maximum value of INT = %d\n", INT_MAX);

   printf("The minimum value of CHAR = %d\n", CHAR_MIN);
   printf("The maximum value of CHAR = %d\n", CHAR_MAX);

   printf("The minimum value of LONG = %ld\n", LONG_MIN);
   printf("The maximum value of LONG = %ld\n", LONG_MAX);
  
   return(0);
}

int main(){
   fun_int_consts();
   fun_num_limits();
}

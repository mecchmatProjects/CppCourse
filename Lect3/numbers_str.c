#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
   float valf;    double vald;
   int vali;   unsigned valu; 
   long long vall;   char str[20];
   char* str_2[2]; 
   strcpy(str, "98993489");
   valf = atof(str);
   vald = strtod(str, NULL);
   vali = atoi(str);
   vall = strtoll(str, NULL, 0); 
   printf("String value = %s, Float value = %f, Double value = %lf, int value = %d, long value =%llu \n", str, valf, vald, vali, vall);
   strcpy(str, "124.0text");
   valf = atof(str);
   vald = strtod(str, &str_2[0]);
   vall = strtoll(str, &str_2[1], 0);

   printf("String value = %s, Float value = %f, double val %lf, remain= %s", str, valf, vald, str_2[0]);
   return(0);
}


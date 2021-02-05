#include <stdio.h> 

int main()
{
   int tr, fal;
   tr=(11<=15); /* вираз істинний */
   fal=(1>1); /* вираз хибний */
   printf("true= - %d false - %d, and=%d, or=%d ", tr, fal, tr && fal, tr || fal);
   return 0;
}

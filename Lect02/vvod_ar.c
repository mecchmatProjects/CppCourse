
/* task 1_2.13 */

#include <stdio.h>
#include <math.h>

int main(){

  int i=0;
  double sum = 0;
  double x;
  double eps=1e-53;

  do{
    printf("a[%d]=",i);
    scanf("%lf",&x);
    sum +=x;
    i++;
  } while(fabs(x)>eps);
 
 printf("sum = %lf",sum);


}

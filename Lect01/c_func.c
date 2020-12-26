
#include <stdio.h>
//#include <math.h>


double func1(double x){
  double y = x*x+1;  
  return y*y;
}


double func2(double x, double y){
  double z = x+y; 
  
  return z*z*z;
}

int main(){

  double x,y;
  printf("x=");
  scanf("%lf",&x);

  printf("y=");
  scanf("%lf",&y);


  double z = func1(x);

  printf("\n z=%lf",z);

  z = func2(x,y);

  printf("\n z2=%lf",z);

}



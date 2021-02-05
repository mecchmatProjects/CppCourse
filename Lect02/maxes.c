

#include <stdio.h>

int max1(int a, int b){
   if (a>b) return a;
   //else 
      return b;
}


int max2(int a, int b){

   return a>b?a:b;
}

int main(){

  int a,b;

  scanf(" %d %d", &a, &b);

  printf("m1=%d, m2=%d",max1(a,b),max2(a,b));

}

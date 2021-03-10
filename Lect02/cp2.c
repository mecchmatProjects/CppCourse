#include <stdio.h>

int main(){

  unsigned n;
  printf("n=");
  scanf("%u",&n);

  unsigned a,b,c,s;
  if((n>=100) && (n<=999)){
    a= n%10;
    b = (n/10)%10;
    c = n/100;

    s = a+b+c;
    unsigned m = 100*a +10*b + c;

    printf("%u, %u, %u;  %u, %u",c,b,a,s,m); 
  }
/*
  long y1;
  long long y2;

  printf("\n sizes = int=%lu, long= %lu, long long= %lu",sizeof(int),sizeof(y1),sizeof(y2));
*/
}


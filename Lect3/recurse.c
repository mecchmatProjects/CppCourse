#include <stdio.h>

long long factorial(int n)
{
if (n==0 || n==1) return 1;
else return n*factorial(n-1);
}

int mult (int a, unsigned b);
unsigned gcd(unsigned x, unsigned y);

int main(){
int x;
printf("Ввести число x=");scanf("%d",&x);
printf("Факторіал x!=%Ld",factorial(x));
unsigned y;
printf("Ввести натуральне y=");scanf("%u",&y);
printf("Сума=%d",mult(x,y));
printf("НСД=%u",gcd(x,y));
}


int mult(int a, unsigned b) {
int S;
if (b==0) S=a;
else S=b+mult(a,b-1);
return S;
}

unsigned gcd(unsigned x, unsigned y){
  if(y==0) return x;
  return gcd(y,x%y);
}
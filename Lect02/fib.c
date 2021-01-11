// задача 30

#include <stdio.h> 
int main(){ 
 int F0=0, F1=1, n, Fn; // F0=0, F1=1, Fn - n-th Fibonacci number 
 
 scanf("%d",&n); 
 for (int i = 2;i<=n;i++){ 
  Fn = F0 + F1;  // F_n+1 = F_n + F_n-1
  F0 = F1;   // 1,1,2,3,5...
  F1 = Fn;   // 1,2,3,5,8... 
} 

  printf("%d",Fn); 

} 

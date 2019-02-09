#include <iostream>
#include <cmath>

int f(){
   double x, y, z;
   std::cin>>x>>y;
   z = exp(x)*cos(y);
   printf("z=%lf",z);
}


int main(int argc, char **argv)
{
   int x;
   std::cin>>x;
   int y =2*x+1;
   std::cout<<"y="<<y;
   
   f();
}

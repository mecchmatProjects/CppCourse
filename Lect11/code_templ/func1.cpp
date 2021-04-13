#include <iostream>
template <typename T=int> T func(T x, int y){
 T res = x / y;
 return res;
}

int main(){
 int x=11,y=2,z;
 double a=11.0,b,c;
 z  = func(x,y);  // 5
 b = func<double>(x,y); // 5.5
 c= func(a,y); // 5.5
 std::cout<<z<<b<<c;
}

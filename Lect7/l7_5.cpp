#include <iostream>
#include <cmath>

int main() { 
double x; 
std::cout.precision(4); 
std::cout.fill('0'); 
std::cout << " x / Корінь(x)"<<std::endl; 
for (x = 1.0; x <= 6.0; x++) { 
   std::cout.width(7);
   std::cout << x << " ";
   std::cout.width(7); 
   std::cout << sqrt(x) << " \n"; 
}
 }

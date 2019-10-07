#include <iostream>
using namespace std;

int main() { 
 double d = 3.124e7; 
 int n = 25; 
 cout << "d = " << d << " "; 
 cout << "n = " << n << ""; 
 cout.setf(ios::hex | ios::uppercase); 
 cout.setf(ios::showpos); 
 cout << "d = " << d << "";
 cout << "n = " << n << ""; 
}

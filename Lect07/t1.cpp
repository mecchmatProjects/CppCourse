#include <iostream> 
#include <cmath> 
#include <iomanip>
using namespace std; 
int main() { 
  int n;
  cin >> n; 
  long long mas[n];
  double y; 
  for(int i = 0; i < n; i++){ 
   cin >> mas[i]; 
  } 
  for(int i = n-1; i >= 0; i--){ 
   y = sqrt(mas[i]);
   cout << fixed; 
   cout.precision(4); cout << y << endl; 
   //cout<<setprecision(4)<<setfill('0')<< y << endl; 
 } 
 return 0; 
 } 

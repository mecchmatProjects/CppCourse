  // Сума елементів
#include <iostream>
#include <numeric>   // для алгоритмів
using namespace std; 
int accum1_massiv()
{   const int N = 8;
int a[N] = {4, 12, 3, 6, 10, 7, 8, 5}, sum = 0;
sum = accumulate(a, a+N, sum);
cout << "Sum of all elements:  " << sum << endl;
cout << "1000 + a[2] + a[3] + a[4]  = " 
 << accumulate(a+2, a+5, 1000) << endl;
return 0;
}

int accum2_massiv()
{   const int N = 4;
int a[N] = {2, 10, 5, 3}, prod =  1; 
prod = accumulate(a, a+N, prod, multiplies<int>());
cout << "Product of all elements: " << prod << endl; 
return  0;
} 

class  fun  
{    
 public:
           fun(){i = 1;}
           int  operator()(int x, int y)
           {   int u = x + i * y;   i *= 2;   
   return u; }
      private:
           int  i;
}; 

int accum3_massiv() 
   {   
   const int N = 4;
     int a[N] = {7, 6, 9, 2},
     prod = 0; 
     prod =  accumulate(a, a+N, prod, fun()); 
     cout << prod << endl;
     return  0; 
     }

int main(){
accum1_massiv();
accum2_massiv();
accum3_massiv();
}


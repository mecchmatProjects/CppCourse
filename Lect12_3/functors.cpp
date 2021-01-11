#include <bits/stdc++.h> 
using namespace std; 
   
int increment(int x) {  return (x+1); } 

// A Functor 
class increment 
{ 
private: 
    int num; 
public: 
    increment(int n) : num(n) {  } 
  
    // This operator overloading enables calling 
    // operator function () on objects of increment 
    int operator () (int arr_num) const { 
        return num + arr_num; 
    } 
}; 


bool comparefun(int x, int y) 
{   return x > y;
}

int dsort1()
{   const  int N =  8; 
int a[N]={1234,5432,8943,3346,9831,7842,8863,9820}; cout << "Before  sorting: \n"; 
copy(a, a+N, ostream_iterator<int> (cout, " ") ) ; 
cout  <<  endl;
sort (a, a+N, comparefun); 
cout << "After sorting in descending order:\n"; 
copy(a, a+N, ostream_iterator<int>(cout, " ")); 
cout  <<  endl;
return  0; 
}

class compare 
{    	public: 
	bool operator() (int x, int y) const
		{   return x > y; } 
};
int funobj()
{   compare v; 
cout << v(2, 15) << endl; // Виведення:  0
cout << compare()(5, 3) << endl;  // Виведення:  1
cout << endl;
return 0; 
}

int dsort2() 
{   const int N = 8; 
int a[N] ={1234,5432,8943,3346,9831,7842,8863,9820};
cout << "Before sorting:\n";
copy(a, a+N, ostream_iterator<int>(cout,  " ")); 
cout << endl;  
sort (a, a+N, compare());
cout << "After sorting in descending order:\n"; 
copy(a, a+N, ostream_iterator<int>(cout,  " ")); 
cout << endl;
return 0; }

   
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
   
    // Apply increment to all elements of 
    // arr[] and store the modified elements 
    // back in arr[] 
    transform(arr, arr+n, arr, increment); 
   
    for (int i=0; i<n; i++) 
        cout << arr[i] << S" ";
 
   
    int to_add = 5; 
  
    transform(arr, arr+n, arr, increment(to_add)); 
  
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
} 

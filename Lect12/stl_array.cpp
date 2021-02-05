// C++ code to demonstrate working of array, 
// to() and get() 
#include<iostream> 
#include<array> // for array, at() 
#include<tuple> // for get() 
using namespace std; 

template<typename T, size_t n> void printArray(const array<T, n> & v){
  for(const auto & it: v){
     cout<<" "<< it;
  }
 cout << endl; 	
}

int main(){ 
// Initializing the array elements 
array<int,6> ar = {1, 2, 3, 4, 5, 6}; 

// Printing array elements using at() 
cout << "The array elemets are (using at()) : " << ar.at(1); 
 
// Printing array elements using get() 
cout << "The array elemets are (using get()) : "; 
cout << get<0>(ar) << " "<< get<1>(ar) << " "; 
cout << get<2>(ar) << " "<< get<3>(ar) << " "; 
cout << get<4>(ar) << " "<< get<5>(ar) << " "; 
cout << endl; 

// Initializing the array elements 
array<int,6> ar1{ {1, 2, 3, 4, 5, 6} }; 

// Printing first element of array 
cout << "First element of array is : "; 
cout << ar1.front() << endl; 

// Printing last element of array 
cout<< "Last element of array is : "; 
cout << ar1.back() << endl; 

// Initializing the array elements 

unsigned mas[] ={1, 2, 3, 4};

array<unsigned,4> ar2; // to_array<unsigned>(mas); //c++20
for(int i =0; i<ar2.size();++i)
  ar2[i] = mas[i];


// Printing number of array elements 
cout << "The number of array elements is : "; 
cout << ar2.size() << endl; 

// Printing maximum elements array can hold 
cout << "Maximum elements array can hold is : "; 
cout << ar2.max_size() << endl; 


// Initializing 1st array 
array<char,6> ar3 = {'1', '2', '3', '4', '5', '6'}; 

// Initializing 2nd array 
array<char,6> ar4{ {'7', '8'} }; 

// Printing 1st and 2nd array before swapping 
cout << "The first array elements before swapping are : "; 
printArray<char,6>(ar3);
cout << "The second array elements before swapping are : "; 
printArray<char,6>(ar4);
// Swapping ar1 values with ar 
ar4.swap(ar3); 

// Printing 1st and 2nd array after swapping 
cout << "The first array elements after swapping are : "; 
printArray<char,6>(ar3);
cout << "The second array elements after swapping are : "; 
printArray<char,6>(ar4);

// Declaring 1st array 
array<double,0> ar5; 

// Declaring 2nd array 
array<double,5> ar6; 

// Checking size of array if it is empty 
ar5.empty()? cout << "Array empty": cout << "Array not empty"; 
cout << endl; 

// Filling array with 1.0 
ar6.fill(1.0); 

// Displaying array after filling 
cout << "Array after filling operation is : "; 
printArray<double,5>(ar6);
}


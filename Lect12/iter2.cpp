#include<iostream>
#include<iterator> // for iterators
#include<vector> // for vectors
int main() {
std::vector<int> ar{1,2,3,4,5};
std::vector<int> ar1{10,20,30};
std::vector<int>::iterator ptr = ar.begin();
std::advance(ptr, 3);
std::copy(ar1.begin(), ar1.end(), inserter(ar,ptr));
std::cout << "The new vector after inserting elements is : ";
for(int &x:ar)std::cout << x <<" ";
}

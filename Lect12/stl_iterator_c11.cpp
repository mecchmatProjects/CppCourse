#include<iostream> 
#include<iterator> // for iterators 
#include<vector> // for vectors 
using namespace std; 

typename <class Coll>
void printColl(const Coll & v){
 for(const auto & x: v){
  cout<< x <<" ";
}
cout<<endl;
}

int main(){ 
vector<int> ar = { 1, 2, 3, 4, 5 }; 

// Declaring iterators to a vector 
vector<int>::iterator ptr = begin(ar); 
vector<int>::iterator ftr = end(ar); 

// Using next() to return new iterator 
// points to 4 
auto it = next(ptr, 3); 

// Using prev() to return new iterator 
// points to 3 
auto it1 = prev(ftr, 3); 

// Displaying iterator position 
cout << "The position of new iterator using next() is : "; 
cout << *it << " "; 
cout << endl; 

// Displaying iterator position 
cout << "The position of new iterator using prev()  is : "; 
cout << *it1 << " "; 
cout << endl; 

  int foo[] = {10,20,30,40,50, 60};
  std::vector<int> bar;

  // iterate foo: inserting into bar
 // be carefull - this fails if size of collection is odd!!!!!
  for (auto it = std::begin(foo); it!=std::end(foo); advance(it,2))
    bar.push_back(*it);

  // iterate bar: print contents:
  std::cout << "bar contains:";
  /*for (auto it = std::begin(bar); it!=std::end(bar); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
*/
  for(auto &x:bar)std::cout << x <<" ";
}

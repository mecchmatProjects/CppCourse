#include<iostream>
#include<iterator> // for iterators
#include<vector> // for vectors

template<class Coll>
void printCollect(Coll v){
  template Coll::const_iterator it = v.begin();
  for(;it!=v.end();++it){
    std::cout<<*it<<" ";
 } 

}

int main() {
std::vector<int> ar{1,2,3,4,5};
std::vector<int> ar1{10,20,30};
std::vector<int>::iterator ptr = ar.begin();
std::advance(ptr, 3);
//ptr += 3;
std::copy(ar1.begin(), ar1.end(), inserter(ar,ptr));
std::cout << "The new vector after inserting elements is : ";
printCollect(ar1);


vector<int> ar = { 1, 2, 3, 4, 5 }; 
vector<int> ar1 = {10, 20, 30};  

// Declaring iterator to a vector 
vector<int>::iterator ptr = ar.begin(); 

// Using advance to set position 
advance(ptr, 3); 

// copying 1 vector elements in other using inserter() 
// inserts ar1 after 3rd position in ar 
copy(ar1.begin(), ar1.end(), inserter(ar,ptr)); 

// Displaying new vector elements 
cout << "The new vector after inserting elements is : "; 
printCollect(ar1); 



  std::deque<int> foo,bar;
  for (int i=1; i<=5; i++){ foo.push_back(i); bar.push_back(i*10); }

  std::copy (bar.begin(),bar.end(),std::front_inserter(foo));

  std::cout << "foo contains:";
  /*for ( std::deque<int>::iterator it = foo.begin(); it!= foo.end(); ++it )
          std::cout << ' ' << *it;
  std::cout << '\n';*/
printCollect(foo);


  std::vector<int> foo1,bar1;
  for (int i=1; i<=5; i++)
  { foo1.push_back(i); bar1.push_back(i*10); }

  std::copy (bar1.begin(),bar1.end(),back_inserter(foo1));

  std::cout << "foo contains:";
/*  for ( std::vector<int>::iterator it = foo.begin(); it!= foo.end(); ++it )
          std::cout << ' ' << *it;
  std::cout << '\n';
*/
printCollect(foo1);

    std::vector<int> v{ 3, 1, 4 };
    std::cout << "distance(first, last) = "
              << std::distance(v.begin(), v.end()) << '\n'
              << "distance(last, first) = "
              << std::distance(v.end(), v.begin()) << '\n';
               //the behavior is undefined (until C++11)
 /*
    static constexpr auto il = { 3, 1, 4 };
    // Since C++17 `distance` can be used in constexpr context.
    static_assert(std::distance(il.begin(), il.end()) == 3);
    static_assert(std::distance(il.end(), il.begin()) == -3);
*/
}

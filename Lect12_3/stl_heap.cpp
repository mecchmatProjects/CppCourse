// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
#include <functional>

int main () {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end(), std::greater<int>()); 
  // deafault is less<T> and v.front() is max 
  std::cout << "initial min heap   : " << v.front() << '\n';

  std::pop_heap (v.begin(),v.end(),std::greater<int>());
  v.pop_back(); 
  // default heap would be max
  std::cout << "min heap after pop : " << v.front() << '\n';

  v.push_back(3); 
  // without push_heap() element won't be placed in the heap-tree 
  std::push_heap (v.begin(),v.end(), std::greater<int>());
  // default heap would be max
  std::cout << "max heap after push: " << v.front() << '\n';
  // sort is done on heap-tree so without predicate here it won't sort
  std::sort_heap (v.begin(),v.end(), std::greater<int>());

  std::cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';

  // c++11 methods
  std::vector<int> foo {9,5,2,6,4,1,3,8,7};
  if (!std::is_heap(foo.begin(),foo.end()))
    std::make_heap(foo.begin(),foo.end());

  std::cout << "Popping out elements:";
  while (!foo.empty()) {
    std::pop_heap(foo.begin(),foo.end());   // moves largest element to back
    std::cout << ' ' << foo.back();         // prints back
    foo.pop_back();                         // pops element out of container
  }
  std::cout << '\n';

 
}

#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector

template<typename T>
void myfunction (T i) {  // функція над елементом послідовності
  std::cout << " " << ((i>0)?"positive ":"negative ");
}

template<typename T>
bool myEqual (T x, T y) {
  return (x-y)*(x-y)<0.0001;
}

bool IsOdd (int i) { return ((i%2)==1); }

int main () {
  double mas[] = {1.0, 2.0, -4.0, 3.0 }; 
  std::vector<int> myvector(mas,mas+4);

  std::cout << "myvector signs:";
  std::for_each (myvector.begin(), myvector.end(), myfunction<int>);
  std::cout << "\narray signs:";
  std::for_each (mas, mas+4, myfunction<double>);

  std::cout<<"\n";
  int myints[] = { 10, 20, 30, -40, 30, 30};
  int * p;

  p = std::find (myints, myints+5, 30);
  if (p != myints+5)
    std::cout << "Element found in myints: " << *p << '\n';
  else
    std::cout << "Element not found in myints\n";

  // using std::find with vector and iterator:
  /*double mas[] = {1.0, 2.0, -4.0, 3.0}; 
  std::vector<int> myvector(mas,mas+4);*/
  std::vector<int>::iterator it;

  it = std::find (myvector.begin(), myvector.end(), 30);
  if (it != myvector.end())
    std::cout << "Element found in myvector: " << *it << '\n';
  else
    std::cout << "Element not found in myvector\n";


  float myarr[] = {5.0f,2.f,5.0f,3.0f,2.9999f,2.0f,1.0f,1.0001f,2.0f};
  std::vector<float> myvector2 (myarr,myarr+8);
  std::vector<float>::iterator it2;
  std::vector<int> myvector3(myarr,myarr+8);// 5,2,5,3,2,2,1,1
  std::vector<int>::iterator it3;

  // using default comparison:
  it3 = std::adjacent_find (myvector3.begin(), myvector3.end());

  if (it3!=myvector3.end())
    std::cout << "the first value of repeated elements are: " << *it3 << '\n';

  //using predicate comparison:
  it2 = std::adjacent_find (myvector2.begin(), myvector2.end(), myEqual<float>);

  if (it2!=myvector2.end())
    std::cout << "the first value of almost repeated elements are: " << *it2 << '\n';

  int mycount = std::count (myints, myints+6, 30);
  std::cout << "10 appears " << mycount << " times.\n";

  // counting elements in container:
  //std::vector<int> myvector (myints, myints+8);
  mycount = std::count (myvector.begin(), myvector.end(), 20);
  std::cout << "20 appears " << mycount  << " times.\n";

  std::vector<int> myvector4;
  for (int i=1; i<10; i++) myvector4.push_back(i); // myvector: 1 2 3 4 5 6 7 8 9

  mycount = count_if (myvector4.begin(), myvector4.end(), IsOdd);
  std::cout << "myvector contains " << mycount  << " odd values.\n";

}

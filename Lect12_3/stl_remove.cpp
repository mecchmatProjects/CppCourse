
#include <iostream>     // std::cout
#include <algorithm>    // std::remove_if
#include <vector>

bool IsPower2 (unsigned i) { return (i & (i-1)) == 0; }

template <class T>
void printIntVector(T a, 
                    T b){
     std::cout << "the range contains:";
     while(a!=b){
          std::cout<<*a<<", ";
          ++a; 
     }
  std::cout << '\n';
}

int main () {
  unsigned myints[] = {1,2,3,4,5,6,7,8,9};            // 1 2 3 4 5 6 7 8 9

  // bounds of range:
  unsigned* pbegin = myints;                          // ptr to 1
  unsigned* pend = myints+sizeof(myints)/sizeof(int); // ptr after 9

  pend = std::remove_if (pbegin, pend, IsPower2);   // 2 4 6 8 ? ? ? ? ?
 
  printIntVector(pbegin, pend);
  unsigned myints2[] = {10,20,30,30,20,10,10,20};      // 10 20 30 30 20 10 10 20

  // bounds of range:
  pbegin = myints2;                          // ^
  pend = myints2+sizeof(myints2)/sizeof(unsigned); // ^                       ^

  pend = std::remove (pbegin, pend, 20);         // 10 30 30 10 10 ?  ?  ?
    printIntVector(pbegin, pend);
   unsigned myints3[] = {1,2,3,4,5,6,7,8,9};
  std::vector<unsigned> myvector (9);

  std::remove_copy_if (myints,myints+9,myvector.begin(), IsPower2);

    printIntVector(myvector.begin(), myvector.end());
}

// transform algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus
#include <random>
#include <ctime>

int op_increase (int i) { return ++i; }

bool IsOdd (int i) { return ((i%2)==1); }

// function generator:
int RandomNumber () { return (std::rand()%100); }

// class generator:
struct c_unique {
  int current;
  c_unique() {current=0;}
  int operator()() {return ++current;}
} UniqueNumber;



int main () {
  std::vector<int> foo;
  std::vector<int> bar;

  // set some values:
  for (int i=1; i<6; i++)
    foo.push_back (i*10);                         // foo: 10 20 30 40 50

  bar.resize(foo.size());                         // allocate space

  std::transform (foo.begin(), foo.end(), bar.begin(), op_increase);
                                                  // bar: 11 21 31 41 51

  // std::plus adds together its two arguments:
  std::transform (foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
                                                  // foo: 21 41 61 81 101

  std::cout << "foo contains:";
  for (std::vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';


  std::vector<int> myvector (8,10);        // myvector: 10 10 10 10 10 10 10 10

  std::fill_n (myvector.begin(),4,20);     // myvector: 20 20 20 20 10 10 10 10
  std::fill_n (myvector.begin()+3,3,33);   // myvector: 20 20 20 33 33 33 10 10

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::fill (myvector.begin(),myvector.begin()+4,5);   // myvector: 5 5 5 5 0 0 0 0
  std::fill (myvector.begin()+3,myvector.end()-2,8);   // myvector: 5 5 5 8 8 8 0 0

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';


std::srand ( unsigned ( std::time(0) ) );

  std::vector<int> myvector1 (8);

  std::generate (myvector1.begin(), myvector1.end(), RandomNumber);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector1.begin(); it!=myvector1.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::generate (myvector1.begin(), myvector1.end(), UniqueNumber);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector1.begin(); it!=myvector1.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

int myints[] = {1,2,3,4,5,6,7,8,9};            // 1 2 3 4 5 6 7 8 9

  // bounds of range:
  int* pbegin = myints;                          // ^
  int* pend = myints+sizeof(myints)/sizeof(int); // ^                 ^

  pend = std::remove_if (pbegin, pend, IsOdd);   // 2 4 6 8 ? ? ? ? ?
                                                 // ^       ^
  std::cout << "the range contains:";
  for (int* p=pbegin; p!=pend; ++p)
    std::cout << ' ' << *p;
  std::cout << '\n';
  int myints0[] = {10,20,30,30,20,10,10,20};      // 10 20 30 30 20 10 10 20

  // bounds of range:
  pbegin = myints0;                          // ^
  pend = myints0+sizeof(myints)/sizeof(int); // ^                       ^

  pend = std::remove (pbegin, pend, 20);         // 10 30 30 10 10 ?  ?  ?
                                                 // ^              ^
  std::cout << "range contains:";
  for (int* p=pbegin; p!=pend; ++p)
    std::cout << ' ' << *p;
  std::cout << '\n';
//int myints[] = {1,2,3,4,5,6,7,8,9};
  std::vector<int> myvector2 (9);

  std::remove_copy_if (myints,myints+9,myvector2.begin(),IsOdd);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector2.begin(); it!=myvector2.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

int myints2[] = {10,20,20,20,30,30,20,20,10};           // 10 20 20 20 30 30 20 20 10
  std::vector<int> myvector3 (myints,myints+9);

  // using default comparison:
  std::vector<int>::iterator it;
  it = std::unique (myvector3.begin(), myvector3.end());   // 10 20 30 20 10 ?  ?  ?  ?
                                                         //                ^

  myvector3.resize( std::distance(myvector3.begin(),it) ); // 10 20 30 20 10

  // using predicate comparison:
  std::unique (myvector3.begin(), myvector3.end(), [](int x, int y)->bool{return x*x==y*y;});   // (no changes)

  // print out content:
  std::cout << "myvector contains:";
  for (it=myvector3.begin(); it!=myvector3.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  // using default comparison:
  //std::vector<int>::iterator it;
  it=std::unique_copy (myints2,myints2+9,myvector3.begin());   // 10 20 30 20 10 0  0  0  0
                                                            //                ^

  std::sort (myvector3.begin(),it);                          // 10 10 20 20 30 0  0  0  0
                                                            //                ^

  // using predicate comparison:
  it=std::unique_copy (myvector3.begin(), it, myvector3.begin(), [](int x, int y)->bool{return x/2==y/2;});
                                                            // 10 20 30 20 30 0  0  0  0
                                                            //          ^

  myvector.resize( std::distance(myvector3.begin(),it) );    // 10 20 30

  // print out content:
  std::cout << "myvector contains:";
  for (it=myvector3.begin(); it!=myvector3.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::vector<int> v({1,2,3});
    std::for_each(std::begin(v), std::end(v),
                  [&](int value){ std::cout << value << " "; });
    std::cout << std::endl;
 
    std::vector<int> destiny(3);
    std::reverse_copy(std::begin(v), std::end(v), std::begin(destiny));
    std::for_each(std::begin(destiny), std::end(destiny),
                  [&](int value){ std::cout << value << " "; });
    std::cout << std::endl;
 

  return 0;
}

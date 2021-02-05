#include <iostream>     // std::cout, ostream_iterator
#include <algorithm>    // std::copy
#include <vector>       // std::vector
#include <iterator>     //ostream_iterator
using namespace std;
template<class V,typename T> void printCont(const V & s, T val){
    copy (s.begin(), s.end(),  ostream_iterator<T>(cout, " ,"));  
   cout<<endl;    
}

int main () {
  int myints[]={10,20,30,40,50,60,70};
  vector<int> myvector (7);
  vector<int> myvector2(8);

  copy( myints, myints+7, myvector.begin() );
  cout << "myvector contains:";
  printCont(myvector, myvector.at(0)); 
  cout<<"\n"; 
  copy_backward( myvector.begin()+3, myvector.end(), myvector.end()-3 );
  printCont(myvector, myvector.at(0)); 


  copy_n( myvector.begin()+3, 3, myvector2.begin());
  printCont(myvector2, myvector2.at(0)); 
  auto it = copy_if (myvector.begin(), myvector.end()-5, myvector2.begin()+3, [](int x){return x%20==0;} );
  printCont(myvector2, myvector2.at(0)); 
  it--;
  cout<<"*it="<<*it;
}

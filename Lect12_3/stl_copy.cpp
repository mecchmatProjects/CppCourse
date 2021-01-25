#include <iostream>     // std::cout, ostream_iterator
#include <algorithm>    // std::copy
#include <vector>       // std::vector
#include <iterator>     //ostream_iterator
using namespace std;
template<class V,typename T> void printCont(const V & s, T val){
    copy (s.begin(), s.end(),  ostream_iterator<T>(cout, " ,"));  
   cout<<endl;    }
int main () {
  int myints[]={10,20,30,40,50,60,70};
  vector<int> myvector (7);
  copy ( myints, myints+7, myvector.begin() );
  cout << "myvector contains:";
  printCont(myvector, myvector.at(0)); 
}

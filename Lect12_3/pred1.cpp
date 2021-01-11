
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;


struct Prd {
   int my_cnt;
   // Конструктор
   Prd(const int &t) : my_cnt(t) {}
   // Перегрузка операції ()
   bool operator() (const int & v) {
       return v > my_cnt;
       cout<<"op"<<v<<"/"<<my_cnt<<";";
   }
};


int main() {
   int mas[] =  {1, 2, 3, 4, 5, 3, 7, 3, 9, 3};
   vector<int> num(mas, mas + 10);
   

   const int z = count_if(num.begin(), num.end(), Prd(4));
   vector<int> myvector(num.size()- z);
   //using namespace placeholders; // c++11
   //const int z = count_if(num.begin(), num.end(), bind(logical_not<bool>(), bind(Prd(4), _1))); 
   //vector<int> myvector(z);

   vector<int>::iterator it = remove_copy_if(num.begin(), num.end(), myvector.begin(),  Prd(4)); 
   cout<< endl;

   for(vector<int>::iterator it2 = myvector.begin(); it2!=myvector.end();++it2) 
      cout<<*it2<<", ";

   return 0;
}

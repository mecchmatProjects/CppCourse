
#include <iostream> 
#include <set> 
//#include <iterator> 

using namespace std; 
// function comarator
bool fncomp (int lhs, int rhs) {return lhs<rhs;}

//class Comparator
struct Classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

template<typename T>
void printSet(const T & v){
   for(auto itr=v.cbegin(); itr!=v.cend();++itr){
     cout <<" "<< *itr;
   }
    cout<< endl;
}

int main (){
   set<int> first_set;                           // empty set of ints
   //int myints[]= {10,20,30,40,50,50};
   set<int> second_set{10,20,30,40,50,50};        // range
   set<int> third_set =  {10,20,30,40,50,50};                  // a copy of second
   set<int> fourth_set (third_set.begin(), third_set.end());  // iterator ctor.
   printSet(fourth_set);
   // empty set container
  set <int, less <int> > seventh_set; 
  // insert elements in random order 
  seventh_set.insert(40); 
  seventh_set.insert(30);
  seventh_set.insert(60);
  seventh_set.insert(20);
  seventh_set.insert(50);
  seventh_set.insert(50); // only one 50 will be added to the set 
  seventh_set.insert(10); 
  
  printSet(seventh_set);

  seventh_set.emplace(80);
  seventh_set.emplace(50);
  auto it1 = seventh_set.emplace_hint(seventh_set.end(),70);
  cout<<" pts to" << *it1<<"next is"<< *(++it1);
  it1 = seventh_set.emplace_hint(seventh_set.end(),50);
  cout<<" pts to" << *it1<<"next is"<< *(++it1);

  printSet(seventh_set);
 

} 

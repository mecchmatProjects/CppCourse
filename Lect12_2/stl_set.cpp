
#include <iostream> 
#include <set> 
#include <vector> 
//#include <iterator> 

using namespace std; 
// function comarator
bool fncomp (int lhs, int rhs) {return lhs*lhs<rhs*rhs;}

//class Comparator
struct Classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

template<typename T>
void printSet(const set<T> v){
   typename set<T>::iterator itr;
   for(itr=v.begin(); itr!=v.end();++itr){
     cout <<"	"<<*itr;
   }
    cout<< endl;
}
template<typename T, class U>
void printSet(const set<T,U> v){
   typename set<T,U>::iterator itr;
   for(itr=v.begin(); itr!=v.end();++itr){
     cout <<"	"<<*itr;
   }
    cout<< endl;
}

int main (){
   set<int> first_set;                           // empty set of ints
   int myints[]= {10,-20,30,40,50,50,40};
    
   set<int> second_set(myints,myints+7);        // range
   set<int> third_set (second_set);                  // a copy of second
   //set<int> fourth_set (third_set.begin(), third_set.end());  // iterator constructor
   vector<int> v(third_set.begin(), third_set.end());
   set<int> fourth_set (v.begin(), v.end());
   cout<<"2,3,4 set:";
   printSet(fourth_set);

   cout<<"set size:"<< second_set.size()<<endl;
   cout<<"set max size:"<< second_set.max_size()<<endl;
   cout<<"how many of 20 there "<< second_set.count(20)<< " of " << *second_set.find(20)<<endl;
   cout<<"how many of 50 there "<< second_set.count(50)<<" of " << *second_set.find(50)<<endl;
   cout<<"equal range for 20: " << *second_set.equal_range(20).first << ", " << *second_set.equal_range(20).second<<endl;

   set<int,Classcomp> fifth_set;                 // class as Compare

   bool(*fn_pt)(int,int) = fncomp;
   set<int,bool(*)(int,int)> sixth_set (fn_pt);  // function pointer as Compare
 set <int,greater <int> > seventh_set;
  //insert elements in random order 
  seventh_set.insert(40); 
  seventh_set.insert(30);
  seventh_set.insert(60);
  seventh_set.insert(-20);
  seventh_set.insert(50);
  seventh_set.insert(30); // only one 30 will be added to the set 
  seventh_set.insert(10); 
  for (set<int,greater <int> >::iterator it = seventh_set.begin(); it!=seventh_set.end();++it){
    first_set.insert(*it);
    fifth_set.insert(*it);
    sixth_set.insert(*it);
  }
  cout<<"1 and 7th set:";
  printSet(first_set);
  cout<<"5th set:";
  printSet(fifth_set);
  cout<<"6th set:";
  printSet(sixth_set);

// remove all elements up to 30 in  
  cout << "second_set after removal of elements less than 30:"; 
  second_set.erase(second_set.begin(), second_set.find(30));
  printSet(second_set); 
   // remove element with value 50 in  
  int num; 
  num = third_set.erase (50); 
  cout << "third_set.erase(50) : ";
  cout << num << " removed " ;

  printSet(third_set); 

//lower bound and upper bound for set seventh_set 
cout << "seventh_set.lower_bound(40) : "<< *seventh_set.lower_bound(40) << endl; 
cout << "seventh_set.upper_bound(40) : "<< *seventh_set.upper_bound(40) << endl; 

//lower bound and upper bound for set second_set 
cout << "second_set.lower_bound(40) : "<< *second_set.lower_bound(40) << endl; 
cout << "second_set.upper_bound(40) : "<< *second_set.upper_bound(40) << endl; 
} 

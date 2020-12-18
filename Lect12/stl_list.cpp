#include <iostream> 
#include <list> 
#include <iterator> // advance
using namespace std; 

//function for printing the elements in a list 
template <typename T>
void showlist(const list <T> & g){ 
   // to get iterator of template type - write template before assignment  
   typename list<T>::const_iterator it = g.begin();
   cout << *it;
   it++;
   for(; it != g.end(); ++it) 
      cout << ','<< *it ; 
  cout << '\n'; 
} 

bool is_even(int n){ return n%2 == 0;}

int main(){ 

list <int> gqlist1, gqlist2; 

for(int i = 0; i < 8; ++i){ 
  gqlist1.push_back(i * 2); 
} 
int mas[] = {1,2,5,3,4};
gqlist2.assign(mas,mas+5);

cout << "\nList 1 (gqlist1) is : "; 
showlist(gqlist1); 

cout << "\nList 2 (gqlist2) is : "; 
showlist(gqlist2); 

cout << "\ngqlist1.front() : "<< gqlist1.front(); 
cout << "\ngqlist1.back() : "<< gqlist1.back(); 

cout << "\ngqlist1.pop_front() : "; 
gqlist1.pop_front(); 
showlist(gqlist1); 

gqlist1.insert(gqlist2.begin(), 2, 10); // insert 2 tens 
//gqlist1.insert(gqlist1.begin()+5, 100);  // iterator can't do it
list <int>::iterator it = gqlist1.begin();
advance(it,5);
gqlist1.insert(it, 100);
showlist(gqlist1); 

cout << "\ngqlist2.pop_back() : "; 
gqlist2.pop_back(); 
showlist(gqlist2); 

cout << "\ngqlist1.reverse() : "; 
gqlist1.reverse(); 
showlist(gqlist1); 

cout << "\ngqlist2.sort(): "; 
gqlist2.sort(); 
showlist(gqlist2); 

cout << "\ngqlist1.splice with list2: ";
list <int>::iterator ind = gqlist2.begin();
advance(ind,3);
gqlist1.splice(gqlist1.begin(),gqlist2, gqlist2.begin(), ind); 
showlist(gqlist1);
cout << "\n list2after splice: ";
showlist(gqlist2);

cout << "\ngqlist1.unique: ";
gqlist1.unique(); // delete repeated values
showlist(gqlist1);

gqlist1.sort();
gqlist1.unique();
for(list<int>::iterator it = gqlist1.begin();it!=gqlist1.end();++it){ (*it)++;}
cout<<"qlist1 update: ";
showlist(gqlist1);

gqlist1.merge(gqlist2);
cout<<"qlist1 & qlist2 merged: ";
showlist(gqlist1);

gqlist1.remove_if(is_even);
cout<<"removed even elements";
showlist(gqlist1);

}

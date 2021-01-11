   //  set.cpp: Дві однакові можини.
#include <iostream>
#include <iterator> // ostream_iterator
#include <set> 
#include <algorithm> // set_intersection etc
using namespace  std;

template<class M, typename T>
void printCont(const M & s, T val){
 
copy (s.begin(), s.end(), 
   ostream_iterator<T>(cout, " "));
cout<<endl;
}

int set1(){
 set<int, less<int> > S, T;
 S.insert(10);  S.insert(20);  S.insert(30); S.insert (10);
 T.insert (20);  T.insert (30);  T.insert (10);
 if (S == T) cout << "Equal sets, containing:\n";
 
printCont<set<int, less<int> >, int >(T,0);           // Результат:
cout << endl;                    //  Equal sets, containing: 
return 0;                        //      10 20 30
}

int multiset1()
{   multiset<int, less<int> > S, T; 
S.insert(10); S.insert(20); S.insert(30); S.insert(10);
T.insert(20); T.insert(30); T.insert(10);
if (S == T) cout << "Equal multisets: \n"; 
else cout << "Unequal multisets:\n"; 
cout << "S:  ";
printCont(S,0);
cout<<"T: ";
printCont(T,0);
     // Вивід:
    //     Unequal multisets:
    //     S: 10 10 20 30
    //     Т: 10 20 30  
return 0; 
}


int set_algorithm() {
const int N = 5;
	string s1[]= {"Bill", "Jessica", "Ben", "Mary",  "Monica"};
	string s2[N] = {"Sju","Monica","John","Bill","Sju"};	
	typedef set<string> SetS;
	SetS A(s1,  s1 + N);
	SetS B(s2,  s2 + N);
	printCont(A,s1[0]); printCont(B,s1[0]);
	SetS prod, sum; // для результату
         // Intersection
        set_intersection (A.begin(), A.end(), B.begin(), B.end(),
				inserter(prod, prod.begin())); 
	printCont(prod,s1[0]); 
    // Union
  set_union (A.begin(), A.end(), B.begin(),B.end(),
	inserter (sum, sum.begin()));
   printCont(sum,s1[0]);
   // /includes
   if (includes (A.begin(), A.end(), prod.begin(), 	prod.end()))
	cout << "Yes" << endl; 
    else cout <<"No" << endl; 
return 0;
}

int main(){
set1();
multiset1();
set_algorithm();
}

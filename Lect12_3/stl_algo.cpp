#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cstring>
#include <iterator>
#include <set>

using namespace std;

template <typename T>
void functionPrint (T x) {  // functionPrint: print the 
   cout << ' ' << x;
}

template<typename T>
struct FunctorPrint {           // function object type:
  void operator() (T x) {
    cout << "val=" << x<<" type="<<typeid(x).name()<<", ";
  }
};


void printForEach1(const vector<int> & myvector){
  cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), functionPrint<int>);
  cout << endl;
}

// count letter 'e'
int count_e(char* p){
   
   int n = count (p, p + strlen(p),  'e'); 
   cout << n << " occurrences of \'e\' found.\n";
   return  n; 
}

// count all vowels
int countvowels(char * p){
 
  char *q = p + strlen(p) ; // end of string
  int n = count(p, q, 'a') + 	count(p, q, 'e') +
	 count(p, q, 'i')  +  	count(p, q, 'o') +
	 count(p, q, 'u');
  cout << n << "vowels (a, e, i, o, u) found.\n";
	// n = 13
  return n;
}

bool found(char ch){   
   return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'; 
}

int countvowels2(char* p){  
  //char *p ="This demonstrates the Standard Template Library";
   int n = count_if(p, p + strlen(p), found);
   cout << n << "vowels2 (a, e, i, o, u) found.\n"; 
	// n = 13
  return  n; 
}


class Functor_in_10_50{
public:
   bool operator() (int x)	{
       return x > 10 && x < 50;
  }
};

bool comparefun(int x, int y){
    return x > y;
}

class Comparator  
{     public:
      bool operator()(int x, int y)const
            {   return x > y; }
}; 


int main(){

   // count demo
   char  *text  = (char*)"This demonstrates the Standard Template Libbbrary"; 

   cout<<"\ncount (e)=" <<count_e(text) <<"\n count_wl:"<<countvowels(text)<<
                "\ncount_wl2(count_if):"<<countvowels2(text)<<endl;

  
   // cope & for_each demo
   FunctorPrint<int> fp;
   int myints[]={10,20,30,40,50,60,70};
   vector<int> myvector (7);
   //copy
   copy ( myints, myints+7, myvector.begin() );
   printForEach1(myvector);
   myvector.resize(myvector.size()+3);  // allocate space for 3 more elements
   printForEach1(myvector);
   //copy_backward
   copy_backward ( myvector.begin(), myvector.begin()+5, myvector.end() );
   printForEach1(myvector);
   //copy_n(myvector.begin()+2, myvector.begin(), myvector.end()-2);
   //printForEach1(myvector);
   //copy_if(myvector.begin(), myvector.begin(), myvector.end(), Functor_in_10_50);
   // printForEach1(myvector);
  cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), fp);
  cout << '\n';

        // find, find_if
	int a[10] = {43,11,26,79,11,55,31,59,8,0};
	vector<int> v(a,a+10);
	vector<int>::iterator it1,it2;
        cout<<"new vector is:";
	for (it1=v.begin(); it1 != v.end();  ++it1) 
	    cout << *it1 << " ";
	cout << endl;
	//  ,  11
        cout<<"val=11 is found:";
	cout << *find(v.begin(), v.end(), 11) << 
                "at pos="<<find(v.begin(), v.end(), 11) -v.begin()<< endl;
	//     10<x<50
        cout<<"val from(10,50) from the last 4:";
        it2 = find_if(it1-4, v.end(), Functor_in_10_50());
        if (it2!=v.end())
        	cout << *it2 << "at pos="<<it2 - v.begin()<<endl;
        else
           cout<<"not found";

       int m; 
        cout<<"all values from(10,50) are:";

       for (it1=v.begin(),m=0; it1 != v.end();  ++it1,++m)	{
  	it2 = find_if(v.begin() + m, v.end(), Functor_in_10_50());
		if (it2 == v.begin() + m) 
                    cout << *it2 << "\t";
		else 
                    cout << "not in (10,50)" << "\t";
	}

    // search
    int b[6] = {11,79,11,55};
    it2 = search(v.begin(), v.end(), b, b+6);

        if (it2!=v.end())
        	cout << *it2 << "at pos"<<it2 - v.begin()<<endl;
        else
           cout<<"not found\n";

    int c[3] = {79,11,55};
    it2 = search (v.begin(), v.end(), c, c+3);
      
        if (it2!=v.end()){
              m=0;
              while(it2!=v.end() && m<3){   
        	cout << *it2 << "at pos"<<it2 - v.begin()<<endl;
                it2++; 
                m++;   
             }
        }
        else
           cout<<"not found\n";
   vector<char> s1(text,text+strlen(text));
   copy(s1.begin(), s1.end(), ostream_iterator<char>(cout,  " ")); 
   //copy(text,text+strlen(text),s1.begin());
   vector<char>::iterator  it3= search_n (s1.begin(),s1.end(), 3, (char)'b');
   if (it3!=s1.end())
        	cout <<"found 3 "<< *it3 << " at pos"<<it3 - s1.begin()<<endl;
        else
           cout<<"not found\n";

  // sort
 const  int N =  8; 
int a1[N]={1234,5432,8943,3346,9831,7842,8863,9820}; 
cout << "\nBefore  sorting: "; 
copy(a1, a1+N, ostream_iterator<int> (cout, " ") ) ; 
cout  <<  endl;
sort (a1, a1+N, comparefun); 
cout << "After sorting in descending order:"; 
copy(a1, a1+N, ostream_iterator<int>(cout, " ")); 
cout  <<  endl;

 
int a2[N] ={1234,5432,8943,3346,9831,7842,8863,9820};
cout << "Before sorting:";
copy(a2, a2+N, ostream_iterator<int>(cout,  " ")); 
cout << endl;  
sort (a2, a2+N, Comparator());
cout << "After sorting in descending order:"; 
copy(a2, a2+N, ostream_iterator<int>(cout,  " ")); 
cout << endl;


if (binary_search(a2, a2 + N, 2, Comparator()))   // Comparator() - obligatory!!!             
 cout << "Element found in the array";
else 
 cout << "Element not found in the array";

copy(a2, a2+N, ostream_iterator<int>(cout,  " ")); 


reverse(a2,a2+N); // or search with reverse
cout<<"\n";

copy(a2, a2+N, ostream_iterator<int>(cout,  " ")); 

if (binary_search(a2, a2+N, 7842))
  cout << "Element found in the array";
else 
  cout << "Element not found in the array";

	return 0;
}





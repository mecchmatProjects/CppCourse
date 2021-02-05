#include <iostream> 
#include <deque>
#include <stack>  

using namespace std; 

template<typename T>
void showdq(const deque <T> & g){  
 for(size_t i=0; i<g.size();++i) 
    cout << '\t'<< g[i]; 
 cout << '\n'; 
} 

template<class T>
void printStack(const stack<T> & st){ 
 stack<T> st1(st);
 while(!st1.empty()){ 
    cout << ", "<< st1.top();
    st1.pop();  
 }
 cout << ";\t"; 
} 

template<typename T>
void showdq(const deque<stack<T> > & g){ 
 
 for(size_t i=0; i<g.size();++i) {
    cout << "stack "<< i<<":";
    printStack(g[i]); 
 }
 cout << '\n'; 
} 

int main(){ 

deque <char*> deq1; 
deq1.push_back((char*)"cadabra"); 
deq1.push_front((char*)"abra"); 
deq1.push_back((char*)"bums"); 
deq1.push_front((char*)"\n"); 
cout << "The deque deq1 is : "; 
showdq(deq1); 

cout << "\ndeq1.size() : "<< deq1.size(); 
cout << "\ndeq1.max_size() : "<< deq1.max_size(); 

cout << "\ndeq1.at(2) : "<< deq1.at(2); 
cout << "\ndeq1.front() : "<< deq1.front(); 
cout << "\ndeq1.back() : "<< deq1.back(); 

cout << "\ndeq1.pop_front() : ";
deq1.pop_front(); 
showdq(deq1); 

cout << "\ndeq1.pop_back() : "; 
deq1.pop_back(); 
showdq(deq1); 

deque<stack<int> > deq2;
stack<int> a1;
a1.push(1);a1.push(2);
deq2.push_back(a1); 

stack<int> a2(a1);
a2.push(3);
deq2.push_back(a2);

deq2.push_front(a1);
a1.pop();
deq2.push_back(a1);

showdq(deq2); 

 deque<int> foo (3,100);   // three ints with a value of 100
 deque<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";


}

/*
/ C++ STL deque, constructor

#include<deque>

#include<iostream>

using namespace std;

 

int main(void)

{

// deque iterators

deque <int>::iterator c1_Iter, c2_Iter, c3_Iter, c4_Iter, c5_Iter, c6_Iter;

// create an empty deque c0

deque <int> c0;

// create a deque c1 with 3 elements of default value 0

deque <int> c1(3);

// create a deque c2 with 5 elements of value 2

deque <int> c2(5, 2);

// create a deque c3 with 3 elements of value 1 and with the allocator of deque c2

deque <int> c3(3, 1, c2.get_allocator());

// create a copy, deque c4, of deque c2

deque <int> c4(c2);

// create a deque c5 by copying the range c4[_First, _Last)

c4_Iter = c4.begin();

c4_Iter++;

c4_Iter++;

deque <int> c5(c4.begin(), c4_Iter);

// create a deque c6 by copying the range c4[_First, _Last) and c2 with the allocator of deque

c4_Iter = c4.begin( );

c4_Iter++;

c4_Iter++;

c4_Iter++;

 

// do the operations and print the data

deque <int> c6(c4.begin(), c4_Iter, c2.get_allocator());

cout<<"c1 deque: ";

for (c1_Iter = c1.begin(); c1_Iter != c1.end(); c1_Iter++)

cout<<*c1_Iter<<" ";

cout<<endl;

cout<<"c2 deque: ";

for (c2_Iter = c2.begin(); c2_Iter != c2.end(); c2_Iter++)

cout<<*c2_Iter<<" ";

cout<<endl;

cout<<"c3 deque: ";

for (c3_Iter = c3.begin(); c3_Iter != c3.end(); c3_Iter++)

cout<<*c3_Iter<<" ";

cout<<endl;

cout<<"c4 deque: ";

for (c4_Iter = c4.begin(); c4_Iter != c4.end(); c4_Iter++)

cout<<*c4_Iter<<" ";

cout<<endl;

cout<<"c5 deque: ";

for (c5_Iter = c5.begin(); c5_Iter != c5.end(); c5_Iter++)

cout<<*c5_Iter<<" ";

cout<<endl;

cout<<"c6 deque: ";

for (c6_Iter = c6.begin(); c6_Iter != c6.end(); c6_Iter++)

cout<<*c6_Iter<<" ";

cout<<endl;

return 0;

}

*/

#include <iostream>
#include <stack>
using namespace std;

void showstack(stack <int> s){
 while (!s.empty()){
   cout<<'\t'<<s.top();
   s.pop();
   }
  cout << '\n';
}

int main(){
  stack <int> s;
  s.push(10);
  s.push(30);
  s.push(20);
  s.push(5);
  s.push(1);
  cout <<"The stack is : ";
  showstack(s);
  //The stack is :     1    5    20    30    10
  cout<<"\ns.size():"<<s.size();//5
  cout << "\ns.top() : " << s.top();//1
  cout << "\ns.pop() : "; //
  s.pop();
  showstack(s);
 //s.pop() :     5    20    30    10
}

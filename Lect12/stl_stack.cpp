#include <iostream>
#include <string>
#include <stack>
//http://candcplusplus.com/c-difference-between-emplace_back-and-push_back-function
using namespace std;
// виводить стек у зворотньому порядку
void showstack(const stack <string> & s){
  stack <string> copy_s(s); // copy-constructor to create copy of s
  /*copy_s.pop();
  copy_s.push("rotas legionas");
  cout<<boolalpha<<(copy_s>= s)<<(copy_s==s)<<endl;
  copy_s.push("legionas rotas");  
  cout<<boolalpha<<(copy_s>= s)<<(copy_s==s)<<endl;;
  copy_s.pop();
  copy_s.pop();
  copy_s.push("rot");
  cout<<boolalpha<<(copy_s>= s)<<(copy_s==s)<<endl;*/
  // поки стек не порожній – виводить верхівку та видаляє її
 while (!copy_s.empty()){
   cout<<'\t'<<copy_s.top();
   copy_s.pop();
   }
  cout << '\n';
}

int main(){
  stack <string> s;
  s.push("sator");
  s.push("arepo");
  s.push("tenet");
  s.push("opera");
  s.push("rotas");
  cout <<"The stack is : ";
  showstack(s);
  //The stack is :     rotas    opera    tenet    arepo    sator
  cout<<"\ns.size():"<<s.size();//5
  cout << "\ns.top() : " << s.top();//rotas
  cout << "\ns.pop() : "; //
  s.pop();
  showstack(s); // opera    tenet    arepo    sator
 //s.pop() :  //    tenet    arepo    sator
}

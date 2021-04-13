
// Queue in Standard Template Library (STL) 
#include <iostream> 
#include <queue> 

using namespace std; 
// виводить чергу в порядку заповнення
template <typename T>
void showq(const queue <T> & gq) { 
// створюэмо копію черги
queue <T> g = gq;
// видаляємо та дивимось всі елементи в неї з початку
while (!g.empty()) {
  	cout << '\t' << g.front();
        g.pop();
 } 
}
// виводить чергу в порядку пріорітету для стандартних типів
template<class T>
void showpq(const priority_queue <T> & gq) {
  priority_queue <T> g(gq);
  while (!g.empty()){
   cout << '\t' << g.top();
   g.pop();
   }
}
// виводить чергу в порядку пріорітету для типу Пара від двох цілих – спеціалізація  showpq
template<>
void showpq(const priority_queue <pair<int,int> > & gq) {
  //‘>>’ should be ‘> >’ within a nested template argument list before C++11
  priority_queue <pair<int,int> > g(gq);
  while (!g.empty()){
   pair<int,int> tmp = g.top();
   cout << "\t(" << tmp.first<<", "<<tmp.second<<")";
   g.pop();
   }
}


int main() {
    // simple Queue
   queue <int> q1; 
   q1.push(10);
   q1.push(20);
   q1.push(30);
   q1.push(15);
   cout << "The queue q1 is : ";
   showq(q1);
   cout << "\nq1.size() : " << q1.size();
   cout << "\nq1.front() : " << q1.front();
   cout << "\nq1.back() : " << q1.back();
   cout << "\nq1.pop() : ";
   q1.pop();
   showq(q1);

   // priority Queue
   priority_queue <int> q2;
   q2.push(10);
   q2.push(30);
   q2.push(20); 
   q2.push(5);
   q2.push(1);
   cout << "\nThe priority queue q2 is : ";
   showpq(q2);
   cout << "\nq2.size() : " << q2.size();
   cout << "\nq2.top() : " << q2.top();
   cout << "\nq2.pop() : ";
   q2.pop(); 
   showpq(q2);
   // priority Queue 2
   priority_queue <pair<int,int> > q3;/* коректно до c++20 – інакше потрібен <=> */
   q3.push(make_pair(1,2));
   q3.push(pair<int,int>(3,4));
   q3.push(make_pair(1,4));
   q3.push(make_pair(2,10));
   cout << "\nThe priority queue q3 is : ";
   showpq(q3);
}


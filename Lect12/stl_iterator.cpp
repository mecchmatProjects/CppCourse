#include<iostream>
#include<iterator> // for iterators
#include<vector> // for vectors
#include<deque> // for vectors
#include<list> // for vectors

template<class Coll>
void printCollect(Coll & v){
  typename Coll::const_iterator it = v.begin();
  for(;it!=v.end();++it){
    std::cout<<*it<<" ";
 } 
 std::cout<<"\n";
}

int main() {

int mas[] ={1,2,3,4,5, 10,20,30};

std::vector<int> ar(mas,mas+5);
std::vector<int> ar1(mas+6,mas+8);
std::vector<int>::iterator ptr = ar.begin();
std::advance(ptr, 3);
//ptr += 3;
std::cout << "Third element is : "<<*ptr;

std::copy(ar1.begin(), ar1.end(), inserter(ar,ptr));
std::cout << "The new vector after inserting elements is : ";
printCollect(ar);
printCollect(ar1);


std::list<int> list1(mas,mas+5);
std::list<int> list2(mas+6,mas+8);
std::list<int>::iterator ptr2 = list1.begin();
std::advance(ptr2, 3);
//ptr += 3;
std::cout << "Third element is : "<<*ptr2;
std::copy(list2.begin(), list2.end(), inserter(list1,ptr2));
std::cout << "The new vector after inserting elements is : ";
printCollect(list1);
printCollect(list2);

  std::deque<int> foo,bar;
  for (int i=1; i<=5; i++){ foo.push_back(i); bar.push_back(i*10); }

  std::copy (bar.begin(),bar.end(),std::front_inserter(foo));

  std::cout << "foo after front insert contains:";
  /*for ( std::deque<int>::iterator it = foo.begin(); it!= foo.end(); ++it )
          std::cout << ' ' << *it;
  std::cout << '\n';*/
printCollect(foo);

  std::vector<int> foo1,bar1;
  for (int i=1; i<=5; i++)
  { foo1.push_back(i); bar1.push_back(i*10); }

  std::copy (bar1.begin(),bar1.end(),back_inserter(foo1));

  std::cout << "foo after back insert contains:";
/*  for ( std::vector<int>::iterator it = foo.begin(); it!= foo.end(); ++it )
          std::cout << ' ' << *it;
  std::cout << '\n';
*/
printCollect(foo1);

    std::vector<int> v(mas+1,mas+7);
    std::cout << "distance(first, last) = "
              << std::distance(v.begin(), v.end()) << '\n'
              << "distance(last, first) = "
              << std::distance(v.end(), v.begin()) << '\n';
               //the behavior is undefined (until C++11)
}

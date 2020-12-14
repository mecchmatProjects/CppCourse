#include <iostream>
#include <vector>

using namespace std;
//Vector c++11 methods


class A{
public:
  A (int x_arg) : x (x_arg) { std::cout << "A (x_arg)\n"; }
  A () { x = 0; std::cout << "A ()\n"; }
  A (const A &rhs) noexcept { x = rhs.x; std::cout << "A (A &)\n"; }
  A (A &&rhs) noexcept { x = rhs.x; std::cout << "A (A &&)\n"; }

private:
  int x;
};

int main(){

// Assign vector 
vector<char> v; 
// fill the array with 10 five times 
v.assign('5', 10); 

// Inserts 20 at the end 
v.emplace_back('2'); 
size_t n = v.size(); 
cout << "\nThe last element is: "<< v[n - 1]; 

// inserts 5 at the beginning 
v.emplace(v.begin(), '7'); 
cout << "\nThe first element is: "<< v[0]; 

    vector<pair<char, int>> vect; 
       
    // using emplace() to insert pair in-place 
    vect.emplace_back('a', 24); 
        
    // Below line would not compile 
    // vect.push_back('b', 25);     
       
    // using push_back() to insert 
    vect.push_back(make_pair('b', 25));     
        
    // printing the vector 
    for (int i=0; i<vect.size(); i++) 
        cout << vect[i].first << " " << vect[i].second 
             << endl; 

  {
    std::vector<A> a;
    std::cout << "call emplace_back:\n";
    a.emplace_back (0);
  }
  {
    std::vector<A> a;
    std::cout << "call push_back:\n";
    a.push_back (1);
  }   

// two vector to perform swap 
vector<float> v1 = {1.f,2.f,3.f,4.f}; 

vector<float> v2{5.0f,6.0f,7.0f}; 

cout << "\nVector 1: "; 
for(int x : v1) 
  cout << x << " "; 

cout << "\nVector 2: "; 
for(auto x : v2) 
  cout << x << " "; 

// Swaps v1 and v2 
v1.swap(v2); 

cout << "\nAfter Swap \nVector 1: "; 
for(auto it = v1.begin(); it != v1.end(); ++it) 
  cout << *it << " "; 

cout << "\nVector 2: "; 
for(auto it = v2.cbegin();it!=v2.cend();++it) 
  cout << *it << " ";

// Shrinks the vector 
//g1.shrink_to_fit(); 
cout << "\nVector elements are: "; 

}



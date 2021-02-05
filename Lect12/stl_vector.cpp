
// C++ program to illustrate the methods Modifiers in vector 
#include <iostream> 
#include <vector> 
using namespace std; 

int main(){ 
// Assign vector 
vector<int> v; 
// fill the array with 10 five times 
v.assign(5, 10); 

cout << "The vector elements are: "; 
for(int i = 0; i < v.size(); i++) 
cout << v[i] << " "; 

// inserts 15 to the last position 
v.push_back(15); 
int n = v.size(); 
cout << "\nThe last element is: "<< v[n - 1]; 

// removes last element 
v.pop_back(); 

for(int i = 0; i < v.size(); i++) 
 cout << v.at(i) << " "; 
// erases the vector 
v.clear(); 
cout << "\nVector size after erase(): "<< v.size();


// prints the vector 
cout << "\nThe vector elements are: "; 
for(int i = 0; i < v.size(); i++) 
 cout << v.at(i) << " "; 

// inserts 5 at the beginning 
v.insert(v.begin(), 5); 

cout << "\nThe first element is: "<< v[0]; 

// removes the first element 
v.erase(v.begin()); 

cout << "\nThe first element is: "<< v[0]; 



vector<int> g1; 
for(int i = 1; i <= 5; i++) 
  g1.push_back(i); 

cout << "Size : "<< g1.size(); 
cout << "\nCapacity : "<< g1.capacity(); 
cout << "\nMax_Size : "<< g1.max_size(); 

// resizes the vector size to 4 
g1.resize(4); 

// prints the vector size after resize() 
cout << "\nSize : "<< g1.size(); 

// checks if the vector is empty or not 
if(g1.empty() == false) 
cout << "\nVector is not empty"; 
else
cout << "\nVector is empty"; 


for(vector<int>::iterator it = g1.begin(); it != g1.end(); it++) 
  cout << *it << " ";

string massiv[] = {"first", "second", "third", "forth", "fifth"};
vector<string> g2(massiv, massiv + 5);    


cout << "\nReference operator [g] : g1[2] = "<< g2[2]; 
cout << "\nat : g1.at(4) = "<< g2.at(4); 
cout << "\nfront() : g1.front() = "<< g2.front(); 
cout << "\nback() : g1.back() = "<< g2.back(); 
// pointer to the first element 
string* pos = g2.data(); 
cout << "\nThe first element is "<< *pos; 
 
}


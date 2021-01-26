#include <bits/stdc++.h>

bool mypredicate (int i, int j) {
  return (i%2==j%2); // to elements are equal if have same parity
}

int main () {
  std::vector<int> haystack;
  // set some values:        haystack: 10 20 30 40 50 60 70 80 90
  for (int i=1; i<10; i++) haystack.push_back(i*10);
  // using default comparison:
  int needle1[] = {40,50,60,70,60,60};
  std::vector<int>::iterator it;
  it = std::search (haystack.begin(), haystack.end(), needle1,needle1+4);
  if (it!=haystack.end())
    std::cout << "needle1 found at position " << (it-haystack.begin()) << '\n';
  else
    std::cout << "needle1 not found\n";

 // using predicate comparison:
  int needle2[] = {20,30,50};
  it = std::search (haystack.begin(), haystack.end(), needle2, needle2+3, mypredicate);

  if (it!=haystack.end())
    std::cout << "needle2 equal parity at position " << (it-haystack.begin()) << '\n';
  else
    std::cout << "needle2 equal parity not found\n";

  haystack.push_back(90);  haystack.push_back(80);
  it = std::search_n (haystack.begin(), haystack.end(), 2,90);
  if (it!=haystack.end())
    std::cout << "2 90th are found at position " << (it-haystack.begin()) << '\n';
  else
    std::cout << "2 90th not found\n";




}

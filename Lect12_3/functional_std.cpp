
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

bool cmp(double x){
  return x>2.0;
}

//using namespace std;
int main(){

std::vector<double> v1, v2(4);
double mas1[] ={1.0,2.3,1.0,4.1};
v1.assign(1.0,4);
std::copy(mas1,mas1+3,v2.begin());  

 for (std::vector<double>::iterator it = v2.begin(); it!=v2.end(); ++it)
    std::cout << ' ' << *it;

// using predicate comparison:
std::pair<std::vector<double>::iterator, std::vector<double>::iterator> it;

  it = std::mismatch (v1.begin(), v1.end(), v2.begin(), std::less<double>() );

  std::cout << "Second mismatching elements: " << *it.first;
  std::cout << " and " << *it.second << '\n';


 std::vector<int> val(v2.begin(),v2.end());
 std::vector<int> result(4);
  std::partial_sum (val.begin(), val.end(), result.begin(), std::multiplies<int>());
  std::cout << "using functional operation multiplies: ";
  for (int i=0; i<4; i++) std::cout << result[i] << ' ';
  std::cout << '\n';

}

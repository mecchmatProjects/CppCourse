// accumulate example
#include <iostream>     // std::cout
#include <functional>   // std::minus
#include <numeric>      // std::accumulate

int myfunction (int x, int y) {return x+2*y;}
struct myclass {
        int operator()(int x, int y) {return x+3*y;}
} myobject;

int myop (int x, int y) {return x+y;}
int myop1 (int x, int y) {return x+y+1;}

int myaccumulator (int x, int y) {return x-y;}
int myproduct (int x, int y) {return x+y;}

int main () {
  int init = 100;
  int numbers[] = {10,20,30};

  std::cout << "using default accumulate: ";
  std::cout << std::accumulate(numbers,numbers+3,init);
  std::cout << '\n';

  std::cout << "using functional's minus: ";
  std::cout << std::accumulate (numbers, numbers+3, init, std::minus<int>());
  std::cout << '\n';

  std::cout << "using custom function: ";
  std::cout << std::accumulate (numbers, numbers+3, init, myfunction);
  std::cout << '\n';

  std::cout << "using custom object: ";
  std::cout << std::accumulate (numbers, numbers+3, init, myobject);
  std::cout << '\n';

 int val[] = {1,2,3,5,9,11,12};
  int result[7];

  std::adjacent_difference (val, val+7, result);
  std::cout << "using default adjacent_difference: ";
  for (int i=0; i<7; i++) std::cout << result[i] << ' ';
  std::cout << '\n';

  std::adjacent_difference (val, val+7, result, std::multiplies<int>());
  std::cout << "using functional operation multiplies: ";
  for (int i=0; i<7; i++) std::cout << result[i] << ' ';
  std::cout << '\n';

  std::adjacent_difference (val, val+7, result, myop);
  std::cout << "using custom function: ";
  for (int i=0; i<7; i++) std::cout << result[i] << ' ';
  std::cout << '\n';
 

  int series1[] = {10,20,30};
  int series2[] = {1,2,3};

  std::cout << "using default inner_product: ";
  std::cout << std::inner_product(series1,series1+3,series2,init);
  std::cout << '\n';

  std::cout << "using functional operations: ";
  std::cout << std::inner_product(series1,series1+3,series2,init,
                                  std::minus<int>(),std::divides<int>());
  std::cout << '\n';

  std::cout << "using custom functions: ";
  std::cout << std::inner_product(series1,series1+3,series2,init,
                                  myaccumulator,myproduct);
  std::cout << '\n';

int val1[] = {1,2,3,4,5};
  int result2[5];

  std::partial_sum (val1, val1+5, result2);
  std::cout << "using default partial_sum: ";
  for (int i=0; i<5; i++) std::cout << result2[i] << ' ';
  std::cout << '\n';

  std::partial_sum (val1, val+5, result2, std::multiplies<int>());
  std::cout << "using functional operation multiplies: ";
  for (int i=0; i<5; i++) std::cout << result2[i] << ' ';
  std::cout << '\n';

  std::partial_sum (val1, val1+5, result2, myop1);
  std::cout << "using custom function: ";
  for (int i=0; i<5; i++) std::cout << result2[i] << ' ';
  std::cout << '\n';

  return 0;
}


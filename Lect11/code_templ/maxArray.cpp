
#include <iostream>
#include <cstring>
using namespace std;

template <typename T> T maxArray(const T* array, size_t size){
  T max = array[0];
  for (int ix = 1; ix < size; ix++)
	if (max < array[ix])
		max = array[ix];
  return max;
}
int main(){
  char array [] = "aodsiafgerkeio";
  int len = strlen(array);
  cout << "Максимальний елемент масиву типу char: " << maxArray(array, len) << endl;
  int iArray [5] = {3,5,7,2,9};
  cout << " Максимальний елемент масиву типу int: " << maxArray(iArray, 5) << endl;
}

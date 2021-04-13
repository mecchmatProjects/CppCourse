#include <iostream>
#include <cstring>
using namespace std;

int maxArray(const int* array, int size){
    int max = array[0];
    for (int ix = 0; ix < size; ix++)
	if (max < array[ix])
	      max = array[ix];
    return max;
}
std::string maxArray(const std::string* array, int size){
    std::string max = array[0]; // максимальне значення в масиві
    for (int ix = 0; ix < size; ix++)
	if (max < array[ix])
		max = array[ix];
    return max;
}
int main(){
    string array[] = {"aodsiafgerkeio", "fsdfsd", "fdfsdfsdfsd"};
    int len = 3;
    cout << "Максимальний елемент масиву типу string: " << maxArray(array, len) << endl;
    int iArray [5] = {3,5,7,2,9};
    cout << " Максимальний елемент масиву типу int: " << maxArray(iArray, 5) << endl;
}

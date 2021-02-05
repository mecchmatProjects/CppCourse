#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int arr[] = {10, 20, 5, 23 ,42 , 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vect(arr, arr+n);
	//  
	reverse(vect.begin(), vect.end());

    	cout << "Vector after reversing is: ";
	
 	for (int i=0; i<vect.size(); i++)
		cout << vect[i] << " ";

	cout << "\nMaximum element of vector is: ";
	cout << *max_element(vect.begin(), vect.end())<<" or " << max({10, 20, 5, 23, 42, 15});
	cout << "\nMinimum element of vector is: ";
	cout << *min_element(vect.begin(), vect.end())<<" or " << min(10, 20, 5, 23, 42, 15);           

cout <<"\nmin:"<< *minmax_element(vect.begin(), vect.end()).first <<" max=" << minmax({10, 20, 5, 23 ,42 , 15}).second;  

}         

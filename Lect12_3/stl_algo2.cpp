// A C++ program to demonstrate working of sort(), reverse()
#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    int arr[] = {10, 20, 5, 23 ,42 , 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);
    cout << "Vector is: ";
    for (int i=0; i<n; i++)          cout << vect[i] << " ";
    // Сортуємо по зростанню
    sort(vect.begin(), vect.end());
    cout << "\nVector after sorting is: ";
    for (int i=0; i<n; i++)
       cout << vect[i] << " ";
  
    // реверсія контейнеру
    reverse(vect.begin(), vect.end());

cout << "\nVector after reversing is: ";
    for (int i=0; i<6; i++)
        cout << vect[i] << " ";
  
    cout << "\nMaximum element of vector is: ";
    cout << *max_element(vect.begin(), vect.end());
  
    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end());
  
    // сумуємо починаючи з 0
    cout << "\nThe summation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0);

int arr[] = {10, 20, 5, 23 ,42, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);
  
    cout << "Occurrences of 20 in vector : ";
    // Кількість 20-ток від початку до кінця
    cout << count(vect.begin(), vect.end(), 20);
  
    // find() повертає ітератор на кінець, якщо не знайшло елемент
find(vect.begin(), vect.end(),5) != vect.end()?
                       cout<< "\nElement found«:    cout << "\nElement not found";


// Перше входження 20 , auto == vector<int>::iterator
    auto q = lower_bound(vect.begin(), vect.end(), 20);
    // Останнє входження 20
    auto p = upper_bound(vect.begin(), vect.end(), 20);
    cout << "The lower bound is at position: ";
    cout << q-vect.begin() << endl;
  
    cout << "The upper bound is at position: ";
    cout << p-vect.begin() << endl;
  
// сортуємо весь вектор
    sort(vect.begin(), vect.end());
  
    cout << "\nVector before removing duplicate occurrences: ";
    for (int i=0; i<5; i++)
        cout << vect[i] << " ";
  
    // видаляємо повтори
    vect.erase(unique(vect.begin(),vect.end()),vect.end());
  
    cout << "\nVector after deleting duplicates: ";
    for (int i=0; i<vect.size(); i++)
        cout << vect[i] << " ";


// повертає відстань до максимального елементу - 9
    cout << "Distance between first to max element: "; 
    cout << distance(vect.begin(),
                     max_element(vect.begin(), vect.end()));

}


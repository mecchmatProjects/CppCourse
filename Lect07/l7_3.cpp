// P4J2.CPP — використання setw()
#include <iostream>
#include <iomanip>
using namespace std;
 
int main ( ){
cout << 456 << 789 << 123 << endl;
cout << setw(5) << 456 << setw(5) << 789 << setw(5) << 123 << endl;
cout << setw(7) << 456 << setw(7) << 789 << setw(7) << 123 << endl;
}

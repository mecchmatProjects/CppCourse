#include <iostream>
#include <iomanip>
using namespace std;

int main ( ){ 
 float prod_sum; // prod_sum — сума продаж
 float nalog;
 //--------------- виведення підказки
 cout << "Введить суму продаж";
 cin >> prod_sum;
 //............... обчислення податку
 nalog = prod_sum* 0.7;
 cout << "Сума: " << setprecision(2) << prod_sum;
 cout << "Податок: " << setprecision(2) << nalog << "\n";
 return 0;
}

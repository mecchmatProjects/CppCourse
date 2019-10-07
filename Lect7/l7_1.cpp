#include <iostream>
#include <string>

using namespace std;

int main(){
 char name[] = "Петро";
 char middle = 'P';
 string last("Петренко");
 int wozrast =20;
 int doplata = 2;
 float zarplata = 3009.75f;
 double prozent = 8.5;
 //---------------- виведення результатів
 cout << "Перевірка даних\n";
 cout << name << " "<< middle <<" " << last << "\n"<<endl;
 cout << "Вік доплата зарплата відсоток:\n";
 cout << " " << wozrast << " " << doplata << " " << zarplata << " " << prozent;
 cin.get();
}

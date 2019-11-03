#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ukr");

    int num1;
    int num2;

    int var = 3; // управляющая переменная для while
    while (var != 0) {
        cout << "Введить число num1: ";
        cin >> num1;
        cout << "Введить число num2: ";
        cin >> num2;

        cout << "num1 + num2 = " << num1 + num2 << endl;
        cout << "num1 / num2 = " << num1 / num2 << endl;
        cout << "num1 - num2 = " << num1 - num2 << endl;
        cout << "=================================" << endl << endl;

        var--;
    }

    cout << "Кінець роботи програми!" << endl << endl;

    return 0;
}


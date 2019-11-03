
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ukr");

    int num1;
    int num2;

    int var = 3;
    while (var != 0) {
        cout << "Введiть число num1: ";
        cin >> num1;
        cout << "Введiть число num2: ";
        cin >> num2;
          
        cout << "num1 + num2 = " << num1 + num2 << endl;
        cout << "num1 / num2 = ";         

        try { // тут код, який може викликати помилку
            if (num2 == 0) {
                throw 42; // генерувати ціле число 42
            }
            cout << num1 / num2 << endl;
        }
        catch (int thr) { // сюда передаєтбся число, яке згенерував throw
            cout << "Помилка №" << thr << " - ділення на 0!!!" << endl;
        }
         catch (exception& e)
        {
        cerr << "exception caught: " << e.what() << '\n';
        }

        cout << "num1 - num2 = " << num1 - num2 << endl;
        cout << "=================================" << endl << endl;

        var--;
    }

    cout << "Програма завершила роботу!" << endl << endl;

    return 0;
}


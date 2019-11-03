// ограничение на генерируемые функцией типы
#include <iostream>

using namespace std;

// данная функция может сгенерировать только int, char и double
void Xhandler(int test) throw (int, char, double)
{
if(test==0) throw test; // генерация int
if(test==1) throw 'a'; // генерация char
if(test==2) throw 123.23; // генерация double
}
int main()
{
cout << "start\n";
try {
Xhandler(1); // попытка передать 1 и 2 в Xhandler()
}
catch (int i) {
cout << "Caught an integer\n";
}
catch (char c) {
cout << "Caught char\n";
}
catch(double d) {
cout << "Caught double\n";
}
cout << "end";
return 0;
}
/*
// данная функция не может сгенерировать исключения
void Xhandler(int test) throw()
{
// следующие операторы больше не работают. Они будут вызывать аномальное завершение программы 
if(test==0) throw test;
if(test==1) throw 'a';
if(test==2) throw 123.23;
}

*/

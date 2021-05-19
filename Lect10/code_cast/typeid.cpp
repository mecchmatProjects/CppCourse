
// пример использования typeid
#include <iostream>
#include <typeinfo>

using namespace std;
class BaseClass {
int a, b;
virtual void f() {}; // BaseClass полиморфный
};
class Derived1: public BaseClass {
int i, j;
};
class Derived2: public BaseClass {
int k;
};
int main()
{
int i;
BaseClass *p, baseob;
Derived1 ob1;
Derived2 ob2;
// сначала выводится имя встроенного типа
cout << "Typeid of i is ";
cout << typeid(i).name() << endl;
// демонстрация typeid с полиморфными типами
p = &baseob;
cout << "p is pointing to an object of type "; // Base
cout << typeid(*p).name()<<" and "<<boolalpha<< typeid(*p).before(typeid(baseob)) << endl;
p = &ob1;
cout << "p is pointing to an object of type "<<typeid(*p).name(); // Dderived 1
cout << boolalpha << (typeid(*p)== typeid(Derived1)) <<" and "<< typeid(*p).before(typeid(baseob))<< endl;
p = &ob2;
cout << "p is pointing to an object of type ";
cout << typeid(p).name() << endl;
return 0;
}

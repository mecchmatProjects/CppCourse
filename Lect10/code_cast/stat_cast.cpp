#include <cstdio>
#include <iostream>

using namespace std;
class Base {
    public:
    int x;
    Base(int x_):x(x_){}
};
class Derived: public Base {
    public:
 int y; 
   Derived(int x_, int y_):Base(x_),y(y_){}
};

int main(int argc, char **argv)
{
	printf("hello world\n");

Base * a = new Base(1);
Derived * b = static_cast<Derived*>(a);

cout<<b->x<<","<<b->y<<endl;

int a1 =static_cast<int>(4.578f);

float b1= static_cast<float>(a1*3);

cout<<b1<<endl;

void * ptr = new long long (12LL);
int *ptr2 = static_cast<int*> (ptr);

cout<<*ptr2<<endl;

long long * ptr3 = new long long (44LL);
//int *ptr4 = static_cast<int*> (ptr3); // error: invalid static_cast from type ‘long long int*’ to type ‘int*’

//cout<<*ptr4<<endl;

int * ptr5 = new int (33);
//long long *ptr6 = static_cast<long long*> (ptr5);
//cout<<*ptr6<<endl;

void *ptr6 = static_cast<void*> (ptr5);

long long *ptr7 = static_cast<long long*> (ptr6);
cout<<*ptr7<<endl;


Base a2(1);
//Derived b2 = static_cast<Derived>(a2);

Derived a3(2,2);
Base b3 = static_cast<Base>(a3);
cout<< b3.x<<endl;

Derived * a4 = new Derived(1,1);
Base * b4 = static_cast<Base*>(a);
cout<< b4->x<<"\n";
	return 0;
}
/* hello world
1,0
12
12
33
2
1
*/

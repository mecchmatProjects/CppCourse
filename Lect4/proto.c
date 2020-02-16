#include<stdio.h>

double sqr (double); // прототип функції sqr()

// функція, що ділить 2 числа націло
long int Div(long int x, long int y)
{
    long int res;
    res = x / y; // результат - ціле число
    return res;
}

long DivRigth(long, long);

int main( ) // головна функція
{ //---------------- виклик функції sqr()
 printf("Квадрат числа=%lf \n", sqr (9));
 
 // виклик функції з іншого програмного коду
int a, b, c;

a = 290488;
b = -223;
c = Div(a, b); // правильна відповідь: c = -1302. Значення c може бути помилкове c=4294965994
printf("c=%d",c);
long c2 = DivRigth(a, b); // правильна відповідь: c = -1302. 
printf("c=%ld",c2);

}

double sqr (double p) //реалізація функції sqr()
{ return p*p; } //повернення результату

long DivRigth(long x, long  y){
    long res;
    res = x / y; // результат - ціле число
    return res;
    }
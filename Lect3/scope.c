#include<stdio.h>
void test2(); // декларація функції test

int main()
{
int m = 22, n = 44;// m, n  локальні змінні
/*m та n мають область дії всередині main().
Функція test їх не бачить.
m =a +b; --- помилка! При спробі використати тут a або b і в інших функціях,буде помилка 'a' undeclared та 'b' undeclared */
printf("\nvalues : m = %d and n = %d", m, n);
test2(); // Виклик test()
}

void test2() { // реалізація функції test
int a = 50, b = 80; // a, b локальні змінні test function
             /*a та b мають область дії лише в цій функції.Їх не бачить main function. 
   a = n+m; -- Помилка! 
При спробі використати m або n тут і в інших функціях,буде помилка 'm' undeclared та 'n' undeclared */
printf("\nvalues : a = %d and b = %d", a, b); 
}
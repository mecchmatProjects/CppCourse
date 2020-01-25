#include<stdio.h>
void test();
int m = 22, n = 44; // Глобальні змінні
int a = 50, b = 80; // Глобальні змінні

int main(){
    printf("All variables are accessed from main function");
    printf("\nvalues: m=%d:n=%d:a=%d:b=%d", m,n,a,b); // всі змінні доступні
test();
}

void test()
{
 printf("\n\nAll variables are accessed from test function");  // всі змінні доступні
 printf("\nvalues: m=%d:n=%d:a=%d:b=%d", m,n,a,b);
 }
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int calculate(int op1, int op2, int(*func)(int, int))
{
    return func(op1, op2);
}

/* додавання, віднімання, множення, ділення,
остача, возведення в ступінь: */
int summ(int op1, int op2)
{
    return op1 + op2;
}
int diff(int op1, int op2)
{
    return op1 - op2;
}
int mult(int op1, int op2)
{
    return op1 * op2;
}
int divd(int op1, int op2)
{
    return op1 / op2;
}
int bals(int op1, int op2)
{
    return op1 % op2;
}
int powr(int op1, int op2)
{
    int ret = 1;
    while (op2--) ret *= op1;
    return ret;
}

typedef int(*fint_t)(int, int); // fint_t - вказівник на функцію
// функції 6-ти арифметичних операцій
fint_t foper[] = { // масив вказівників на функції
    summ, diff, mult, divd, bals, powr
};


// function returns function

int (*idputs(int (*puts)(const char *)))(const char *) {
    return puts;
}

//int (*getFunc(void))(int, int) { … }


int main()
{
    setlocale(LC_ALL, "Ukrainian");
    char coper[] = { '+', '-', '*', '/', '%', '^' };
    int noper = sizeof(coper) / sizeof(coper[0]);
    
    printf("%d",calculate(2,3,summ)); 
    printf("%d",calculate(3,4,diff));
    fint_t fun = summ;  fint_t fun1 = &diff; 
   printf("%d",calculate(7,3,fun)); printf("%d",calculate(7,3,fun1)); 
    
    do {
        char buf[120];
        char *str = buf;
        char *endptr;
        char oper;

        printf("вираз для обчислення (<op1><знак><op2>): ");
        fflush(stdin);
        fscanf(stdin, "%s", buf);
        
        if(strncmp(buf,"stop", 4)==0) break;

        int op1, op2;
        op1 = strtod(str, &endptr);
        oper = *endptr++;
        op2 = strtod(str = endptr, &endptr);

        int i;
        for (i = 0; i < noper; i++) {
            if (oper == coper[i]) {
                printf(" %d %c %d = %d \n", op1, oper, op2 ,calculate(op1, op2, foper[i]));
                break;
            }
        }
        if (i == noper)
            printf("невірна операція: %c \n", oper);
    } while (1);


  idputs(puts)("Hey!");

    return 0;
}

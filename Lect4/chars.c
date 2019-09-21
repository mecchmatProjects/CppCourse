
#include <stdio.h>

int f1 ()
{
setlocale (LC_ALL, "ukr");
char str [15] = { 'Т', 'е', 'к', 'с', 'т', ' ', 'і', ' ', 'к', 'р', 'а', 'п', 'к', 'а' '.'};
for (int i = 0; i <15; i ++)
{
printf("%c"str[i]);
}
printf("\n");
return 0;
}

int f2 ()
{
setlocale (LC_ALL, "ukr");
char str [] = "Текст"; // '\ 0' присутній неявно
printf("str=%s\n",str);
return 0;
}

void input1 ()
{
    setlocale (LC_ALL, "rus");
    char siteName [20] = "";
    
    scanf("%s",siteName);
    printf("str=%s\n",siteName);
}

void input2 ()
{
    setlocale (LC_ALL, "rus");
    char siteName [20] = "";
    
   gets(siteName); // deprecated
    puts(siteName);
}

/* 
Optional, but recommended: Documentation section 
Необов’язкова але рекомендована частина 
i.e. comments, that describe the program, like:
 Заголовочні коментарі
First C-style program - Перша програма: 
Обчислення синуса 
*/
#include <stdio.h> // Link section  - заголовочний файл, 
              //бібліотека стандартного вводу-виводу 
#include <math.h> // Link section заголовочний файл, 
              //бібліотека математичних функцій 

//Definition Section and Global declaration section
//Тут можуть бути визначення макросів
//Тут можуть бути визначення глобальних змінних та констант
//Тут можуть бути визначення або декларація функцій

int hello() // головна функція (main function): точка входу (entry point)
{
    // Визначення та/або ініціалізація локальних змінних
    float x; //визначаємо дійсну (одинарної точності) змінну 'x'
    scanf("%F",&x); // введення змінної 'x'
    double y=sin(x); /* Вираз (expression): виклик функції sin, 
                  обчислення виразу та 
                 ініціалізація дійсної змінної (подвійною точності) ‘y’ 
               */
     printf("Result y=%f\n",y); // виведення значення змінної y 
}
#include <stdio.h>
 
int add(int x, int y); // needed so main.cpp knows that add() is a function declared elsewhere
 
int main()
{
    printf("The sum of 3 and 4 is: %d \n ", add(3, 4));
    return 0;
}

#include <stdio.h>
#define MAX  10

#define getName(var)  #var 

void ptr( int x, int *y){
    printf("Адреса %s: %p\n", getName(x), &x);
    printf("Адреса %s: %p\n", getName(y), &y);

    int* ptr_y = y;
    printf("Значення %s: %p, адреса %p  вказує %d \n", getName(ptr_y), ptr_y, &ptr_y, *ptr_y);

    int* ptr2_x = &x;
    printf("Значення %s: %p   вказує %d \n", getName(ptr2_x), ptr2_x, *ptr2_x);

    *y=34;
    
    printf("Значення %s: %p, адреса %p  вказує %d \n", getName(ptr_y), ptr_y, &ptr_y, *ptr_y);
}

int main(){
  int x, y;
  ptr(x, &y);

  printf("Значення %s: %d, адреса %p  \n", getName(y), y, &y);
}

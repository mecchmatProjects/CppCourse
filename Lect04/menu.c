#include <stdlib.h>
#include <stdio.h>
//#include <conio.h>
#include <string.h>

void enter(void), del(void), review(void), quit(void);

int menu(void);

void (*options []) (void) = {
 enter,
 del,
 review,
 quit
};

int main_menu(void){

 int i;
 do{
 i = menu(); /* получение выбора пользователя */
 (*options[i])(); /* выполнение */
 } while(i!=4);
 return 0;
}

int menu(void){

  char ch;
  do {
   printf("1. Enter\n");
   printf("2. Delete\n");
   printf("3. Review\n");
   printf("4. Quit\n");
   printf("Select a number: ");
   ch = getchar();
   printf ("choice: %c \n", ch);
 } while(!strchr("1234",ch));
 
 return ch-49; /* преобразование к целочисленному эквиваленту */
}

void enter(void) {
  printf("In enter.");
}

void del(void){
  printf("In del.");
}

void review(void){
  printf("In review.");
}

void quit (void){
  printf("In quit.");
  exit(0);
}

int main(){
   main_menu();
}

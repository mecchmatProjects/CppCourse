#include <stdio.h>
#include <stdlib.h>

typedef struct MyStack{

   int data;
   struct MyStack* ptr; 
} MyStack;

int main(){

  int x;
  MyStack* p = NULL;
  MyStack* z;

 do {
   scanf("%d",&x);
   z = (MyStack*) malloc(sizeof(MyStack));
   z->data = x;
   z->ptr = p;
   p = z;
 }while(x!=0);

 while(p){
   z = p;  
   printf("%d",p->data);
   p = p->ptr;
   free(z);
 }

}

#include <stdio.h>


enum {
  N_MAX=4 //5
};


//void process(int arr[])
//void process(int arr[4]) 
void process(int* arr){
  for(int i=0;i<N_MAX;++i)
    printf("%d",arr[i]);
  printf("\n");
}


void process_true_arr(int (*pArr)[4]){

  for(int i=0;i<4;++i)
    printf("%d",(*pArr)[i]);

  printf("\n");
}

void process_true_arr2(const int (*const pArr)[4]){

  for(int i=0;i<4;++i)
    printf("%d",(*pArr)[i]);

  printf("\n");
}


/*
void proc(int myArray[const 4]){ // don't work on g++

  for(int i=0;i<4;++i)
    printf("%d",myArray[i]);

  printf("\n");
}*/


int main(){

  int arr[N_MAX]={1,2,3,45};
  int* ptr = arr; // int* ptr =&arr[0];

  arr[2] = 7;
  ptr[2] = 7;

  *(arr+2) = 7;
  *(ptr+2) = 7;

  process(arr);
  //proc(arr);
  process_true_arr(&arr);
  process_true_arr2(&arr);

  printf("\n");
  process(ptr);
 // proc(ptr);
  process_true_arr(ptr);//warning
  process_true_arr2(ptr);//warning

  printf("\n");
  int ar1[3] = {1,2,3};
  int ar2[5] = {1,2,3,4,5};
 
  process(ar1);
  //proc(ar1);
  process_true_arr(&ar1); //warning
  process_true_arr2(&ar1); //warning

  printf("\n");
  process(ar2);
  //proc(ar2);
  process_true_arr(&ar2);//warning
  process_true_arr2(&ar2);//warninh

  printf("\n");
  int ar3[N_MAX] = {1,2,3};
 
  process(ar3);
  //proc(ar3);
  process_true_arr(&ar3); //warning
  process_true_arr2(&ar3); //warning


}

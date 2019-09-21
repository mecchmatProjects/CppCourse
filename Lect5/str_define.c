#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student  // визначаємо структуру з назвою Student 
{ 
 char  name [25]; //  Поле 1:  Прізвище та ініціали – тип рядок з 25 символів 
 char group[3]; //  Поле 2:  Група – тип рядок з 3 символів 
int pract_mark; //  Поле 3:  Бали за практику – тип ціле 
int course_project1; //  Поле 4:  Бали за перший проект – тип ціле 
int course_project2; //  Поле 5:  Бали за другий проект – тип ціле 
float additional_mark; // Поле 6: середній додатковий бал  -тип дійсне число
} st1, st2;

struct Point2D {
   int x, y;
};


struct VectorND {
   size_t n;
   double * v;
} VectorND;


typedef struct {
  int x,y,z;
} Point3D;


int main(){

  struct Credit{ int bals[2][2]; float marks; } cred[10] = { { {{8,8,},{8,8,},},33, }  } ;

  scanf("%s %s %d %d %d %f",st1.name, st1.group, &st1.pract_mark, &st1.course_project1, &st1.course_project2, &st1.additional_mark);
  st2 = st1;
  strcpy(st2.name, "Vasya");
 
  struct Point2D z = {1, 0};
  Point3D t = {0,0,0};

  struct VectorND v = {.n=5};

  v.v = (double*) calloc(v.n, sizeof(*(v.v)));

  printf("%s",st2.name);

  printf("\n %d %d \n", z.x, t.y); 
  
  for(int i=0;i < v.n;i++){
    printf("\t%lf,",v.v[i]);
  }


  printf("Credit %d ", cred[0].bals[0][0]);  

  free(v.v);
}





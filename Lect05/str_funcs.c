#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Credit {
   int marks[2][2];
   float addit;
} Credit;


typedef struct {   
   char * name;
   float mark;
   float proj_mark[2];
   float addit;
   Credit exam; 
} MarkProgram;


void printCredit(Credit c){
   printf("%d %d %d %d",c.marks[0][0], c.marks[0][1],c.marks[1][0],c.marks[1][1]);
}

void printMark(MarkProgram* m){

  printf("Mark of %s:", m->name);
  printf("%f %f %f", m->mark, (*m).proj_mark[0],m->proj_mark[1]);
  
  printCredit(m->exam);
}


Credit inputCredit(){

   Credit c = {0,0,0,0,0.f}; 
   printf("Input 4 marks and additional mark");
   scanf(" %d %d %d %d", &c.marks[0][0], &c.marks[0][1],&c.marks[1][0],&c.marks[1][1]); 
   return c;
}


int inputMark(MarkProgram* z){

   fputs("Input Name", stdin);
   const size_t N = 20;
   char name[N];
   fflush(stdin);
   fgets(name, N, stdin);

   z->name = (char*) malloc(sizeof(name));
   strcpy(z->name, name);

   fputs("Input 3 marks:", stdin);
   fflush(stdin);
   scanf("%f %f %f", &z->mark, &z->proj_mark[0], &z->proj_mark[1]); 
   
   z->exam = inputCredit();

   return 0;
}

void deleteMark(MarkProgram m){
  free(m.name);
}

int main(){

  MarkProgram* m;
  int n;
  printf("Number of students");
  scanf("%d ", &n);
 
  m = (MarkProgram*) malloc(n * sizeof(*m));

  for(int i=0; i<n;i++) {
   inputMark(&m[i]);
  }

  for(int i=0; i<n;i++) {
   printMark(&m[i]);
   deleteMark(m[i]);
  }

  free(m);
}

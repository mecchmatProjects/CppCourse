#include <stdio.h>

#define N 3
#define M 3


int vvod (int matrix[][M]){

 int i,j;
 for (i = 0; i < N; i++) {
  for (j = 0; j < M; j++) {
   printf("Enter value %d %d:", i, j);
   scanf("%d", &matrix[i][j]);
  }
 }

 return 0;
}

void print(int matrix[N][M]){
int i,j;
for (i = 0; i < N; i++) {
 for (j = 0; j < M; j++) {
   printf("%d ", matrix[i][j]);
  }
 printf("\n"); 
}

}


int main() {

int matrix[N][M], transposed[N][M];
int i, j, n, m;

printf("input n, m: ");
scanf("%d %d", &n, &m);
 
vvod(matrix);

for (i = 0; i < N; i++) {
 for (j = 0; j < M; j++) {
  if (matrix[i][j] == m) {
  matrix[i][j] = n;
 }
}
}
 

printf("original matrix with replaced elements: \n");

print(matrix);

}

#include <stdio.h>

#define N 10
#define M 10

int main(){

  int n,m;
  int a[N][M];

  scanf("%d %d",&n,&m);
  
  for (int i=0; i<n;++i){
    printf("row %d:  ",i);
    for (int j=0; j<m;++j){
       scanf("%d",&a[i][j]);
    }    
  }

  
for (int i=0; i<n;++i){
    printf("\n");
    for (int j=0; j<m;++j){
       printf("%d ",a[i][j]);
    }    
    
  }

}

#include <stdio.h>

#define SIZE 25

int main (){
const size_t size = 25;
//double arr[size] = {5}; C++
double arr[SIZE] = {5};
int i,j;

for (size_t i=0; i<size; ++i)
{
printf("arr[%lu]=%lf \n",i,arr[i]);
}
for (size_t i=0; i<size; ++i){
scanf("%lf",&arr[i]);
}
for (size_t i=0; i<size; ++i)
{
printf("arr[%lu]=%lf,\t" ,i,arr[i]);
}
getchar();

int a1[3][4] = { 
   {0, 1, 2, 3,} ,   /*  initializers for row indexed by 0 */
   {4, 5, 6, 7,} ,   /*  initializers for row indexed by 1 */
   {8, 9, 10, 11,}   /*  initializers for row indexed by 2 */
};

int a2[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};


for ( i = 0; i < 5; i++ ) {      
for ( j = 0; j < 2; j++ ) {
        printf("a[%d][%d] = %d\n", i,j, a1[i][j] );      }
   }

        
for(i = 0; i < 5; i = i + 1) {
      for(j = 0; j < 7; j = j + 1)
             a2[i][j] = 10 * i + j;
      
}
                

for(i = 0; i < 5; i = i + 1) {
      for(j = 0; j < 7; j = j + 1)
              printf("%d\t", a2[i][j]);
      printf("\n");
     }

return 0;
}

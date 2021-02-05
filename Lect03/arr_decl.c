#include <stdio.h>
#define NUM 5

int main (){

	const size_t size = 25;
	//double arr[size] = {5}; //variable-sized object may not be initialized (on C only, C++ good)
        double arr[NUM] = {5};

	for (size_t i=0; i<size; ++i){
		printf("arr[%lu]=%lf \n",i,arr[i]);
	}
	for (size_t i=0; i<size; ++i){
		scanf("%lf",&arr[i]);
	}
	for (int i=0; i<size; ++i){
		printf("arr[%d]=%lf,\t" ,i,arr[i]);
	}



	int a1[3][4] = {  
   		{0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
   		{4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
   		{8, 9, 10, 11}   /*  initializers for row indexed by 2 */
	};

	int a2[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

	for (int i = 0; i < 3; i++ ) {      
		for (int j = 0; j < 4; j++ ) {
        		printf("a2[%d][%d] = %d\n", i,j, a1[i][j] );
		      }
   		}

        int i, j;
        for(i = 0; i < 3; i = i + 1){
                for(j = 0; j < 4; j = j + 1){
                        a2[i][j] = 10 * i + j;
                }
	}
                
        for(i = 0; i < 3; i++){
                for(j = 0; j < 4; j++)
                        printf("%d\t", a2[i][j]);
                printf("\n");
                }
	getchar();
}

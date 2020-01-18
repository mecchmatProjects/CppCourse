#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 5;

void use_malloc(void)
{
    //malloc
    int *p1 = malloc(N*sizeof(int));  // allocates enough for an array of 4 int
    int *p2 = malloc(sizeof(int[N])); // same, naming the type directly
    int *p3 = malloc(N*sizeof *p3);   // same, without repeating the type name

    if(p1) {
        for(int i=0; i<N; ++i) // populate the array
            p1[i] = i*i;
        for(int i=0; i<N; ++i) // print it back out
            printf("p1[%d] == %d\n", i, p1[i]);
    }


    free(p1);
    free(p2);
    free(p3);

    //calloc
    int *c1 = calloc(N, sizeof(int));    // allocate and zero out an array of 4 int
    int *c2 = calloc(1, sizeof(int[N])); // same, naming the array type directly
    int *c3 = calloc(N, sizeof *c3);     // same, without repeating the type name

    if(c2) {
        for(int i=0; i<4; ++i) // print the array
            printf("c2[%d] == %d\n", i, c2[i]);
    }

    free(c1);
    free(c2);
    free(c3);

    //realloc
    int *pa = malloc(2 * N * sizeof *pa); // allocate an array of 10 int
    if(pa) {
        printf("%zu bytes allocated. Storing ints: ", 10*sizeof(int));
        for(int i = 0; i < 2 * N; ++i)
            printf("%d ", pa[i] = i);
    }

    int *pb = realloc(pa, 10 * N * sizeof *pb); // reallocate array to a larger size
    if(pb) {
        printf("\n%zu bytes allocated, first 10 ints are: ", 10 * N * sizeof(int));
        for(int j = 0; j < 10; ++j)
            printf("%d ", pb[j]); // show the array
        free(pb);
    } else { // if realloc failed, the original pointer needs to be freed
        free(pa);
    }

    //aligned_alloc
    int *a1 = malloc(10*sizeof *a1);
    printf("default-aligned addr:   %p\n", (void*)a1);
    free(a1);

    int *a2 = aligned_alloc(1024, 1024*sizeof *a2);
    printf("1024-byte aligned addr: %p\n", (void*)a2);
    free(a2);


    //free
    int *q1 = malloc(10*sizeof *q1);
    free(p1); // every allocated pointer must be freed

    int *q2 = calloc(10, sizeof *q2);
    int *q3 = realloc(q2, 1000*sizeof *q3);
    if(q3) // p3 not null means p2 was freed by realloc
        free(q3);
    else // p3 null means p2 was not freed
        free(q2);

}

int allocate_char() {

   char name[100];
   char *description;

   strcpy(name, "Zara Ali");

   /* allocate memory dynamically */
   description = malloc( 30 * sizeof(char) );
	
   if( description == NULL ) {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   } else {
      strcpy( description, "Zara ali a DPS student.");
   }
	
   /* suppose you want to store bigger description */
   description = realloc( description, 100 * sizeof(char) );
	
   if( description == NULL ) {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   } else {
      strcat( description, "She is in class 10th");
   }
   
   printf("Name = %s\n", name );
   printf("Description: %s\n", description );

   /* release memory using free() function */
   free(description);
}


int mainm()
{
    use_malloc();
    allocate_char();
}

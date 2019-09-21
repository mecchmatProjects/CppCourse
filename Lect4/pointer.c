#include <stdio.h>

int main () {

int  var = 20;   /* actual variable declaration */
int  *ip;        /* pointer variable declaration */

ip = &var;  /* store address of var in pointer variable*/

printf("Address of var variable: %x\n", &var  );

/* address stored in pointer variable */
printf("Address stored in ip variable: %x\n", ip );

/* access the value using the pointer */
printf("Value of *ip variable: %d\n", *ip );


int  *ptr = NULL;
printf("The value of ptr is : %x\n", ptr  );



int  arr[10] = {10, 100, 200,3000, 200, 10, };
int  i;
/* let us have array address in pointer */
ptr = arr;

for ( i = 0; i < MAX; i++) {
printf("Address of var[%d] = %x\n", i, ptr );
printf("Value of var[%d] = %d\n", i, *ptr );
/* move to the next location */
ptr++;
}

/* let us have array address in pointer */
ptr = &ar[MAX-1];

for ( i = MAX; i > 0; i--) {
printf("Address of var[%d] = %x\n", i-1, ptr );
printf("Value of var[%d] = %d\n", i-1, *ptr );

/* move to the previous location */
ptr--;
}

while ( ptr <= &arr[MAX - 1] ) {

printf("Address of var[%d] = %x\n", i, ptr );
printf("Value of var[%d] = %d\n", i, *ptr );
ptr+=2;
i+=2;
}

int *ptr2[MAX];

for ( i = 0; i < MAX; i++) {
ptr2[i] = &arr[i]; /* assign the address of integer. */
}

for ( i = 0; i < MAX; i++) {
printf("Value of var[%d] = %d\n", i, *ptr2[i] );


return 0;
}

/*результат роботи коду:
Address of var variable: bffd8b3c
Address stored in ip variable: bffd8b3c
Value of *ip variable: 20*/

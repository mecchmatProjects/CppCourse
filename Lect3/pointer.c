#include <stdio.h>

const size_t MAX = 10;

int main_ptr() {

int  var = 20;   /* actual variable declaration */
int  *ip;        /* pointer variable declaration */

ip = &var;  /* store address of var in pointer variable*/

//printf("Address of var variable: %x\n", &var  ); works but with warning: %x - not int* 
printf("Address of var variable: %p\n", &var  );

/* address stored in pointer variable */
printf("Address stored in ip variable: %p\n", ip );

/* access the value using the pointer */
printf("Value of *ip variable: %d\n", *ip );


int  *ptr = NULL;
printf("The value of ptr is : %p\n", ptr  );



int  arr[MAX] = {10, 100, 200,3000, 200, 10, };
int  i;
/* let us have array address in pointer */
ptr = arr;

for ( i = 0; i < MAX; i++) {
    printf("Address of var[%d] = %p\n", i, ptr );
    printf("Value of var[%d] = %d\n", i, *ptr );
    /* move to the next location */
    ptr++;
}

/* let us have array address in pointer */
ptr = &arr[MAX-1];

for ( i = MAX; i > 0; i--) {
printf("Address of var[%d] = %px\n", i-1, ptr );
printf("Value of var[%d] = %d\n", i-1, *ptr );

/* move to the previous location */
ptr--;
}

while ( ptr <= &arr[MAX - 1] ) {

    printf("Address of var[%d] = %px\n", i, ptr );
    printf("Value of var[%d] = %d\n", i, *ptr );
    ptr+=2; i+=2;
}

int *ptr2[MAX];

for ( i = 0; i < MAX; i++) {
    ptr2[i] = &arr[i]; /* assign the address of integer. */
}
for ( i = 0; i < MAX; i++) {
    printf("Value of var[%d] = %d\n", i, *ptr2[i] );
}

return 0;
}

/*Pезультат роботи коду:
Address of var variable: 0x7ffc085bfe18
Address stored in ip variable: 0x7ffc085bfe18x
Value of *ip variable: 20
The value of ptr is : (nil)x
 
Address of var[0] = 0x7ffc085bfe40x
Value of var[0] = 10
Address of var[1] = 0x7ffc085bfe44x
Value of var[1] = 100
Address of var[2] = 0x7ffc085bfe48x
Value of var[2] = 200
Address of var[3] = 0x7ffc085bfe4cx
Value of var[3] = 3000
Address of var[4] = 0x7ffc085bfe50x
Value of var[4] = 200
Address of var[5] = 0x7ffc085bfe54x
Value of var[5] = 10
Address of var[6] = 0x7ffc085bfe58x
Value of var[6] = 0
Address of var[7] = 0x7ffc085bfe5cx
Value of var[7] = 0
Address of var[8] = 0x7ffc085bfe60x
Value of var[8] = 0
Address of var[9] = 0x7ffc085bfe64x
Value of var[9] = 0
 
Address of var[9] = 0x7ffc085bfe64x
Value of var[9] = 0
Address of var[8] = 0x7ffc085bfe60x
Value of var[8] = 0
Address of var[7] = 0x7ffc085bfe5cx
Value of var[7] = 0
Address of var[6] = 0x7ffc085bfe58x
Value of var[6] = 0
Address of var[5] = 0x7ffc085bfe54x
Value of var[5] = 10
Address of var[4] = 0x7ffc085bfe50x
Value of var[4] = 200
Address of var[3] = 0x7ffc085bfe4cx
Value of var[3] = 3000
Address of var[2] = 0x7ffc085bfe48x
Value of var[2] = 200
Address of var[1] = 0x7ffc085bfe44x
Value of var[1] = 100
Address of var[0] = 0x7ffc085bfe40x
Value of var[0] = 10

 
Address of var[0] = 0x7ffc085bfe3cx
Value of var[0] = 0
Address of var[2] = 0x7ffc085bfe44x
Value of var[2] = 100
Address of var[4] = 0x7ffc085bfe4cx
Value of var[4] = 3000
Address of var[6] = 0x7ffc085bfe54x
Value of var[6] = 10
Address of var[8] = 0x7ffc085bfe5cx
Value of var[8] = 0
Address of var[10] = 0x7ffc085bfe64x
Value of var[10] = 0
 
Value of var[0] = 10
Value of var[1] = 100
Value of var[2] = 200
Value of var[3] = 3000
Value of var[4] = 200
Value of var[5] = 10
Value of var[6] = 0
Value of var[7] = 0
Value of var[8] = 0
Value of var[9] = 0

 */

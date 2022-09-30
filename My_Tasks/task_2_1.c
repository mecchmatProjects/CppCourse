//Task 2.1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {
	int x;
	printf("Enter x: ");
	scanf("%d", &x);
  	double result = cos(x);
        printf("cos(x) = %.2lf", result);
	return 0;
}

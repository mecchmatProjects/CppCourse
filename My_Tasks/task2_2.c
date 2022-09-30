//Task 2.2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {
	int a, b;
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
  	 double c = sqrt(a*a + b*b);
     printf("c = %.2lf", c);
	return 0;
}

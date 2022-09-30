//Task 2.3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {
	int a, b, c;
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
	printf("Enter c: ");
	scanf("%d", &c);
	double p = (a+b+c)/2;
  	 double S = sqrt(p*(p-a)*(p-b)*(p-c));
     printf("S = %.2lf", S);
	return 0;
}

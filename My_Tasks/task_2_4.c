//Task 2.4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double y(int x) {
	int x4 = x*x*x*x;
	return 16*x4+(8*x4/x)+(4*x4/x/x)+2*x+1;
}

int main(int argc, char *argv[]) {
	int x;
	printf("Enter x: ");
	scanf("%d", &x);
  	 double res = y(x);
     printf("y(x) = %.2lf", res);
	return 0;
}

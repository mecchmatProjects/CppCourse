//Task 2.5

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Rosenbrock2d(int x, int y) {
	return 100*pow((x*x-y), 2) + pow(x-1, 2);
}

int main(int argc, char *argv[]) {
	int x, y;
	printf("Enter x: ");
	scanf("%d", &x);
	printf("Enter y: ");
	scanf("%d", &y);
  	 double res1 = Rosenbrock2d(x, y);
     printf("result1 = %.2lf", res1);
     printf("\n");
    double res2 = Rosenbrock2d(20, 10);
     printf("result2 = %.2lf", res2);
     printf("\n");
    double res3 = Rosenbrock2d(1, 2);
     printf("result3 = %.2lf", res3);
	return 0;
}

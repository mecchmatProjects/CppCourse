//1.4
#include <stdio.h>
#include <math.h>

int main()
{
    double m1, m2, r;
	printf("Enter m1: ");
	scanf("%lf",&m1);
	putchar('\n');
	printf("Enter m2: ");
	scanf("%lf",&m2);
	putchar('\n');
	printf("Enter r: ");
	scanf("%lf",&r);
	
	double y = 6.673 * pow(10, -11);
	double F = y * ((m1*m2) / pow(r, 2));
	printf(" F = %lf", F);
	return 0;
}
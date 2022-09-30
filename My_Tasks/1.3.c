//1.3
#include <stdio.h>
#include <math.h>

int main()
{
	double a;
	
	printf("Enter a: ");
	scanf("%lf", &a);
	
	printf("%lf) ", a  );
	putchar('\n');
	printf("%lf - %lf - %lf - %lf", a);
	putchar('\n');
	printf("%lf | %lf | %lf | %lf", a);
	putchar('\n');
	printf("- %lf - %lf - %lf", a);
	return 0;
}
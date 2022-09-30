//1.5
#include <stdio.h>
#include <math.h>

int main()
{
	long x;
	printf("Enter x: ");
	scanf("%ld", &x);
	long long x2 = x*x;
	long long x4 = x2*x2;
	long long x6 = x4*x2;
	long long x9 = x6*x4/x;
	long long x15 = x9 * x6;
	unsigned long long x28 = x15*x15/x2;
	unsigned long long x64 = x28*x28*x9/x;
	
	printf("x^2 = %lld\n", x2);
	printf("x^4 = %lld\n", x4);
	printf("x^6 = %lld\n", x6);
	printf("x^9 = %lld\n", x9);
	printf("x^15 = %lld\n", x15);
	printf("x^28 = %lld\n", x28);
	printf("x^64 = %lld\n", x64);
}
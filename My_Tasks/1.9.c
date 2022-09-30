//1.9
#include <stdio.h>
#include <math.h>

int main(){
	double a, b;
	printf("Number 1: ");
	scanf("%lf", &a);
	printf("Number 2: ");
	scanf("%lf", &b);
	double average1 = (a+b)/2;
	double average2 = (1/a)+(1/b);
	printf("average1 nauk: %lf\n" ,average1);
	printf("average1 desiatkove: %lf\n" , (int)average1);
	printf("average2 nauk: %lf\n", average2);
	printf("average2 desiatkove: %lf\n", (int)average2);
	
	return 0;
}
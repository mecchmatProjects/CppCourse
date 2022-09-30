//1.8
#include <stdio.h>
#include <math.h>
int main()
{
	double row1, row2;
	printf("Enter row1: ");
	scanf("%lf", &row1);
	printf("");
	printf("Enter row2: ");
    scanf("%lf", &row2);
	double difference = row1-row2;
	double product = row1*row2;
    printf("Difference: %lf\n", difference); 
    printf("Product: %lf\n", product);
	return 0;
}
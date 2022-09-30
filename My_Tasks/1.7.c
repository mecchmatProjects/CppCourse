//1.7
#include <stdio.h>
#include <math.h>

int main()
{
	double x = -123.321;
	printf("Enter x: ");
	scanf("%lf", &x);
	double tsila0 = (int)x;
	double drobna0 = x-tsila0;
	double Bigger0 = tsila0+1;
	double Less0 = tsila0-1;
	int rounded0 = (int)(x+0.5f);
		
	double tsila;
	double drobna = modf(x, &tsila);
	double Bigger = tsila+1;
	double Less = tsila-1;
	double rounded = round(x);
	printf("Tsila: %lf\n: ", tsila);
	printf("Drobna: %lf\n: ", drobna);
	printf("Bigger: %lf\n: ", Bigger);
	printf("Less: %lf\n: ", Less);
	printf("Rounded: %lf\n: ", rounded);
	
	return 0;
}
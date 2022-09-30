//2.6

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dovzhinaVidrizka(int x1, int x2, int y1, int y2) {
	  return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double Square(double a, double b, double c) {
	double p = (a + b + c) / 2;
    double s = pow(p*(p - a)*(p - b)*(p - c),0.5);
    return s;
}

int main(int argc, char *argv[]) {
	int xA, yA;
	int xB, yB;
	int xC, yC;
	printf("Enter xA, yA: ");
	scanf("%d", &xA);
	scanf("%d", &yA);
	printf("\n");
  	printf("Enter xB, yB: ");
	scanf("%d", &xB);
	scanf("%d", &yB);
	printf("\n");
	printf("Enter xC, yC: ");
	scanf("%d", &xC);
	scanf("%d", &yC);
	printf("\n");
	double AB = dovzhinaVidrizka(xA, xB, yA, yB);
	double AC = dovzhinaVidrizka(xA, xC, yA, yC);
	double BC = dovzhinaVidrizka(xB, xC, yB, yC);
	double res = Square(AB, AC, BC);
	printf("%.2f", res);
	
	return 0;
}

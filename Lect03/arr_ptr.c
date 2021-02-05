#include <stdio.h>

int main(){
	float mas[] = {1.0f, 2.54f, 1.26e-01, 5.45E+5,};
	float *p1, *p2, *p3;
	p1 = &mas[0];
	p2 = &mas[2];
	printf("\n %ld",p2-p1);
	p2[1] = 2.3f;
	printf("\n %f",p1[3]); 
	p3 = ++p1;  
	printf("\n %f %f %f",p1[2], p3[1], p2[1]);
	p3[0]++;
	printf("\n %f %f %f",p1[0], p3[0], p2[1]);
}

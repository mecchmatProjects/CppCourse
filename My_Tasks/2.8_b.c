#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double bis(int a, int b, int c)
{
    return sqrt(b*c*(a + b + c)*(b + c - a)) / (b + c);
}

int main(int argc, char *argv[]) {
	int a, b, c;
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
	printf("Enter c: ");
	scanf("%d", &c);
 if (a < b + c && b < a + c && c < a + b)
    {
    	printf("Bisektrisa do a");
       printf("%.3f", bis(a, b, c));
    printf("Bisektrrisa do b");
       printf("%.3f", bis(b, a, c));
       	printf("Bisektrisa do c");
       printf("%.3f", bis(c, b, a));
    }
    else
    {
       printf("Trikutnik ne isnue\n");
    }
	return 0;
}

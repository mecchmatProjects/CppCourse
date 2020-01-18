/* Optional, but recommended: Documentation section
   i.e. comments, that describe the program, like: 
   First C-style program */
#include <stdio.h> // headers (Link section)
#include <math.h>


int main0(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}


//Definition Section and Global declaration section
int main1() // main function: entry point
{
    
    float x; //define real variable 'x'
    scanf("%F",&x); // input 'x'
    double y=sin(x); // expression: calculate y
	printf("Result y=%f\n",y); // output
    
    double z; //define real variable 'x'
    scanf("%lf",&z); // input 'z'
    
    getchar();
    return 0;
}

 
const float pi = 3.14158f;
void student_bottles()
{
int number=5, cost=11000, s=-777;
float bat=255, x=12.345;
printf ("%d students drank %f bottles.\n", number, bat);
printf ("Value of pi is%f.\n", pi);
printf ("The price is %d%s\n", cost,"ó.å");
printf ("x=%-8.4f s=%5d%8.2f ", x, s, x);
getchar();
}
 
int f_scanf(){
int course;
float grant;
char name[20];
printf ( "Âêàæ³òü âàø êóðñ, ñòèïåíä³þ, ³ì’ÿ \n");
scanf ( "%d%f", &course, &grant);
scanf ( "%s", name); /* ”&” â³äñóòí³é ïðè çàçíà÷åíí³ ìàñèâó ñèìâîë³â */

printf("%s %d %f",name, course, grant);
return 0;
}

int main(){
    
main0(0,NULL);
main1(); 
student_bottles();

 f_scanf();
    
}



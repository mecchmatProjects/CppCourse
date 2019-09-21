#include <stdio.h>

int op (char c, int x, int y){
    if (c=='+') return x+y;
    else if (c=='-') return x-y;
    else if (c=='*') return x*y;
    else if (c=='/') return x/y;
    else printf("\n wrong char!\n");
    return -1; // if we don't return there it is warning
}

float cube(float d){
    return d*d*d;
}


void f1(){};
void f2(void){};
void f3(){ return;}
void f4(void) {return;}

void MyFuncMultDouble(double x, double y){
    double z;
    z = x*y;
    printf("r=%f \n", z); // âèâ³ä ðåçóëüòàòó
    return;
}

int Mult5(int d){
    int res;
    res = d * 5;
    return res; // ïîâåðíåííÿ ðåçóëüòàòó
}

int MaxInt3(int a, int b, int c){
    int max;
    max = a;
    if (max<b) max = b;
    if (max<c) max = c;
    return max;
}

float MaxFloat(float x, float y)
{
    if (x>y) return x;
    else return y;
}

int main(int argc, char **argv)
{
	printf("hello world\n");
    
    float s, f=0.55; 
    s=cube(f);
    
    char c;
    scanf("%c",&c);
    c= getchar();
    printf("%d",op(c,1,2));
    int r = op ( '+', 5 ,4 );
    printf("s=%f r=%d",s, r);
    
    MyFuncMultDouble(1,2);
    MyFuncMultDouble(2.5, -2.0); // áóäå âèâåäåíî -5
    MyFuncMultDouble(1.85, -2.23); // áóäå âèâåäåíî -4.1255
    
    int x, y;
x = 20;
y = Mult5(x);   // y = 100
y = Mult5(-15); // y = -75


float Max; // çì³ííà - ðåçóëüòàò

Max = MaxFloat(29.65f, (float)30); // Max = 30.0

int a = 8, b = 5, c1 = -10;
int res;
res = MaxInt3(a, b, c1);       // res = 8
res = MaxInt3(a, b+10, c+15); // res = 15
res = MaxInt3(11, 2, 18);     // res = 18

double x1 = 10.99;
double y1= 10.999;
Max = MaxFloat(x1, y1); // Max = 10.999
printf("max=%f",Max);
Max = MaxFloat((float)x, (float)y); // Max = 10.999 - òàê íàä³éí³øå
printf("max=%f",Max);
    
	return 0;
}

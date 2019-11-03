#include <iostream>

using namespace std;
class Dummy {
 
    double i,j;
};

class Addition {
    int x,y;
  public:
    Addition (int a, int b) { x=a; y=b; }
    int result() { return x+y;}
};

int main(){

short a=2000;
int b;
b=a;

cout<<b<<endl;

int a1=2000;
short b1;
b1=a1;
cout<<b1<<endl;
b1=(short)a1;

cout<<b1<<endl;
int x=1;
unsigned y;

y =x;
cout<< y<<endl;

int x1=1;
unsigned y1;

y1 =x1;
cout<< y1<<endl;

const int a2=2000;
int b2;
b2=a2;
cout<<a2<<b2<<endl;
int a3=2000;
//const int b3;

const int b3 = a3 ;

cout<<b3<<endl;

int x2=1;
float y2; double z2;

y2 =x2; 
z2=y2;

cout<<x2<<","<<y2<<","<<z2<<endl;

double x3=1;
float y3; int z3;
y3 = x3;
z3= y3;

cout<<x3<<","<<y3<<","<<z3<<endl;

int x4=199;
int y4,z4;
y4 = int (x4);    // functional notation
z4 = (int) x4;    // c-like cast notation 
cout<<y4<<z4;

  Dummy d;
  Addition * padd;
  padd = (Addition*) &d; //Is it good???
  cout << padd->result();
  
}
/* 2000
2000
2000
1
1
20002000
2000
1,1,1
1,1,1
199 199 4197760
*/

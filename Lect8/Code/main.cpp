#include <iostream>
#include "Poly.h"
#include "Monomial.h"

using namespace std;

int Monomial::count = 0;

struct Point2D {
    // public:
    // members
    double x;
    double y;
    //methods
    void show() {
        cout<<"P("<<x<<","<<y<<")"<<endl;
    }
};


class TimeH
{
    // private:
    //members
    int hours;
    int minutes;
    //methods
    int getTotalMinutes() {
        return hours*60 + minutes;
    }

public:
    // Constructor(s)
    //TimeH(int h, int m){ setTime(h,m);}
    TimeH(int h=0, int m=0) {
        setTime(h,m);
    }
    //TimeH():hours(0),minutes(0){}

    //methods
    void show() {
        cout<<"H:"<<hours<<":"<<minutes<<" ";
    }

    void setHours(int x) {
        if (0<=x && x<=23) {
            hours = x;
        }
    }

    void setMinutes(int x) {
        if (0<=x && x<=59) {
            minutes = x;
        }
    }

    bool setTime(int h, int m); 
    bool is_less(TimeH other);
};


bool TimeH::setTime(int h, int m)
{
    if (0>h || h>23 || 0>m || m>59) {
        return false;
    }
    hours = h;
    minutes = m;
    return true;
}

bool TimeH::is_less(TimeH other)
{
    int m = getTotalMinutes();
    return m < other.getTotalMinutes();
}

int main(int argc, char **argv)
{
    Point2D p1;
    Point2D p2 {1,2};
    Point2D* p3 = new Point2D;

    p1.x = 11;
    p1.y = 22;
    (*p3).x=44;
    p3->y = 55;

    p3->show();
    p2.show();
    p1.show();

    delete p3;

    TimeH q1;
    //TimeH q2{1,2}; //* error: no matching function for call to ...
    //TimeH* q3 = new TimeH{3,4};//error: could not convert '{3, 4}' from '<brace-enclosed initializer list>' to 'TimeH'
    TimeH* q4 = new TimeH;

    //q1.hours = 12; q1.minutes=25; // error: int TimeH::hours' is private within this context
    //q4->hours = 23; q4->minutes = 33;// error: int TimeH::hours' is private within this context
    q1.setHours(12);
    q1.setMinutes(25);

    (*q4).setHours(23); // access through pointer
    q4->setMinutes(33); // access through pointer (syntax sugar)

    q1.show();
    q4->show();
    //q1.getTotalMinutes();//error: getTotalMinutes() is private within this context
    /*
    int h,m;
    cin>>h>>m;
    if(q1.setTime(h,m)) {
        q1.show();
    }
    cin>>h>>m;
    if(q1.setTime(h,m)) {
        q1.show();
    } else {
        cout<<"Uncorrect initialization";
    }
    */
    delete q4;

    TimeH q21(23,45);
    q21.show();
    TimeH q2 {1,2}; //C++98 style
    q2.show();

    q1 = {3,4};
    q1.show();
    if(q2.is_less(q21)) {
        q2.show();
        cout<<"less then";
        q21.show();
    }
    
    double a[] = {1,2,3};
    Poly polin(3,a);
    cout<<"P="<<polin.value(1);
    
    Poly polin2(polin);
    polin2.show();
    cout<<"P2="<<polin2.value(2);
    
    Poly polin3{polin};
    polin3.show();
    cout<<"P3="<<polin3.value(3);
    
    Poly pol[10];
    
    pol[0] = polin;
    pol[0].show();
    cout<<"P4="<<pol[0].value(4);
    
    Poly* pol2 = new Poly[2]; 
    pol2[0] = pol2[1] = polin2;
    pol2[1].show();
    cout<<"P5="<<pol2[1].value(5);

    delete[] pol2;
    
    Monomial g1(5, 2.56);  
    cout<<"Pwr="<<g1.power(2,3);
    cout<<"Pwr="<<Monomial::power(2,3);
    cout<<"Res="<<g1.value(2);

    cout<<"Cnt="<<g1.show_count();
  
    return 0;
}
/*
P(44,55)
P(1,2)
P(11,22)
H:12:25
H:23:33
11 12
H:11:12
11 88
Uncorrect initialization
*/

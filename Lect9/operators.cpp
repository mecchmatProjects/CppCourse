#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Vector2D
{
protected:
    double x;
    double y;
    static double eps(void);
public:
    Vector2D() {}
    Vector2D(double x, double y):x(x),y(y) {}

    friend ostream &operator<<( ostream &output, const Vector2D &D ) {
        output << "(" << D.x << " , " << D.y << ")";
        return output;
    }

    friend istream &operator>>( istream  &input, Vector2D &D ) {
        input >> D.x >> D.y;
        return input;
    }

    Vector2D operator+(const Vector2D& b) {
        return Vector2D(x+b.x, y+b.y);
    }

    Vector2D operator-(const Vector2D& b) {
        return Vector2D(x-b.x, y-b.y);
    }

    Vector2D operator-(void) {
        return Vector2D(-x, -y);
    }

    Vector2D operator=(const Vector2D& b) {
        x = b.x;
        y = b.y;
        return Vector2D(x,y);
    }
    
    friend bool operator!=(const Vector2D& left, const Vector2D& right) {
        return (abs(left.x-right.x)>=eps()) || (abs(left.y-right.y)>=eps());
    }
    
    bool operator==(const Vector2D& right) {
        return (fabs(x-right.x)< eps()) && (fabs(y-right.y)<eps());
    }

    void show() {
        cout<<x<<","<<y<<endl;
    }

};

double Vector2D::eps(void){
    return 0.0001;
}

const Vector2D ZERO(0,0); 

class NamedVector2D: public Vector2D {
private:
    string name_x;
    string name_y;
public:
    NamedVector2D(){}
    NamedVector2D(double x1, double y1){
        this->x = x1;
        this->y= y1;
        name_x ="x";
        name_y ="y";
        }
    NamedVector2D(double x1, double y1, string name, string name2){
        this->x = x1;
        this->y = y1;
        name_x =name;
        name_y =name2;
    }
    NamedVector2D(string name, string name2):Vector2D(0,0),name_x(name),name_y(name2){}
    
    /*NamedVector2D(Vector2D c){
        NamedVector2D* d;
        d = (NamedVector2D*)&c;
        this->x= d->x;
        this->y= d->y;
        name_x= "x",name_y="y";
    
        }*/
    NamedVector2D operator+(const NamedVector2D& b) {
        return NamedVector2D(x+b.x, y+b.y);
    }
  

    void show() {
        cout<<name_x<<","<<name_y<<endl;
        cout<<this->x<<","<<this->y<<endl;
    }
};


int main()
{

    Vector2D a(1,1);
    Vector2D b(1,1);
    Vector2D c,d;

    if(a!=b){
        cout<<"a!=b"<<endl;
    }else{
        cout<<"a==b"<<endl;
    }

    c = a + b;
    c.show();
    c = c - a;
    cout<<c<<endl;
    cin>>c;
    if(-c==ZERO){
        cout<<"zero";
    }
    else{
        cout<<c;
    }
    
    NamedVector2D z(2,2);
    NamedVector2D t(3,4,"x","y");
    NamedVector2D w("X","Y"); 
    z.show();
    t.show();
    w = z + t;
    w.show();
}

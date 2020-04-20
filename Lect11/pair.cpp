#include <iostream>
#include <utility> 
#include <cmath>

using namespace std;

 
// êëàññ point íàñëåäóåòñÿ îò êëàññà pair<float, float>

class point : protected pair<float, float>{

public:
     point(void) { first = second = 0; }
 point(float x, float y) {

 first = x;
 second = y;
 }
 

 point operator -(const point& sub) {
   point p(*this);
   p.first -= sub.first;
   p.second -= sub.second;
   return p; // ðàçíèöà ïî êîîðäèíàòàì

 }

 float abs(void) {

 return sqrt(first * first + second * second);

 return 0;

 }

 

 inline friend ostream& operator <<(ostream& out, const point& obj) {

 return out << "<" << obj.first << "," << obj.second << ">";

 //return out;

 }

};

 

int main(int argc, char *argv[]) {

 point p1(1, 3), p2(3, 1);

 cout << "the distance between two points " << p1 << " & " << p2

 << " is " << (p1 - p2).abs() << endl;
}

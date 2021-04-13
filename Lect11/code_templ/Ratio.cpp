
#include <iostream>

using namespace std;

template<class T>
class Ratio{
  T x;
  T y;
public:

  Ratio(){};
  Ratio(T x1, T y1):x(x1),y(y1){};

  Ratio add(const Ratio& a){
    return Ratio(a.x*y+a.y*x, a.y*y);
  }

  friend ostream &operator<<( std::ostream &output, const Ratio &D ) {
    output << D.x << "/" << D.y <<endl;
    return output;
  }

};


int main(){

 Ratio<int> r1(1,2);
 Ratio<int> r2(1,3);

 Ratio<int> z;
 z = r1.add(r2);

 cout<<z;
}


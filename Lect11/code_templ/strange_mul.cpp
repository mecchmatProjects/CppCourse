#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2, class T3> 
	T3 strange_mul(T1 x, T2 y) {
	T3 res = static_cast<T3>(x) * static_cast<T3>(y);
	return res;
}
int main(){
long long y1 =  strange_mul<int, unsigned,long long>(1,2);
double y2 =  strange_mul<float, int, double>(1.0f,2);
//double y3 =  strange_mul<float, string, double>(1.0f,"2"); //error: invalid static_cast 
//string y4 =  strange_mul<string, string, string>("1","2"); // error: no match for ‘operator*’
}

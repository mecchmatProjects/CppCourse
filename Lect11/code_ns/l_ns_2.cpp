// використання простору імен без директиви using
#include <iostream>
using namespace std;
namespace NewNsOne{
// декларація змінної в NewNsOne
int p = 4;
// декларація функції в NewNsOne
int funct(int q);
}
namespace NewNsTwo{
// декларація змінної в NewNsTwo
int r = 6;
// декларація функції в NewNsTwo
int funct1(int numb);
// декларація вкладеного простору імен
namespace InNewNsTwo {
// декларація змінної в InNewNsTwo
long tst = 20.9456;
}
}
int main(){
/* наступний код згенерує помилку тому що це не загальний простір імен а
головна функція main */
// namespace local {
//
int k;
// }
cout<<"NewNsOne::p is "<<(NewNsOne::p)<<endl;cout<<"NewNsTwo::r is "<<(NewNsTwo::r)<<endl;
cout<<"NewNsTwo::InNewNsTwo::tst"<<(NewNsTwo::InNewNsTwo::tst)<<endl;
}
/*
NewNsOne::p is 4
NewNsTwo::r is 6
NewNsTwo::InNewNsTwo::tst20
*/

// анонімний простір імен
#include <iostream>
using namespace std;
// Простір імен без назви (anonymous namespace)
namespace{int p = 1; // unique::p
}
void funct1(){
++p; // unique::++p
}
namespace One{
// вкладений анонімний простір
namespace
{
int p;
// One::unique::p
int q = 3; // One::unique::q
}
}
// використання using-declaration
using namespace One;
void testing(){
// ++p;
// помилка: unique::p або One::unique::p?
// One::++p; // помилка , One::p - невизначене (undefined)
cout<<"++q = "<<++q<<endl;
}
int main(){
testing();
}

//++q = 4

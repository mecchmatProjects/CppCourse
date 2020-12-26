// namespace extension
#include <iostream>
using namespace std;
struct SampleOne
{ };
struct SampleTwo
{ };
// оригінальний простір імен namespace
namespace NsOne{
// оригінальна функція
void FunctOne(struct SampleOne){
cout<<"Processing the struct argument..."<<endl;
}
}
using NsOne::FunctOne; // використання using-declaration...
// розширення простору NsOne
namespace NsOne{// перевантажена (overloaded) функція...
void FunctOne(SampleTwo&)
{ cout<<"Processing the function argument..."<<endl; }
}
int main(){
SampleOne TestStruct;
SampleTwo TestClass;
FunctOne(TestStruct);
// Ця функція не запрацює, бо нема її перевантаженого екземпляру
// FunctOne(TestClass);
return 0;
}

//Processing the struct argument...



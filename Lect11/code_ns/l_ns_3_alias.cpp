// псевдоніми просторів імен namespace alias
#include <iostream>
using namespace std;
namespace TheFirstLongNamespaceSample{
float p = 23.44;
namespace TheNestedFirstLongNamespaceSample {int q = 100; }
}
// псевдонім: an alias namespace
namespace First = TheFirstLongNamespaceSample;
// псевдонім для вкладеного простору імен
namespace Second = TheFirstLongNamespaceSample::TheNestedFirstLongNamespaceSample;

int main(){
using namespace First; // використання першого псевдоніму
using namespace Second; // використання другого псевдоніму
cout<<"p = "<<p<<endl;
cout<<"q = "<<q<<endl;
}

/*
p = 23.44
q = 100

*/

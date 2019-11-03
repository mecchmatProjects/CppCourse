
#include <iostream>
#include <stdlib.h>

namespace SampleOne
{
	float p = 10.34;
}

namespace SampleTwo
{
	using namespace SampleOne;
   	float q = 77.12;
   	namespace InSampleTwo
   	{
   		float r = 34.725;
   	}
}

int main()
{
	//this directive gives you everything declared in SampleTwo
	using namespace SampleTwo;
	//this directive gives you only InSampleTwo
	using namespace SampleTwo::InSampleTwo;
	//local declaration, take precedence
	float p = 23.11; 

        using namespace std;
	cout<<"p = "<<p<<endl;
	cout<<"q = "<<q<<endl;
	cout<<"r = "<<r<<endl;
	
	return 0;
}


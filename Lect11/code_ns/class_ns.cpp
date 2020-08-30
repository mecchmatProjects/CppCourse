//Explicit access, namespace within a class
#include <iostream>
#include <stdlib.h>

using namespace std;
class One
{
	public:
	void funct1(char chs)
	{cout<<"character = "<<chs<<endl;}
};

class Two:public One
{
	public:
   	//The using directive is not allowed in class
   	//using namespace One;
	void funct1(char *str)
	{cout<<"String = "<<str<<endl;}
	
	//using declaration is OK in class
	using One::funct1;  //overload Two::funct1()
       
        void func2(){
          funct1('a');    
       }
};

int main()
{
   Two Sample;

 //Calling One::funct1()
   Sample.funct1('P');
   //Calling Two::funct1()
   Sample.funct1(const_cast<char*>("This is string"));
   
   return 0;
}


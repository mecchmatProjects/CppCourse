// dynamic_cast
#include <cstdio>
#include <iostream>
#include <exception>
using namespace std;

class Base { 
 
virtual void dummy() {}
  public:
  void use(){
	cout<<"Base"<<'\n';
  }
 };

class Derived: public Base { int a;

public:
 void use(){ 
   cout<<"Derive"<<'\n';
 }

 };


void print(const char* str){
	cout<<str;
}

void func(const int * arr){

}


int main () {

  const char * c = "sample text";
  print ( const_cast<char*> (c) );

  try{
   int * arr = new int[1000];
        func(const_cast<const int*>(arr));
       cout<<"Все гаразд"<<endl;
         delete[] arr;
    } catch(bad_alloc ex) {
        cout<<ex.what();
    }
    
  try {
    Base * pba = new Derived;
    Base * pbb = new Base;
    Derived * pd;
    pd = dynamic_cast<Derived*>(pba);
    if (pd==0) cout << "Null pointer on first type-cast.\n";
    pd->use(); 
    pd = dynamic_cast<Derived*>(pbb);
    if (pd==0) cout << "Null pointer on second type-cast.\n";
    pd->use();
    
    Base * pc = dynamic_cast<Base*>(pd) ;
    pc->use();
    Base * pe = dynamic_cast<Base*>(pba);
    pe->use();

  } catch (exception& e) {cout << "Exception: " << e.what();}


  return 0;
}

/*
sample textВсе гаразд
Derive
Null pointer on second type-cast.
Derive
Base
Base
*/

#include <iostream>
using namespace std;




int main(){

  int x = 45;
  int y =0;
  int z =0;
  try{
       z = x/y;

  }
  catch(...){
     cout<<"div By zero";
  }

}


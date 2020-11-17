#include <iostream>

template <class T, unsigned N=100> 
class Mystack {

    T a[N];
    unsigned num;

   public:
    Mystack(){ num=0; }

    T top(){ 
         return a[num];
    }  
    
    bool push(T b){ 

         if (num+1>=N) return false;
         a[num++]=b;
	return true;
    }  


    T pop(){ 
         if (num==0) return 0; //exception         
	return a[--num];
    }  

   void print(){
   for (int i=0;i<num;++i){
       std::cout<<a[i]<<",";
       std::cout<<std::endl;
   }

  }


};

int main(){

   Mystack<int> s1;
   Mystack<std::string> s2;
   
   s1.push(1);s1.push(2);
   s1.print();


   s2.push("aaa");s2.push("bbbb");
   s2.print();


}



#include <iostream> 
class A { 
private: 
    int a; 
public: 
    A() { a=0; } 
    friend class B;     // Friend Class 
}; 
  
class B { 
private: 
    int b; 
public: 
    void showA(A& x) { 
        // Since B is friend of A, it can access 
        // private members of A 
        std::cout << "A::a=" << x.a; 
    } 
}; 
  
  
class B1; 
  
class A1 
{ 
public: 
    void showB(B1& ); 
}; 
  
class B1 
{ 
private: 
    int b; 
public: 
    B1()  {  b = 0; } 
    friend void A1::showB(B1& x); // Friend function 
}; 
  
void A1::showB(B1 &x) 
{ 
    // Since show() is friend of B, it can 
    // access private members of B 
    std::cout << "B::b = " << x.b; 
} 
  
  
class A2 
{ 
    int a; 
public: 
    A2() {a = 0;} 
    friend void showA(A2&); // global friend function 
}; 
  
void showA(A2& x) { 
    // Since showA() is a friend, it can access 
    // private members of A 
    std::cout << "A::a=" << x.a; 
} 
  

  
int main() { 
   A a; 
   B b; 
   b.showA(a); 
   
   A1 a1; 
   B1 x1; 
   a1.showB(x); 
   
   A2 a2; 
   showA(a2);
   
   return 0; 
} 

/*
Output:

A::a=0
*/
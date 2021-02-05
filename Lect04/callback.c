#include <stdlib.h>
#include <stdio.h>

//http://www.zentut.com/c-tutorial/c-dynamic-memory-allocation/

struct container
{
  struct container (* call)(int);
};

struct container look_I_return_myself(int p)
{
  struct container result;

  printf("Here's some integer someone gave me, not sure what to do with it: %d.\n", p);

  result.call = look_I_return_myself;
  return result;
}

 typedef void (*callback_t1)(int);
 typedef callback_t1* (callback_t2)(int);
 typedef callback_t2* (callback_t3)(int);
 typedef callback_t3* (callback_t4)(int);
 
 callback_t4 X;
 callback_t3 *X(int i)
 {
    printf("(%d) ", i);
    return i>0 ? X(i-1) : X;
 }
 
 
   //  Example 3(d): The correct solution c++
  /*
  struct FuncPtr_;
  typedef FuncPtr_ (*FuncPtr)();

  struct FuncPtr_
  {
    FuncPtr_( FuncPtr pp ) : p( pp ) { }
    operator FuncPtr() { return p; }
    FuncPtr p;
  };

Now we can declare, define, and use f() naturally:

  FuncPtr_ f() { return f; } // natural return syntax

  int main()
  {
    FuncPtr p = f();  // natural usage syntax
    p();
  }
*/
 
 /* define function poiter type */
typedef int(*pfOperator)(int, int);
 
int plus(int,int);
int minus(int,int);
 
pfOperator getOperator(const char oper);
 
 
pfOperator getOperator(const char oper)
{
    switch(oper)
    {
    case '+':
        return +
        break;
    case '-':
        return −
        break;
    default:
        return NULL;
    }
}
 
int plus(int x,int y)
{
    return x + y;
}
int minus(int x,int y)
{
    return x - y;
}
 
 
int main(void)
{
  look_I_return_myself(3).call(4).call(5);
  
  printf("%p\n", X);
    printf("%p\n", X(2));
    printf("%p\n", X(3)(4));
    printf("%p\n", X(5)(6)(7));
    
    
     int x = 10,
        y = 20,
        z = 0;
 
    pfOperator func = NULL;
 
    func = getOperator('+');
    z = func(x,y);
    printf("%d\n",z);
 
    func = getOperator('-');
    z = func(x,y);
    printf("%d\n",z);
  
  return EXIT_SUCCESS;
}
// пример повторной генерации исключения
#include <iostream>
using namespace std;
void Xhandler()
{
try {
throw "hello"; // генерация char *
}
//error not const
catch (const char*) { // перехват char *
cout << "Caught char * inside Xhandler\n";
throw "aa"; // повторная генерация char * извне функции
}
}
int main()
{
 cout << "Start\n";
  try{
   Xhandler();
   }
  // error not const
  catch(const char *) {
   cout << "Caught char * inside main\n";
   }
  cout << "End";
return 0;
}



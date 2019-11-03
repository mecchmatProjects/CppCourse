#include <iostream>
int main()
{
  int* i;
  char *p = "This is a string";
  i = reinterpret_cast<int*> (p); // преобразование указателя к целому
  std::cout << *i;
  return 0;
}

#include <iostream>

using namespace std;

#define NUM_EMPLOYEES 4
class employee {
  public:
    employee () { cout << "Constructing employee\n"; }
    virtual void print() = 0;
};

class programmer : public employee {
  public:
    programmer() { cout << "Constructing programmer\n"; }
    void print () { cout << "Printing programmer object\n"; }
};

class salesperson : public employee {
  public:
   salesperson () { cout << "Constructing salesperson\n"; }
   void print() { cout << "Printing salesperson object\n"; }
};

class executive : public employee {
  public:
   executive () { cout << "Constructing executive\n"; }
   void print () { cout << "Printing executive object\n"; }
};

int main() {

  programmer prog1, prog2;
  executive ex;
  salesperson sp;
  // инициализация массива служащих
  employee *e[NUM_EMPLOYEES];
  e[0] = &prog1;
  e[1] = &sp;
  e[2] = &ex;
  e[3] = &prog2;
  // просмотр на предмет выяснения, кто является программистом
  for (int i = 0; i < NUM_EMPLOYEES; i++) {
   programmer *pp = dynamic_cast<programmer*>(e[i]);
   if(pp) {
     cout << "Is a programmer\n";
     pp->print();
   }
   else {
    cout << "Not a programmer\n";
   }
 }
}

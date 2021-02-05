#include <iostream>
#include <fstream>

using namespace std;
const char * filename = "testfile2.txt";

int main () {
// створення потоку, відкриття файлу для записів в текстовому режимі,
// запису данных и закрытия файла.
 ofstream ostr;
 ostr.open (filename);
 if (ostr) {
  for(int i = 0; i <16; i ++) {
    ostr << i * i << endl;
    if (ostr.bad ()) {
      cerr << "Невиправна помилка запису" << endl;
      return 1;
    }
  }
  ostr.close ();
 }
 else{
    cerr<< "Вихідний файл відкриває помилку"<< filename <<"\t";
   return 1;
 }
// відкриття файлу (в конструкторі) для чтения в текстовому режимі,
// чтение данных, форматированный вывод на консоль, закриття файлу.
 int data;
 int counter = 0;
 ifstream istr (filename);
 if (istr) {
   while (! (istr >> data) .eof ()) {
      if (istr.bad ()) {
          cerr << "Невиправна помилка читання" << endl;
          return 2;
      }
      cout.width (8);
      cout << data;
      if (++ counter% 4 == 0) {
         cout << endl;
      }
   }
   istr.close ();
  }
  else{
    cerr << "Помилка відкриття вхідного файлу"<< filename <<"\t";
    return 2;
  }
  return 0;
}



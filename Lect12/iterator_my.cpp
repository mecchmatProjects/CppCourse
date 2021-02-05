
#include <iostream>
using namespace std;
#define MAXSIZE 100

template<class Type>class MyMasiv{
  Type mas[MAXSIZE];
  int size;
  public:
     class iterator{
          Type *current;
          public: 
            iterator() { current = 0; }
            void operator++() {
                   current++; 
            }
            void operator+=(int temp) {
                   current += temp; 
            }
            void operator-=(int temp) { 
                   current -= temp; 
            }
            void operator=(Type& temp) {
                 current = &temp; 
            }
            bool operator!=(Type& temp) {
                 return current != &temp; 
            }
            bool operator==(Type& temp) {
                 return current == &temp; 
            }

            Type operator *() { 
                return *current / 2; 
            }
           Type* operator ->() { 
              return current; } 
           };
    
      MyMasiv(){	
           size = 0;
       }

     void add(int temp){
          size++; 
         mas[size - 1] = temp;
     }
    void del(){ 
        size--; 
       mas[size + 1] = 0; 
    }
    void show(){
       cout << "Массив:\n";
       for (int i = 0;i < size;i++)
 	       cout << mas[i] << ' ';
	cout << endl;
     }
    Type& begin() { return mas[0]; }
    Type& end() { return mas[size]; }
};


int main(){
 MyMasiv<int> a;
for (int i = 0;i < 5;i++){
     a.add(i*2);
  }

MyMasiv<int>::iterator it;
for (it = a.begin();it!=a.end();++it){
    cout << *it << ' ';
    
}
}


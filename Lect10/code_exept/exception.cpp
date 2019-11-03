
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int delenie(int n1, int n2)
{
    if (n2 == 0) {
        throw 42;
    }
    return n1 / n2;
};



int file_processing(string full_path){
   fstream file(full_path.c_str(), ios::binary);
   if(file.is_open()) {
        int magic_number = 0;
        file.read((char *)&magic_number, sizeof(magic_number));
      
        if(magic_number!=42) throw magic_number;
        // some code 
    } else {
        throw runtime_error("Unable to open file `" + full_path + "`!");
    }

return 0;
}

struct MyException : public exception {
   
   int line; 
   MyException(int m){
        line = m; 
    } 
   const char * what () const throw () {
      return "C++ Exception";
   }
   int getLine(){
       return line;
  }  
};
 
int my_func() {
   try {
      throw MyException(2);
   } catch(MyException& e) {
      std::cout << "MyException caught" << std::endl;
      std::cout << e.what() << std::endl;
      std::cout << e.getLine() << std::endl;
   } catch(std::exception& e) {
      //Other errors
      std::cout << e.what() << std::endl;
   }
}


int main(int argc, char **argv)
{

    int A=25, B=5, C=0;
  
    //1 input & division by zero processing  
    try {
        std::cout<<"A "<<std::endl;
        std::cin>>A;
        std::cout<<"B "<<std::endl;
        std::cin>>B;

        if (B==0) throw "Error";
        C = A/B;
        cout<<"C=" <<C<<endl;
    } catch( const char* e) {
        std::cout<<e<<std::endl;
    } catch(...) {
        cout<<"A=" <<A<<"B=" <<B<<endl;
    }
    //2 memory bad_alloc processing
    int * arr;
    try {
        arr = new int[1000000000];
        cout<<"Все гаразд"<<endl;
         delete[] arr;
    } catch(bad_alloc ex) {
        cout<<ex.what();
    }
    
    // 3 out of range processing 
    //int x[9];
    vector<int> x(9);
    try {
        for(int i =0; i<10; ++i) {
            x[i]=i;
        }
        cout<<"Все гаразд"<<endl;
    } catch(out_of_range exception) {
        cout<<exception.what();
    } catch(...) {
        cout<<"невідома проблема";
    }

    int num1;
    int num2;
    cout << "Введить число num1: ";
    cin >> num1;
    cout << "Введить число num2: ";
    cin >> num2;
    try {
        cout << "num2: "<<num2;
        if (num2 == 0) {
            throw "Ділення на 0!!!!"; // генерується рядок

        }
        if(num2<0) throw 1;
        cout << "n=: "<<num1/num2;
    } catch (const char *str) { // рядок перехоплює catch-блок
        cout << str << endl;
    } catch(int a) { // перехоплюємо ціле число
        cout<<"num2<0"<< endl;
    } 

    //У цьому прикладі, если num2 дорівнює 0,кидати генерує рядок, а не число. Строка “падає” у try-catch-блок і виводиться на екран.
    //Щоб виняток спрацювало правильно, цю функцію треба викликати в блоці try..catch:

    try {
        cout << delenie(7, 0);
        cout << endl;
    } catch (int thr) {
        cout << "Помилка №" << thr << " Ділення на 0!!!" << endl;
    }

    try{
        file_processing("1.txt");
    }
    catch(runtime_error e){
        cout<<e.what()<< endl;;
    }
    catch(int a){
            cout<<"a="<<a<<endl;
    }
  
    my_func();
    
    return 0;
}

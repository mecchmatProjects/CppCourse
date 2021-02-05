#include <iostream>
#include <functional>

struct A {
    A(int num) : num_(num){}
    void printNumberLetter(char c) const {std::cout << "Number: " << num_  << " Letter: " << c << std::endl;}
    int num_;
};

void printLetter(char c){
    std::cout << c << std::endl;
}

struct B {
    void operator() () {std::cout << "B()" << std::endl;}
};


std::function<double(double)> derivative(const std::function<double(double)> &f, const double h){

  return [=](double x)->double { return (f(x+h)-f(x-h))/2/h; };

}


int main(){
    // визначаємо функтор через вказівник на функцію
    std::function<void(char)> f_print_Letter = printLetter;
    f_print_Letter('Q');

    // визначаємо функтор як лямбда-вираз
    std::function<void()> f_print_Hello = [] () {std::cout << "Hello world!" << std::endl;};
    f_print_Hello();

    // визначаємо функтор через звязувач 
    std::function<void()> f_print_Z = std::bind(printLetter, 'Z');
    f_print_Z();

    // визначаємо функтор як метод класу
    std::function<void(const A&, char)> f_printA = &A::printNumberLetter;
    A a(10);
    f_printA(a, 'A');

    // присвоєння функторів
    B b;
    std::function<void()> f_B = b;
    f_B();

    // рахуємо піхідну функції як функцію
    std::function<double(double)> fd = [](double x)->double{ return x*x; } ;
    std::cout<<derivative(fd,0.001)(2.0);

}

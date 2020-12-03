// шаблон класу, 
template <class T>
class MyNumber{
    public:
    // конструктор
    MyNumber(void) { }

    // метод, множення на 2
    void Mult2(T* t);

    // метод, возведення в квадрат
    T MySquare(T x);

    // метод, ділення двох чисел типу T, результат - тип T
    T DivNumbers(T x, T y);
};


// реализація методу множення на 2
template <class T> void MyNumber<T>::Mult2(T* t){
    *t = (*t)*2;
}

// реализація методу, возведння в квадрат
template <class T> T MyNumber<T>::MySquare(T number)
{
    return (T)(number*number);
}

// метод ділення
template <class T> T MyNumber<T>::DivNumbers(T t1, T t2){
    return (T)(t1/t2);
}

int main(){
MyNumber <int> mi; // обєкт mi класу для типу int
MyNumber <float> mf; // обєкт mf класу для типу float

int d = 8;
float x = 9.3f;

// множення на 2
mi.Mult2(&d); // d = 16
mf.Mult2(&x); // x = 18.6

// возведення в квадрат
int dd;
dd = mi.MySquare(9); // dd = 81 - ціле число

double z;
z = mf.MySquare(1.1); // z = 1.21000... - дійсне

// деленне чисел
long int t;
float f;

t = mi.DivNumbers(5, 2); // t = 2 - ділення цілих чисел
f = mf.DivNumbers(5, 2); // f = 2.5 - ділення дійсних чисел

}

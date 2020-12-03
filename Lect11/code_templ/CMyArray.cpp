// шаблон класса, получающего 2 параметра
template <class TT, int count, int num> class CMyArray
{
    private:
    int n; // число элементов массива
    TT A[10]; // массив элементов

    public:
    // конструктор класса без параметров
    CMyArray()
    {
        // число элементов берем из входного параметра count
        n = count;

        // заполнить массив произвольными значениями
        for (int i=0; i<n; i++)
            A[i] = (TT)(i*2);
    }

    // конструктор класса с 1 параметром
    CMyArray(int cnt)
    {
        if (cnt<=10) n = cnt;
        else n = 0;

        // заполнение массива произвольными значениями
        for (int i=0; i<n; i++)
            A[i] = (TT)(i*2);
    }

    // методы доступа
    int GetN(void) { return n; }

    void SetN(int n)
    {
        if (n<=10) this->n = n;
        else n=0;

        for (int i=0; i<n; i++)
            A[i] = (TT)(i*2);
    }

    // метод, возвращающий значение элемента массива с заданным индексом
    TT GetItem(int index) { return (TT)A[index]; }

    // методы, выполняющие операции над массивом A
    // возведение элементов массива в степень num
    void Power(void);

    // подсчет числа элементов, значения которых есть больше num
    int CalcNum(void);
};

// возведение значения элементов массива в степень num
template <class TT, int count, int num>
void CMyArray<TT, count, num>::Power(void)
{
    if (n<0) return;

    for (int i=0; i<n; i++)
        A[i] = System::Math::Pow(A[i], num);
}

// метод, определяющий число элементов массива,
// которые больше заданного числа num (num - входящий параметр)
template <class TT, int count, int num>
int CMyArray<TT, count, num>::CalcNum(void)
{
    int k = 0;

    // цикл подсчета
    for (int i=0; i<n; i++)
        if (A[i] > num)
            k++;
    return k;
}

int main(){

// использование шаблона класса CMyArray
// массив целых чисел, параметры: count=7, num=2
CMyArray <int, 7, 2> ai1;

// массив целых чисел, вызов конструктора с 1 параметром
CMyArray <int, 8, -3> ai2(6); // число элементов count = 6, num=-3

// массив вещественных чисел типа double, вызов конструктора без параметров
CMyArray <double, 4, 5> ad1;

// проверка
int n, t;
double x;

n = ai1.GetN(); // n = 7
n = ai2.GetN(); // n = 6
n = ad1.GetN(); // n = 4

// проверка массива
t = ai1.GetItem(3); // t = 6
t = ai2.GetItem(0); // t = 0
x = ad1.GetItem(2); // x = 4.0

// вызов методов обработки массива и проверка результата
ai1.Power(); // возведение элементов массива в степень num=2
t = ai1.GetItem(3); // t = 6^2 = 36

// подсчет числа элементов, которые больше чем -3
// всего в массиве класса ai2 6 элементов
t = ai2.CalcNum(); // t = 6

// работа с классом, реализующим тип double
x = ad1.GetItem(3); // x = 6.0
ad1.Power(); // возведение чисел массива x в степень num = 5
x = ad1.GetItem(3); // x = 6.0^5 = 7776


}

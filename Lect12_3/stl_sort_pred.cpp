
#include <iostream>
#include <algorithm>
#include <functional>
#include <random>
#include <ctime>
#include <array>
using namespace std;
using namespace placeholders;

struct Rnd {
    void operator() (int &ar) {
        static default_random_engine rnd(time(0));
        static uniform_int_distribution<unsigned> d(10, 30);
        ar = d(rnd);
    }
};

int main() {
    array<int, 20> num {};
    auto first = num.begin();
    auto last = num.end();
    for_each(first, last, Rnd());
    cout << "вихідний масив:\n";
    for (auto &ar : num)
        cout << ar << " ";
    // Сортування від найбільшого до найменшого
    //=====================================================
    cout << "\nУпорядкований масив:\n";
    sort(first, last, greater<int>());
    for (auto &ar : num)
        cout << ar << " ";
    //=====================================================
    // Підрахунок
  
    cout << "\nКількість усіх елементів, рівних 20:\n"
         << count_if(first, last, bind(equal_to<int>(), _1, 20));
    //=====================================================
    // Заміна за критерієм
    replace_if(first, last, bind(less<int>(), _1, 19), 10);
    cout << "\nЗамінені усі < 19 на 10:\n";
    for (auto &ar : num)
        cout << ar << " ";
    cout << endl;
    return 0;
}

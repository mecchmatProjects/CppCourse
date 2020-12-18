#include <forward_list>
#include <string>
#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::forward_list<T>& v) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

int main() 
{
    // c++11 initializer list syntax:
    std::forward_list<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
    std::cout << "words1: " << words1 << '\n';
 
    // words2 == words1
    std::forward_list<std::string> words2(words1.begin(), words1.end());
    std::cout << "words2: " << words2 << '\n';
 
    // words3 == words1
    std::forward_list<std::string> words3(words1);
    std::cout << "words3: " << words3 << '\n';
 
    // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
    std::forward_list<std::string> words4(5, "Mo");
    std::cout << "words4: " << words4 << '\n';

    std::forward_list<int> numbers = { 7, 8 };
    numbers.push_front(6);  // добавляем в начало число 6
    // numbers =  { 6, 7, 8 }
 
    numbers.emplace_front(-3);  // добавляем в начало число -3
    // numbers =  { -3, 6, 7, 8 }
 
    auto iter = numbers.begin();
    iter = numbers.emplace_after(iter, -2); // добавляем после итератора число -2
    // numbers =  { -3, -2, 6, 7, 8 }
 
    iter = numbers.insert_after(iter, -1);
    // numbers =  { -3, -2, -1, 6, 7, 8 }
 
    iter = numbers.insert_after(iter, 3, 0);    // добавляем три нуля
    // numbers =  { -3, -2, -1, 0, 0, 0, 6, 7, 8 }
 
    std::list<int> values = { 1, 2, 3 };
    iter = numbers.insert_after(iter, values.begin(), values.end()); // добавляем все элементы из values
    // numbers =  { -3, -2, -1, 0, 0, 0, 1, 2, 3, 6, 7, 8 }
 
    numbers.insert_after(iter, { 4, 5 }); // добавляем список { 4, 5 }
    // numbers =  { -3, -2, -1, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8 }
 
    std::cout << "numbers: " << numbers << '\n';
   
    numbers.resize(4);  // оставляем первые четыре элемента - numbers = { -3, -2, -1, 0}
     std::cout << "numbers: " << numbers << '\n';
    numbers.resize(6, 8);    // numbers = {-3, -2, -1, 0, 8, 8}
    std::cout << "numbers: " << numbers << '\n';

}
/*
Выход:

words1: [the, frogurt, is, also, cursed]
words2: [the, frogurt, is, also, cursed]
words3: [the, frogurt, is, also, cursed]
words4: [Mo, Mo, Mo, Mo, Mo] 
*/

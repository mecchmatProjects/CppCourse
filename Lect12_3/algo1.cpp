
#include <iostream>
#include <algorithm>
#include <string>
#include <array>

//#include <string_view>

struct Student{

  std::string name;
  int marks;
};

 
struct Season
{
  std::string name;
  double averageTemperature;
};
 
int i{};
static int j{};
 
int getValue()
{
  return 0;
}
 

int main(){

std::array<Student, 8> arr{
  { { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan имеет больше всего баллов (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
};
 
auto z = std::max_element(arr.begin(),arr.end(), [](Student s1, Student s2) -> bool { return s1.marks<s2.marks; }  );

std::cout<< z->name << "is the best\n";

std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 },
      { "Winter", 263.0 } }
  };
 
  /*
   * Используйте std::sort() здесь
   */

  std::sort(seasons.begin(),seasons.end(), [](Season s1, Season s2) -> bool { return s1.averageTemperature<s2.averageTemperature; });
 
  for (const auto& season : seasons)
  {
    std::cout << season.name << '\n';
  }
 
  int a=1;
  constexpr int b=2;
  static int c=3;
  static constexpr int d=4;
  const int e=5;
  const int f{ getValue() };
  static const int g{}; 
  static const int h{ getValue() }; 
 
  [](){
    // Попробуйте использовать переменные без их явного захвата
    //a; //can't use
    std::cout<<b;
    std::cout<<c;
    std::cout<<d;
    std::cout<<e;
    //f; // can't use
    std::cout<<g;
    std::cout<<h;
    std::cout<<i;
    std::cout<<j;
  }();


//[a,f](){ a++;};
auto l1 = [a]()mutable-> int { a++;a++; return a;};
auto l= [&a]()->int { a++;a++; return a;};
std::string favoriteFruit{ "grapes" };
 
  auto printFavoriteFruit{
    [=]() {
      std::cout << "I like " << favoriteFruit << '\n';
    }
  };
 
  favoriteFruit = "bananas with chocolate";
 
  printFavoriteFruit();
 int x= l1(); // a=1, x = 3
  std::cout<<a<<x;
 x+=l(); //a=3, x=6 
  std::cout<<a<<x;
}



/CPP program to illustrate pair STL 
#include <iostream> 
#include <utility> 
using namespace std; 
  
int main() 
{ 
    pair <int, char> PAIR1 ;  
    PAIR1.first = 100; 
    PAIR1.second = 'G' ; 
  
    cout << PAIR1.first << " " ; 
    cout << PAIR1.second << endl ; 

     pair <string,unsigned> PAIR2 ("Мехмат", 65); 
  
    cout << PAIR2.first << " " ; 
    cout << PAIR2.second << endl ; 
      
    pair <int, double> PAIR3 ; 
    pair <string, char> PAIR4 ; 
  
    cout << PAIR3.firs

t ;  //it is initialised to 0 
    cout << PAIR3.second ; //it is initialised to 0 


  
    cout << " "; 
  
    cout << PAIR4.first ;  //it prints nothing i.e NULL 
    cout << PAIR4.second ; //it prints nothing i.e NULL 

    pair <int, char> PAIR21 ; 
    pair <string, double> PAIR22 ("Студент", 4.23) ; 
    pair <string, double> PAIR23 ; 
  
    PAIR21.first = 100; 
    PAIR21.second = 'G' ; 
  
    PAIR23 = make_pair ("Мехмат кращій",4.56); 
  
    cout << PAIR21.first << " " ; 
    cout << PAIR21.second << endl ; 
  
    cout << PAIR22.first << " " ; 
    cout << PAIR22.second << endl ; 

    cout << PAIR23.first << " " ; 
    cout << PAIR23.second << endl ;


    pair<int, int>pair1 = make_pair(1, 12); 
    pair<int, int>pair2 = make_pair(9, 12); 
  
  
    cout << (pair1 == pair2) << endl; 
    cout << (pair1 != pair2) << endl; 
    cout << (pair1 >= pair2) << endl; 
    cout << (pair1 <= pair2) << endl; 
    cout << (pair1 > pair2) << endl; 
    cout << (pair1 < pair2) << endl; 

  
   
    pair<char, int>pair1 = make_pair('A', 1); 
    pair<char, int>pair2 = make_pair('B', 2); 
  
    cout << "Before swapping:\n " ; 
    cout << "Contents of pair1 = " << pair1.first << " " << pair1.second ; 
    cout << "Contents of pair2 = " << pair2.first << " " << pair2.second ; 
    pair1.swap(pair2);  // c++ 11
  
    cout << "\nAfter swapping:\n "; 
    cout << "Contents of pair1 = " << pair1.first << " " << pair1.second ; 
    cout << "Contents of pair2 = " << pair2.first << " " << pair2.second ;


}


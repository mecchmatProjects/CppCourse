#include <iostream> 
#include <map> 
#include <stdexcept>
  
using namespace std; 

template <typename K, typename V>
void printMap(const map<K,V> & dict, string name){
    // printing map gquiz1 
    typename map<K, V>::const_iterator itr; 
    cout << "The map " << name <<" is : \n"; 
    for (itr = dict.begin(); itr != dict.end(); ++itr) { 
        cout << " " << itr->first 
             << " " << itr->second << " "; 
    } 
    cout << endl; 
}
  
int main(){ 
    // empty map container 
    map<int, int> dict1; 
  
    // insert elements in random order 
    dict1.insert(pair<int, int>(1, 40)); 
    dict1.insert(pair<int, int>(3, 30)); 
    dict1.insert(pair<int, int>(2, 60)); 
    dict1.insert(pair<int, int>(5, 20)); 
    dict1.insert(pair<int, int>(4, 50)); 
    dict1.insert(make_pair(7, 50)); 
    dict1.insert(make_pair(6, 10)); 
    //dict1.insert(make_pair(6, 15)); // replace old value 

    printMap(dict1, "dict1");
  
    // assigning the elements from gquiz1 to gquiz2 
    map<int, int> dict2(dict1.begin(), dict1.end()); 

    // access and change value by key 
    dict2[6] = 20;
    dict2.at(7) = 30;
    try{    
     dict2.at(8) = 30;
    }
    catch(out_of_range & ex){
     cout<<"error Incorrect key"<<ex.what()<<endl;
    }

    printMap(dict2, "dict2");
  
    // remove all elements up to 
    // element with key=3 in dict2 
    cout << "dict2 after removal of"
            " elements less than key=3 : "; 
    dict2.erase(dict2.begin(), dict2.find(3)); 
    printMap(dict2, "dict2 erased: ");
      
    // remove all elements with key = 5 
    int num; 
    num = dict2.erase(5); 
    cout << "dict2.erase(5) : " << num << " removed \n"; 
 
    printMap(dict2, "dict2 erased 5");  
    // lower bound and upper bound for map gquiz1 key = 5 
    cout << "dict1.lower_bound(5) : "  << "KEY = "; 
    cout << dict1.lower_bound(5)->first << " "; 
    cout << "	ELEMENT = "<< dict1.lower_bound(5)->second << endl; 
} 


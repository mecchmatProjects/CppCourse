// mapl.cpp:  Програма зі словниками.
#include <iostream>
#include <string>
#include <cstring>
#include <map> 
#include <set>
#include <iterator> 

#include <typeinfo>
using namespace  std; 
// Функтор:
class  compare2{ 
   public:
   //bool operator()(const char *s, const char *t) const{
   bool operator()(string s, string t) const{
     return strcmp (s.c_str(), t.c_str()) <  0;
   } 
};

template <typename T, typename U>
ostream & printpair(ostream & out, pair<T,U> & p){
  out<<"("<<p.first<<","<<p.second<<"),";
  return out;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T,U>  &t) { 
    return os << t.first << " " << t.second;
}

template<typename K, typename V, class L>
ostream& operator<<(ostream& os,
                        const map<K,V,L> &m) {

    typename map<K,V,L>::const_iterator it = m.begin(); 
    while ( it!= m.end()){
        os << "{" << it->first << ": " << it->second << "}\n";
      it++;
    }
    return os;
}
    
template<typename K, typename V, class L>
ostream& operator<<(ostream& os,
                        const multimap<K,V,L> &m) {

    typename multimap<K,V,L>::const_iterator it = m.begin(); 
    while ( it!= m.end()){
        os << "{" << it->first << ": " << it->second << "}\n";
      it++;
    }
    return os;
}
template <class T, class U>
string value_type(map<T, U> const &m) {
    return typeid(U).name();
}

template <class T, class U>
string key_type(map<T, U> const &m) {
    return typeid(T).name();
}


int map1(){
    map<string, long, compare2> D; 
   D["Johnson"]   =  12345; 
   D["Smith"]     =  54321; 
   D["Shaw"]      =  99999; 
   D["Atherton"]  =  11111;

   //printpair(cout,*D.begin());
   cout<<*D.begin();
  cout<<D;
  //char GivenName [30] ;
  string GivenName;
  cout  <<  "Enter a name:  "; 
  //cin.get(GivenName,  30); 
  cin>>GivenName;
  if(D.find (GivenName) != D.end())
     cout << "The number is " << D[GivenName]; 
   else cout  <<  "Not  found.";
   cout  <<  endl; 
return  0;
}

typedef multimap<string, long, compare2> Mmtype;
int multimap1(){
   Mmtype D; 
  D.insert(Mmtype::value_type("Johnson",  12345));
  D.insert(Mmtype::value_type("Smith",  54321));
  D.insert(Mmtype::value_type("Johnson",  10000));
  //printMap(D);
   cout<<D;
   cout << "There are " << D.size() << " elements. \n";
  return  0;
}

int main(){
map1();
multimap1();

}


#include <iostream>
template<class Type>
Type _min(Type a, Type b) {
    if (a < b) {
        return a;
    }
    return b;
}

template<class Type>
Type* _min(Type* a, Type* b){
    if(*a < *b){
        return a;
    }
    return b;
}

template<>
std::string _min(std::string a, std::string b){
    if(a.size() < b.size()){ // compare by size
        return a;
    }
    return b;
}

int main(int argc, char** argv) {
    std::cout << _min(1, 2) << std::endl; // 1
    std::cout << _min(3.1, 1.2) << std::endl; // 1.2
    //std::cout << _min(5, 2.1) << std::endl; // oops!
    std::cout << _min<double>(5, 2.1) << std::endl; // 2.1

    // pointer version
    int A[] ={1,2,3};
    int B[] ={0,100, 200};
    std::cout <<"ptr"<< _min(A, B)<<",elem="<< *_min(A, B) << std::endl; //ptr0x7ffe27741be0,elem=0
    std::cout << _min("abc", "bca") << std::endl; //abc

    // specialization for strings
    std::string s1("Big");
    std::string s2("small");
    std::cout << _min(s1, s2) << std::endl; //Big 
  
    return 0;
}


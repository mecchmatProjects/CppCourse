#include <iostream>
#include <vector>
#include <stdexcept>
 
int main(){

    int mas[] = { 1, 2, 3, 4, 5};
    std::vector<int> numbers(mas,mas+5);
    try
    {
        int n = numbers.at(5); //oops...
        std::cout<<"n="<<n;
    }
    catch (std::out_of_range e)
    {
        std::cout << "Caught: Incorrect index 1" << std::endl;
    }
 
    std::vector<int> numbers2(mas,mas+5);
    try
    {
        int n = numbers2[5]; // ???
        std::cout<<"n="<<n; // n=0 or maybe n=502012792....
    }
    catch (std::out_of_range e)
    {
        std::cout << "Shouldnt caught: Incorrect index 2" << std::endl;
    }


    return 0;
}


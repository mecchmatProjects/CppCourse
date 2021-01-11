#include <iostream>
#include <algorithm>

class DividedByTwo{
    public:
        bool operator()(const int x) const        {
            return x % 2 == 0;
        }
};
 
int main(){
    const std::size_t N = 5;
    int A[N] = {3, 2, 5, 6, 8};
    std::cout << std::count_if(A, A + N, DividedByTwo());
}

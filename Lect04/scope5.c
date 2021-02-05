#include <stdio.h>
// Inline function in C

__inline static int bar(){
    return 2;
    }

// Driver code
int main()
{

    int ret;

    // inline function call
    // ret = foo();
    ret = bar();

    printf("Output is: %d\n", ret);

    return 0;
}




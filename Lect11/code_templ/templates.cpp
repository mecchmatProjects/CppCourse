#include "Array.h"
#include "Array.cpp" // It's bad - but it's only here and small criminal
 
// Here we can #include other files *.h and *.cpp with temaplates we need
 
template class Array<int>; // Create object of class Array<int>
template class Array<double>; // create object of Array<double>
 
// here we can instantiate all templaet classes we need

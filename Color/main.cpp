#include <iostream>

#include "test/tests.h"
#include "src/imgcol.h"

using namespace std;

void runTests();

int main()
{

}

void runTests(){
    try {
        cout << "--RGBA TEST--" << endl;
        testRGBA();
        cout << "--CMYK TEST--" << endl;
        testCMYK();
        cout << "--HSB TEST--" << endl;
        testHSB();
        cout << "--CONVERT TEST--" << endl;
        testConvert();
        cout << "--IMAGE LOAD AND SAVE TEST--" << endl;
        testImageLoadSave();
        cout << "--IMAGE FILTER TEST--" << endl;
        testImageMask();
        cout << "--TESTS PASSED--" << endl;
    } catch (...) {
        cout << "--TESTS NOT PASSED--" << endl;
    }

}

#ifndef TESTS_H
#define TESTS_H

#include "src/colorrgba.h"
#include "src/colorcmyk.h"
#include "src/colorhsb.h"
#include "src/image.h"
#include "src/imageloader.h"
#include "src/imagesaver.h"
#include <iostream>

using namespace std;
//RGBA test
void testRGBA(){
    //tests print, convert to int and float
    ColorRGBA c1(255,128,0,0);
    cout << c1 << endl;
    cout << int(c1) << endl;
    cout << float(c1) << endl;

    ColorRGBA c2(0,128,300);
    cout << c2 << endl;
    cout << int(c2) << endl;
    cout << float(c2) << endl;
    //operator tests
    ColorRGBA c3 = c1 + c2;
    cout << c3 << endl;
    c3 = c1 & c2;
    cout << c3 << endl;
    c3 = c1 | c2;
    cout << c3 << endl;
    c3 = c1 ^ c2;
    cout << c3 << endl;
    //test creation from int
    ColorRGBA c4(static_cast<int>(c1));
    cout << c4;
    cout << int(c4);
}

void testCMYK(){
    ColorCMYK c1(0.5f,0.3f,1.0f,0.4f);
    cout << c1 << endl;
    cout << int(c1) << endl;
    cout << float(c1) << endl;

    ColorCMYK c2(0.0f,1.6f,0.4f,0.2f);
    cout << c2 << endl;
    cout << int(c2) << endl;
    cout << float(c2) << endl;

    //operator tests
    ColorCMYK c3 = c1 + c2;
    cout << c3 << endl;
    c3 = c1 & c2;
    cout << c3 << endl;
    c3 = c1 | c2;
    cout << c3 << endl;
    c3 = c1 ^ c2;
    cout << c3 << endl;
}

void testHSB(){
    ColorHSB c1(167,0.3f,1.0f);
    cout << c1 << endl;
    cout << int(c1) << endl;
    cout << float(c1) << endl;

    ColorHSB c2(400,1.6f,0.4f);
    cout << c2 << endl;
    cout << int(c2) << endl;
    cout << float(c2) << endl;

    //operator tests
    ColorHSB c3 = c1 + c2;
    cout << c3 << endl;
    c3 = c1 & c2;
    cout << c3 << endl;
    c3 = c1 | c2;
    cout << c3 << endl;
    c3 = c1 ^ c2;
    cout << c3 << endl;
}

void testConvert(){
    ColorRGBA c_rgb1(45,45,45);
    ColorCMYK c_cmyk1 = c_rgb1.toCMYK();;
    ColorHSB c_hsb1 = c_rgb1.toHSB();
    ColorRGBA c_rgb2 = c_cmyk1.toRGBA();
    ColorRGBA c_rgb3 = c_hsb1.toRGBA();
    ColorCMYK c_cmyk2 = c_hsb1.toCMYK();
    ColorHSB c_hsb2 = c_cmyk1.toHSB();

    cout << c_rgb1;
    cout << c_cmyk1;
    cout << c_hsb1;
    cout << c_rgb2;
    cout << c_rgb3;
    cout << c_cmyk2;
    cout << c_hsb2;
}

void testImageLoadSave(){
    Image img1(5,6);
    cout << "Before Save" << endl;
    img1.setPixel(21343,3,4);
    img1.show();
    img1.save("..//Color//test//img.txt");
    cout << "After Load" << endl;
    Image img2 = Image::load("..//Color//test//img.txt");
    img2.show();
}

void testImageMask(){
    Image img = Image::load("..//Color//test//img2.txt");
    cout << "IMAGE" << endl;
    img.show();
    Image mask = Image::load("..//Color//test//mask2.txt");
    cout << "MASK" << endl;
    mask.show();

    Image result = img * mask;
    cout << "Filtered new image" << endl;
    result.show();

    img.applyFilter(mask);
    cout << "Filtered first image" << endl;
    img.show();
}

#endif // TESTS_H

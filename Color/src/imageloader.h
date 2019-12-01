#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <string>
#include <iostream>
#include <fstream>
#include "image.h"

using namespace std;

//class for Save image. Using RAII for safe open and close
class ImageLoader
{
    ifstream in;
public:
    //open file in constructor
    explicit ImageLoader(const string& filename);
    //close file in destructor
    ~ImageLoader();
    //save function
    Image load();
    //restrict copy and move semantic
    ImageLoader(const ImageLoader&) = delete;
    ImageLoader(ImageLoader&&) = delete;
    ImageLoader& operator=(const ImageLoader&) = delete;
    ImageLoader& operator=(ImageLoader&&) = delete;
};

#endif // IMAGELOADER_H

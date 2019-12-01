#include "image.h"

#include <stdexcept>
#include <iostream>
#include "imageloader.h"
#include "imagesaver.h"

unsigned Image::getM() const
{
    return _m;
}

unsigned Image::getN() const
{
    return _n;
}

void Image::applyFilter(const Image &mask)
{
    if(_m != mask.getM() || _n != mask.getN()){
        throw invalid_argument("Image and mask size does not match");
    }

    for(unsigned i = 0; i < _m; i++){
        for(unsigned j = 0; j < _n; j++){
            _data[i][j] -= mask.getPixel(i,j);
            _data[i][j] *= _data[i][j];
        }
    }
}

void Image::show() const
{
    for (unsigned int i = 0; i < _m; i++) {
        for(unsigned int j = 0; j < _n; j++){
            cout << _data[i][j] << ' ';
        }
        cout << endl;
    }
}

void Image::save(const string &filename) const
{
    try {
        ImageSaver saver(filename);
        saver.save(*this);
    } catch (...) {
        cout << "Cannot save image" << endl;
    }
}

Image Image::load(const string &filename)
{
    Image img(0,0);
    try {
        ImageLoader loader(filename);
        img =  loader.load();
    } catch (...) {
        cout << "Cannot load image" << endl;
    }
    return img;
}

Image operator*(const Image &image, const Image &mask)
{
    //copy image
    Image new_image = image;
    //apply mask
    new_image.applyFilter(mask);
    return new_image;
}

Image::Image(unsigned m, unsigned n)
    :_m(m),_n(n)
{
    for(unsigned i = 0; i < _m; i++){
        _data.push_back(vector<int>(_n,0));
    }
}

int Image::getPixel(unsigned i, unsigned j) const
{
    if(i >= _m || j >= _n){
        throw invalid_argument("Out of image range");
    }

    return _data[i][j];
}

void Image::setPixel(int clr, unsigned i, unsigned j)
{
    if(i >= _m || j >= _n){
        throw invalid_argument("Out of image range");
    }

    _data[i][j] = clr;
}

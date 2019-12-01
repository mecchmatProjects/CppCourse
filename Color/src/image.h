#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

using namespace std;

//Image and Mask have same structure -> no reason to make different classes
class Image
{
    //image m rows and n columns
    unsigned _m;
    unsigned _n;
    //image data
    vector<vector<int>> _data;
public:
    Image(unsigned m, unsigned n);
    //getters and setters
    int getPixel(unsigned i, unsigned j) const;
    void setPixel(int clr, unsigned i, unsigned j);
    unsigned getM() const;
    unsigned getN() const;
    //apply mask to image (change current image)
    void applyFilter(const Image &mask);
    //apply mask to image as operator and return new filtered image
    friend Image operator*(const Image &image,const Image &mask);
    //show image
    void show() const;
    //save func
    void save(const string& filename) const;
    //static load func
    static Image load(const string& filename);
};

#endif // IMAGE_H

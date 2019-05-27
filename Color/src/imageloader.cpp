#include "imageloader.h"

#include <exception>

ImageLoader::ImageLoader(const string &filename)
    :in(ifstream(filename))
{
    if(!in.is_open()){
        throw ios_base::failure("Cannot open " + filename);
    }
}

ImageLoader::~ImageLoader()
{
    if(in.is_open())
        in.close();
}

Image ImageLoader::load()
{
    //read size of image from file
    unsigned m,n;
    in >> m >> n;
    //create image
    Image img(m,n);
    //load data from file
    for(unsigned i = 0; i < m; i++) {
        for(unsigned j = 0; j < n; j++){
            int pixel;
            in >> pixel;
            img.setPixel(pixel,i,j);
        }
    }
    return img;
}

#include "imagesaver.h"

#include <exception>

ImageSaver::ImageSaver(const string &filename)
    :out(ofstream(filename))
{
    if(!out.is_open()){
        throw ios_base::failure("Cannot open " + filename);
    }
}

ImageSaver::~ImageSaver()
{
    if(out.is_open())
        out.close();
}

void ImageSaver::save(const Image &image)
{
    //first line of file is size of image
    out << image.getM() << " " << image.getN() << std::endl;
    //write data in file
    for(unsigned i = 0; i < image.getM(); i++) {
        for(unsigned j = 0; j < image.getN(); j++){
            out << image.getPixel(i,j) << " ";
        }
        out << std::endl;
    }
}

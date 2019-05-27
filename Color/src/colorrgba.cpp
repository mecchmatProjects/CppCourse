#include "colorrgba.h"
#include "colorcmyk.h"
#include "colorhsb.h"

#include "utility.h"

unsigned short ColorRGBA::r() const
{
    return _r;
}

void ColorRGBA::setR(CLR r)
{
    _r = r;
}

unsigned short ColorRGBA::g() const
{
    return _g;
}

void ColorRGBA::setG(CLR g)
{
    _g = g;
}

unsigned short ColorRGBA::b() const
{
    return _b;
}

void ColorRGBA::setB(CLR b)
{
    _b = b;
}

unsigned short ColorRGBA::a() const
{
    return _a;
}

void ColorRGBA::setA(CLR a)
{
    _a = a;
}

ColorRGBA ColorRGBA::toRGBA()
{
    //convert from RGBA to RGBA - return copy of object
    return *this;
}

ColorCMYK ColorRGBA::toCMYK()
{
    //convert to RGB first, opacity will lose
    float r = (_r * _a/255.0f)/255;
    float g = (_g * _a/255.0f)/255;
    float b = (_b * _a/255.0f)/255;
    //calculating black color
    float k = r;
    k = f_max(r,g,b);
    k = 1 - k;
    //check if it is true black
    if(k == 1.0f){
        return ColorCMYK{0,0,0,1};
    }
    //convert to CMYK
    float c = (1-r-k)/(1-k);
    float m = (1-g-k)/(1-k);
    float y = (1-b-k)/(1-k);

    return ColorCMYK(c,m,y,k);
}

ColorHSB ColorRGBA::toHSB()
{
    //convert to RGB first, opacity will lose
    float r = (_r * _a/255.0f)/255;
    float g = (_g * _a/255.0f)/255;
    float b = (_b * _a/255.0f)/255;
    //find max and min
    float max_c = f_max(r,g,b), min_c = f_min(r,g,b);
    float delta = max_c - min_c;
    //calc bright
    float bri = max_c;
    //calc hue
    float hue = 0;

    if(f_eq(delta,0.0f)){
        return ColorHSB(0,0,bri);
    }
    else if (f_eq(max_c,r)) {
        hue = (g-b)/delta;
    }
    else if (f_eq(max_c,g)) {
        hue = 2.0f + (b-r)/delta;
    }
    else{
        hue = 4.0f + (r-g)/delta;
    }

    hue *= 60;
    if(hue < 0.0f)
        hue += 360;

    //calc saturation
    float sat = f_eq(delta,0.0f) ? 0 : (delta/max_c);

    return ColorHSB(static_cast<unsigned short>(hue),sat,bri);
}

ColorRGBA operator^(ColorRGBA &clr1, ColorRGBA &clr2)
{
    return ColorRGBA(int(clr1) ^ int(clr2));
}

ColorRGBA operator|(ColorRGBA &clr1, ColorRGBA &clr2)
{
    return ColorRGBA(int(clr1) | int(clr2));
}

ColorRGBA operator&(ColorRGBA &clr1, ColorRGBA &clr2)
{
    return ColorRGBA(int(clr1) & int(clr2));
}

ColorRGBA operator+(ColorRGBA &clr1, ColorRGBA &clr2)
{
    return ColorRGBA((clr1._r + clr2._r)/2,(clr1._g + clr2._g)/2,(clr1._b + clr2._b)/2,(clr1._a + clr2._a)/2);
}

istream& operator>>(istream &in, ColorRGBA &clr){
    unsigned short tr,tg,tb,ta;
    //read velues
    in >> tr;
    in >> tg;
    in >> tb;
    in >> ta;
    //check values
    if(!(tr > 255 || tg > 255 || tb > 255 || ta > 255)){
        //change clr if values correct
        clr._r = tr;
        clr._b = tb;
        clr._g = tg;
        clr._a = ta;
    }
    return in;
}

ColorRGBA::operator float()
{
    //convert to float color represnted as int
    return static_cast<float>(int(*this));
}

ColorRGBA::operator int()
{
    //conver to int
    return 0 | (_r << 16) | (_g << 8) | (_b) | (_a << 24);
}

ostream &ColorRGBA::print(ostream &out)
{
    out << _r << " " << _g << " " << _b << " " << _a << std::endl;
    return out;
}

ColorRGBA::ColorRGBA(CLR r, CLR g, CLR b, CLR a)
    :_r(r > 255 ? 255 : r),
      _g(g > 255 ? 255 : g),
      _b(b > 255 ? 255 : b),
      _a(a > 255 ? 255 : a)
{

}

ColorRGBA::ColorRGBA(int val)
    :_r((val >> 16) & 255),
      _g((val >> 8) & 255),
      _b(val & 255),
      _a((val >> 24) & 255)
{

}

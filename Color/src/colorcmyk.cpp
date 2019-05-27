#include "colorcmyk.h"
#include "colorhsb.h"
#include "colorrgba.h"


float ColorCMYK::c() const
{
    return _c;
}

void ColorCMYK::setC(float c)
{
    _c = c;
}

float ColorCMYK::m() const
{
    return _m;
}

void ColorCMYK::setM(char m)
{
    _m = m;
}

float ColorCMYK::y() const
{
    return _y;
}

void ColorCMYK::setY(float y)
{
    _y = y;
}

float ColorCMYK::k() const
{
    return _k;
}

void ColorCMYK::setK(float k)
{
    _k = k;
}

ColorRGBA ColorCMYK::toRGBA()
{
    char r = char(255 * (1-_c) * (1-_k));
    char g = char(255 * (1-_m) * (1-_k));
    char b = char(255 * (1-_y) * (1-_k));
    return ColorRGBA(r,g,b);
}

ColorCMYK ColorCMYK::toCMYK()
{
    return *this;
}

ColorHSB ColorCMYK::toHSB()
{
    return this->toRGBA().toHSB();
}

ColorCMYK operator+(ColorCMYK &clr1, ColorCMYK &clr2)
{
    return ColorCMYK((clr1._c + clr2._c)/2,(clr1._m + clr2._m)/2,(clr1._y + clr2._y)/2,(clr1._k + clr2._k)/2);
}

ColorCMYK operator&(ColorCMYK &clr1, ColorCMYK &clr2)
{
    return ColorRGBA(int(clr1) & int(clr2)).toCMYK();
}

ColorCMYK operator|(ColorCMYK &clr1, ColorCMYK &clr2)
{
    return ColorRGBA(int(clr1) | int(clr2)).toCMYK();
}

ColorCMYK operator^(ColorCMYK &clr1, ColorCMYK &clr2)
{
    return ColorRGBA(int(clr1) ^ int(clr2)).toCMYK();
}

istream &operator>>(istream &in, ColorCMYK &clr)
{
    float tc,tm,ty,tk;
    //read velues
    in >> tc;
    in >> tm;
    in >> ty;
    in >> tk;
    //check values
    if(!(tc > 1.0f || tm > 1.0f || ty > 1.0f || tk > 1.0f || tc < 0.0f || tm < 0.0f || ty < 0.0f || tk < 0.0f)){
        //change clr if values correct
        clr._c = tc;
        clr._m = tm;
        clr._y = ty;
        clr._k = tk;
    }
    return in;
}

ColorCMYK::operator float()
{
    //convert to float color represnted as int
    return static_cast<float>(int(*this));
}

ColorCMYK::operator int()
{
    return int(this->toRGBA());
}

ostream &ColorCMYK::print(ostream &out)
{
    out << _c << " " << _m << " " << _y << " " << _k << std::endl;
    return out;
}

ColorCMYK::ColorCMYK(float c, float m, float y, float k)
    :_c(c > 1 ? 1 : c),
      _m(m > 1 ? 1 : m),
      _y(y > 1 ? 1 : y),
      _k(k > 1 ? 1 : k)
{

}

#include "colorhsb.h"
#include "colorrgba.h"
#include "colorcmyk.h"

#include <math.h>
#include "utility.h"

unsigned short ColorHSB::h() const
{
    return _h;
}

void ColorHSB::setH(unsigned short h)
{
    _h = h;
}

float ColorHSB::s() const
{
    return _s;
}

void ColorHSB::setS(float s)
{
    _s = s;
}

float ColorHSB::b() const
{
    return _b;
}

void ColorHSB::setB(float b)
{
    _b = b;
}

ColorRGBA ColorHSB::toRGBA()
{
    float c = _b * _s;
    float hh = _h/60.0f;
    hh = fmodf(hh,2) - 1.0f;
    float x = c * (1.0f - fabsf(hh));
    float m = _b - c;
    float r = 0, g = 0, b = 0;

    if(_h < 60){
        r = c;
        g = x;
    }
    else if (_h >= 60 && _h < 120) {
        r = x;
        g = c;
    }
    else if (_h >= 120 && _h < 180) {
        g = c;
        b = x;
    }
    else if (_h >= 180 && _h < 240) {
        g = x;
        b = c;
    }
    else if (_h >= 240 && _h < 300) {
        r = x;
        b = c;
    }
    else{
        r = c;
        b = x;
    }

    unsigned short R = static_cast<unsigned short>((r+m)*255.0f);
    unsigned short G = static_cast<unsigned short>((g+m)*255.0f);
    unsigned short B = static_cast<unsigned short>((b+m)*255.0f);

    return ColorRGBA(R,G,B);
}

ColorCMYK ColorHSB::toCMYK()
{
    return this->toRGBA().toCMYK();
}

ColorHSB ColorHSB::toHSB()
{
    return *this;
}

ColorHSB operator+(ColorHSB &clr1, ColorHSB &clr2)
{
    return ColorHSB((clr1._h + clr2._h)/2,(clr1._s + clr2._s)/2,(clr1._b + clr2._b)/2);
}

ColorHSB operator&(ColorHSB &clr1, ColorHSB &clr2)
{
    return ColorRGBA(int(clr1) & int(clr2)).toHSB();
}

ColorHSB operator|(ColorHSB &clr1, ColorHSB &clr2)
{
    return ColorRGBA(int(clr1) | int(clr2)).toHSB();
}

ColorHSB operator^(ColorHSB &clr1, ColorHSB &clr2)
{
    return ColorRGBA(int(clr1) ^ int(clr2)).toHSB();
}

istream & operator>>(istream &in, ColorHSB &clr)
{
    unsigned short th;
    float ts,tb;
    //read values
    in >> th;
    in >> ts;
    in >> tb;
    //check values
    if(!(th > 360 || ts < 0.0f || ts > 1.0f || tb < 0.0f || tb > 1.0f)){
        //change clr if values correct
        clr._h = th;
        clr._s = ts;
        clr._b = tb;
    }
    return in;
}

ColorHSB::operator float()
{
    //convert to float color represnted as int
    return static_cast<float>(int(*this));
}

ColorHSB::operator int()
{
    return int(this->toRGBA());
}

ostream &ColorHSB::print(ostream &out)
{
    out  << _h << " " << _s << " " << _b << std::endl;
    return out;
}

ColorHSB::ColorHSB(unsigned short h, float s, float b)
    :_h(h > 360 ? 360 : h),
      _s(s > 1 ? 1 : s),
      _b(b > 1 ? 1 : b)
{

}


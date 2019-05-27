#ifndef COLORHSB_H
#define COLORHSB_H

#include "color.h"

class ColorHSB: public Color
{
    unsigned short _h;
    float _s;
    float _b;
protected:
    ostream &print(ostream& out);
public:
    /*
     * Constructor
     * default values give black color
     */
    ColorHSB(unsigned short h, float s, float b);
    //getters and setters
    unsigned short h() const;
    void setH(unsigned short h);
    float s() const;
    void setS(float s);
    float b() const;
    void setB(float b);
    //implementation of virtual methods
    ColorRGBA toRGBA();
    ColorCMYK toCMYK();
    ColorHSB toHSB();
    //convert to int and float methods
    operator int();
    operator float();
    //overload of input operator >>
    friend istream& operator>> (istream& in, ColorHSB& clr);
    /*
     * overload operations
     * + is for combine
     * & | ^ bit opeartions
     */
    friend ColorHSB operator+(ColorHSB& clr1, ColorHSB& clr2);
    friend ColorHSB operator&(ColorHSB& clr1, ColorHSB& clr2);
    friend ColorHSB operator|(ColorHSB& clr1, ColorHSB& clr2);
    friend ColorHSB operator^(ColorHSB& clr1, ColorHSB& clr2);
};

#endif // COLORHSB_H

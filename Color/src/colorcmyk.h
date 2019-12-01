#ifndef COLORCMYK_H
#define COLORCMYK_H

#include "color.h"

class ColorCMYK : public Color
{
    float _c; //cyan
    float _m; //margenta
    float _y; //yellow
    float _k; //black
protected:
    ostream &print(ostream& out);
public:
    /*
     * Constructor
     */
    ColorCMYK(float c, float m, float y, float k);
    //getters and setters
    float c() const;
    void setC(float c);
    float m() const;
    void setM(char m);
    float y() const;
    void setY(float y);
    float k() const;
    void setK(float k);
    //implementation of virtual methods
    ColorRGBA toRGBA();
    ColorCMYK toCMYK();
    ColorHSB toHSB();
    //convert to int and float methods
    operator int();
    operator float();
    //overload of input operator >>
    friend istream& operator>> (istream& in, ColorCMYK& clr);
    /*
     * overload operations
     * + is for combine
     * & | ^ bit opeartions
     */
    friend ColorCMYK operator+(ColorCMYK& clr1, ColorCMYK& clr2);
    friend ColorCMYK operator&(ColorCMYK& clr1, ColorCMYK& clr2);
    friend ColorCMYK operator|(ColorCMYK& clr1, ColorCMYK& clr2);
    friend ColorCMYK operator^(ColorCMYK& clr1, ColorCMYK& clr2);
};

#endif // COLORCMYK_H

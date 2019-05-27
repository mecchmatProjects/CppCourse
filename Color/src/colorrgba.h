#ifndef COLORRGBA_H
#define COLORRGBA_H

#include <iostream>

#include "color.h"

class ColorRGBA : public Color
{
    typedef unsigned short CLR;
    CLR _r; //red
    CLR _g; //green
    CLR _b; //blue
    CLR _a; //opacity
protected:
    ostream &print(ostream& out);
public:
    /*
     * Constructor
     */
    ColorRGBA(CLR r, CLR g, CLR b, CLR a = 255);
    /*
     * overloaded conctructor
     * convert int to RGBA
     * because it can be done directly
     */
    ColorRGBA(int val = 0);
    //getters and setters
    CLR r() const;
    void setR(CLR r);
    CLR g() const;
    void setG(CLR g);
    CLR b() const;
    void setB(CLR b);
    CLR a() const;
    void setA(CLR a);
    //implementation of virtual methods
    ColorRGBA toRGBA();
    ColorCMYK toCMYK();
    ColorHSB toHSB();
    //convert to int and float methods
    operator int();
    operator float();
    //overload of input operator >>
    friend istream& operator>> (istream& in, ColorRGBA& clr);
    /*
     * overload operations
     * + is for combine
     * & | ^ bit opeartions
     */
    friend ColorRGBA operator+(ColorRGBA& clr1, ColorRGBA& clr2);
    friend ColorRGBA operator&(ColorRGBA& clr1, ColorRGBA& clr2);
    friend ColorRGBA operator|(ColorRGBA& clr1, ColorRGBA& clr2);
    friend ColorRGBA operator^(ColorRGBA& clr1, ColorRGBA& clr2);
};

#endif // COLORRGBA_H

#pragma once
//#include "stdafx.h"
#include <iostream>
#include <math.h>
class FourSrComplex
{
public:
	FourSrComplex();
	~FourSrComplex();
	void showX();
private:
	void inputCoef();
	double a, b, c, d, e, f;
	double alpha, betta, gamma;
	void ComputeABG();
	void solve();
};


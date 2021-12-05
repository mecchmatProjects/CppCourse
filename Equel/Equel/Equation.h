#pragma once
#include <iostream>
class Equation
{
public:
	virtual void showX() = 0;
	int getN() { return n; }

protected:
	int n;
	double *x;

	virtual void solve() = 0;
	virtual void computeN() = 0;
	virtual void inputCoef() = 0;
};

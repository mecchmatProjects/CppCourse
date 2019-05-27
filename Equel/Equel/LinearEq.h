#pragma once
#include "Equation.h"
#include <iostream>

class LinearEq : public Equation
{
public:
	LinearEq();
	LinearEq(const double, const double);
	~LinearEq();

	void showX() override;

	double getX();

private:
	double a;
	double b;
	bool isSolved = false;

	void solve() override;
	void computeN() override;
	void inputCoef() override;

};


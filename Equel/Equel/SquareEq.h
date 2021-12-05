#pragma once
#include "Equation.h"
#include "LinearEq.h"
#include <iostream>

class SquareEq : public Equation
{
public:
	SquareEq();
	SquareEq(double const, double const, double const);
	~SquareEq();

	void showX() override;

	int GetN();

	double* GetX();

private:
	double a;
	double b;
	double c;
	double D;

	void solve() override;
	void computeN() override;
	void inputCoef() override;
	double computeD();
};


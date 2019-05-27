#pragma once
#include "Equation.h"
#include "LinearEq.h"
#include "SquareEq.h"
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

class CubEq : public Equation
{
public:
	CubEq();
	CubEq(double const, double const, double const, double const);
	~CubEq();

	void showX() override;

	double* GetX();

private:
	double a, b, c, d, S, Q, R;
	void solve() override;
	void computeN() override;
	void inputCoef() override;
	void compSQR();
	void Zmist();

};
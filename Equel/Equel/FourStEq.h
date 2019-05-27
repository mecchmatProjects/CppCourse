#pragma once
#include "Equation.h"
#include "CubEq.h"

class FourStEq :
	public Equation
{
public:
	FourStEq();
	FourStEq(double const, double const, double const, double const, double const);
	~FourStEq();

	void showX() override;

private:
	double a, b, c, d, e;
	void solve() override;
	void computeN() override;
	void inputCoef() override;
};


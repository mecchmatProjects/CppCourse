#include "LinearEq.h"

LinearEq::LinearEq()
{
	inputCoef();

	//std::cout << std::endl;

	computeN();

	if (n != 0 || n != 255)
	{
		x = new double[n];
	}

	solve();
}

LinearEq::LinearEq(const double a, const double b)
{
	this->a = a;
	this->b = b;

	computeN();

	if (n != 0 || n != 255)
	{
		x = new double[n];
	}

	solve();
}


LinearEq::~LinearEq()
{
	delete[] x;
	x = nullptr;
}

void LinearEq::computeN() 
{
	if ((a * a + b * b) == 0)
	{
		n = 255;
	}
	else if ((a == 0) && (b != 0))
	{
		n = 0;
	}
	else 
	{
		n = 1;
	}
}

void LinearEq::solve()
{
	std::cout << "\n\tStart solve!" << std::endl;

	if (n == 255 || n == 0)
	{
		return;
	}
	else
	{
		if (b != 0)
		{
			x[0] = (-1.0) * (b / a);
		}
		else
		{
			x[0] = 0;
		}
	}
}

void LinearEq::showX()
{
	if (n == 255)
	{
		std::cout << "\t\t-We have to many solves!" << std::endl;
	}
	else if (n == 0)
	{
		std::cout << "\t\t-We have no solves!" << std::endl;
	}
	else
	{
		std::cout << "\t\t-Our solves is x = " << x[0] << std::endl;
	}
}

void LinearEq::inputCoef()
{
	std::cout << "\tPlease, input a = ?\b";
	while (!(std::cin >> a))
	{
		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\t\t-Invalid input. Try aganin: ";
	}

	// std::cout << std::endl;

	std::cout << "\tPlease, input b = ?\b";
	while (!(std::cin >> b))
	{
		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\t\t-Invalid input. Try aganin: ";
	}
}

double LinearEq::getX()
{
	return x[0];
}

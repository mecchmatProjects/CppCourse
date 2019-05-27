#include "SquareEq.h"



SquareEq::SquareEq()
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


SquareEq::SquareEq(const double a, const double b, const double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
	computeN();

	if (n != 0 || n != 255)
	{
		x = new double[n];
	}

	solve();
}



SquareEq::~SquareEq()
{
	delete[] x;
	x = nullptr;
}

void SquareEq::computeN()
{
	if (a == 0)
	{
		LinearEq* linear = new LinearEq(b, c);

		n = linear->getN();

		delete linear;
	}
	else
	{

		D = computeD();

		if (D == 0)
		{
			n = 1;
		}
		else if (D > 0)
		{
			n = 2;
		}
		else
		{
			n = 0;
		}
	}
}

double SquareEq::computeD()
{
	return b * b - 4 * a * c;
}

void SquareEq::solve()
{
	//std::cout << "\n\tStart solve!" << std::endl;

	if (a == 0)
	{
		LinearEq *linear = new LinearEq(b, c);

		x[0] = linear->getX();

		delete linear;
	}
	else
	{
		if (D == 0)
		{
			x[0] = (-1) * b / (2.0 * a);
		}
		else if (D > 0)
		{
			x[0] = ((-1) * b + sqrt(D))/ (2.0 * a);
			x[1] = ((-1) * b - sqrt(D)) / (2.0 * a);
		}
	}
}

void SquareEq::showX()
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
		std::cout << "\t\t-Our solves are:\n";
		for (int i = 0; i < n; i++)
		{
			std::cout << "\t\t\tx[" << i << "] = " << x[i] << std::endl;
		}
	}
}

int SquareEq::GetN()
{
	return n;
}

double* SquareEq::GetX()
{
	return x;
}

void SquareEq::inputCoef()
{
	std::cout << "\tPlease, input a = ?\b";
	while (!(std::cin >> a))
	{
		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\t\t-Invalid input. Try aganin: ";
	}

	std::cout << "\tPlease, input b = ?\b";
	while (!(std::cin >> b))
	{
		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\t\t-Invalid input. Try aganin: ";
	}

	std::cout << "\tPlease, input c = ?\b";
	while (!(std::cin >> c))
	{
		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\t\t-Invalid input. Try aganin: ";
	}
}


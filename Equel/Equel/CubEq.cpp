#include "CubEq.h"
#include <fstream>


CubEq::CubEq()
{
	inputCoef();

	Zmist();

	compSQR();

	computeN();

	if (n != 0 || n != 255)
	{
		x = new double[n];
	}

	solve();
}


CubEq::CubEq(double const a, double const b, double const c, double const d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;

	Zmist();

	compSQR();

	computeN();

	if (n != 0 || n != 255)
	{
		x = new double[n];
	}

	solve();
}



CubEq::~CubEq()
{
	delete[] x;
	x = nullptr;
}


void CubEq::compSQR()
{
	Q = (b*b - 3*c)/9;
	R = (2*b*b*b - 9*b*c + 27*d)/54;
	S = Q * Q * Q - R * R;
	//std::cout << S << std::endl;
	//std::cout << Q << std::endl;
	//std::cout << R << std::endl;
}


void CubEq::Zmist()
{
	if (a != 0)
	{
		b = b / a;
		c = c / a;
		d = d / a;
		a = 1;
	}
}


void CubEq::computeN()
{
	if (a != 0)
	{
		if (S >= 0)
		{
			n = 3;
		}
		else
		{
			n = 1;
		}
	}
	else
	{
		SquareEq* sq = new SquareEq(b, c, d);
		n = sq->GetN();

	}
}


void CubEq::solve()
{
	//std::cout << "\n\tStart solve!" << std::endl;

	if (a == 0)
	{
		if (b == 0)
		{
			LinearEq* linear = new LinearEq(c, d);

			x[0] = linear->getX();
			n = linear->getN();
			//std::cout << "We are in cycle " << x[0];

		}
		else
		{
			
			SquareEq* sq = new SquareEq(b, c, d);

			x = sq->GetX();
		}
	}
	else
	{
		if (S > 0)
		{
			double fi;
			//std::cout << "fi_under =  " << R / sqrt(Q * Q * Q) << std::endl;
			//std::cout << "acos =  " << acos(-0.7638) << std::endl;
			fi = acos(R / sqrt(Q * Q * Q))/3;
			//std::cout << "fi =  " << fi << std::endl;
			x[0] = -2 * sqrt(Q) * cos(fi) - b / 3;
			//std::cout << "x[0] = " << x[0];
			x[1] = -2 * sqrt(Q) * cos(fi - 2*M_PI/3) - b / 3;
			x[2] = -2 * sqrt(Q) * cos(fi + 2*M_PI/3) - b / 3;
		}
		else if (S == 0)
		{
			//std::cout << "We are in cycle " << x[0];
			x[0] = -2*cbrt(R) - b / 3;
			x[1] = cbrt(R) - b / 3;
			x[2] = cbrt(R) - b / 3;
		}
		else
		{
			//std::cout << "We are in cycle " << x[0];
			if (Q > 0)
			{
				double fi;
				fi = acosh(abs(R) / sqrt(Q * Q * Q)) / 3;
				x[0] = -2 * R / abs(R) * sqrt(Q) * cosh(fi) - b / 3;
			}
			else if (Q < 0)
			{
				//std::cout << "We are in cycle " << x[0];
				double fi;
				fi = asinh(abs(R) / sqrt(abs(Q * Q * Q))) / 3;
				x[0] = -2 * R / abs(R) * sqrt(abs(Q)) * sinh(fi) - b / 3;
			}
			else
			{
				x[0] = -cbrt(d - b * b * b / 27) - b / 3;
			}
		}
	}
}


void CubEq::showX()
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

double* CubEq::GetX()
{
	return x;
}


void CubEq::inputCoef()
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

	std::cout << "\tPlease, input d = ?\b";
	while (!(std::cin >> d))
	{
		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\t\t-Invalid input. Try aganin: ";
	}
}

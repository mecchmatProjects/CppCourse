#include "FourStEq.h"



FourStEq::FourStEq()
{
	inputCoef();

	computeN();

	if (n != 0 || n != 255)
	{
		//std::cout << "Here";
		x = new double[n];
	}

	solve();
}


FourStEq::FourStEq(double const a, double const b, double const c, double const d, double const e)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->e = e;
	

	computeN();

	if (n != 0 || n != 255)
	{
		//std::cout << "Here";
		x = new double[n];
	}

	solve();
}



FourStEq::~FourStEq()
{
	delete x;
	x = nullptr;
}


void FourStEq::computeN()
{
	if (a == 0)
	{
		CubEq* cb = new CubEq(b, c, d, e);
		n = cb->getN();
	}
	else
	{
		double a1, b1, c1, d1;
		a1 = b / a;
		b1 = c / a;
		c1 = d / a;
		d1 = e / a;
		double p, q, r, s;
		p = b1 - 3 * a1 * a1 / 8;
		q = a1 * a1 * a1 / 8 - a1 * b1 / 2 + c1;
		r = -3 * (a1 * a1 * a1 * a1 / 256) + (a1 * a1 * b1 / 16) - (c1 * a1 / 4) + (d1);

		CubEq* cb = new CubEq(2, -p, (-2 * r), (r * p - q * q / 4));
		//std::cout << "2 = " << -p << std::endl;
		//std::cout << "3 = " << -2*r << std::endl;
		//std::cout << "4 = " << r*p - q*q/4 << std::endl;
		s = cb->GetX()[0];
		
		//std::cout << "s = " << s << std::endl;
		//std::cout << "s2 = " << cb->GetX()[1] << std::endl;
		//std::cout << "s3 = " << cb->GetX()[2] << std::endl;
		//std::cout << "p = " << p << std::endl;
		//std::cout << "q = " << q << std::endl;
		//std::cout << "r = " << r << std::endl;
		if (2 * s - p <= 0)
		{
			n = 0;
		}
		else
		{
			//std::cout << "We are here";
			int n1, n2;
			SquareEq* sq = new SquareEq(1, -sqrt(2 * s - p), q / (2 * sqrt(2 * s - p)));
			SquareEq* sq2 = new SquareEq(1, sqrt(2 * s - p), -q / (2 * sqrt(2 * s - p)));

			n1 = sq->getN();
			n2 = sq2->getN();
			//td::cout << "n1 = " << n1 << std::endl;
			//std::cout << "n2 = " << n2 << std::endl;

			n = n1 + n2;
			//std::cout << "n = " << n << std::endl;
		}
	}
}


void FourStEq::solve()
{
	//std::cout << "Here";
	if (a == 0)
	{
		CubEq* cb = new CubEq(b, c, d, e);
		x = cb->GetX();
	}
	else
	{
		double a1, b1, c1, d1;
		a1 = b / a;
		b1 = c / a;
		c1 = d / a;
		d1 = e / a;
		double p, q, r, s;
		p = b1 - 3 * a1 * a1 / 8;
		q = a1 * a1 * a1 / 8 - a1 * b1 / 2 + c1;
		r = -3 * (a1 * a1 * a1 * a1 / 256) + (a1 * a1 * b1 / 16) - (c1 * a1 / 4) + (d1);

		CubEq* cb = new CubEq(2, -p, -2 * r, r * p - q * q / 4);
		s = cb->GetX()[0];

		SquareEq* sq = new SquareEq(1, -sqrt(2 * s - p), q / (2 * sqrt(2 * s - p)) + s);
		SquareEq * sq2 = new SquareEq(1, sqrt(2 * s - p), -q / (2 * sqrt(2 * s - p)) + s);

		//std::cout << "b3 = " << -sqrt(2 * s - p) << "c3 = " << q / (2 * sqrt(2 * s - p)) + s << std::endl;
		//std::cout << "b3 = " << sqrt(2 * s - p) << "c3 = " << -q / (2 * sqrt(2 * s - p)) + s << std::endl;

		int n1, n2;
		double* x1 = new double;
		double* x2 = new double;


		n1 = sq->getN();
		n2 = sq2->getN();

		x1 = sq->GetX();
		x2 = sq2->GetX();

		//std::cout << " x1 = " << x1[0] << " x2 = " << x1[1] << " x3 = " << x2[0] << " x4 = " << x2[1] << std::endl;

		if ((n1 != 255) && (n != 0))
		{
			for (int i = 0; i < n1; i++)
			{
				x[i] = x1[i] - a1/4;
			}
		}
		if ((n2 != 255) && (n != 0))
		{
			for (int i = 0; i < n2; i++)
			{
				x[n1 + i] = x2[i] - a1/4;
			}
		}
	}
}


void FourStEq::showX()
{
	//std::cout << "Here";
	if (n == 255)
	{
		std::cout << "\t\t-We have to many solves!" << std::endl;
	}
	else if (n == 510)
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


void FourStEq::inputCoef()
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

	std::cout << "\tPlease, input e = ?\b";
	while (!(std::cin >> e))
	{
		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\t\t-Invalid input. Try aganin: ";
	}
}

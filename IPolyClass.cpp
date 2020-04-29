#include "IPolyClass.h"

IPOLY::IPOLY()
{

}

IPOLY::~IPOLY()
{
	thisPoly.clear();
}

IPOLY::IPOLY(const vector < int > & _poly, int _modul)
{
	modul = _modul;
	polySize = _poly.size();

	for (int i = 0; i < _poly.size(); i++)
	{
		thisPoly.push_back(_poly[i]);
	}
}

IPOLY IPOLY::operator+(IPOLY rValue)
{
	vector < int > result;
	int resultModul = modul;

	for (int i = 0; i < max(polySize, rValue.getSize()); i++)
	{
		int coefficient = 0;

		if (i < polySize)
		{
			coefficient += thisPoly[i];
		}

		if (i < rValue.getSize())
		{
			coefficient += rValue.get—oefficient(i);
		}

		if (resultModul)
		{
			coefficient %= resultModul;
		}

		result.push_back(coefficient);
	}

	for (; result.size() && result.back() == 0; result.pop_back()) {}

	IPOLY Result(result, resultModul);

	return Result;
}

IPOLY IPOLY::operator-(IPOLY rValue)
{
	vector < int > result;
	int resultModul = modul;

	for (int i = 0; i < max(polySize, rValue.getSize()); i++)
	{
		int coefficient = 0;

		if (i < polySize)
		{
			coefficient += thisPoly[i];
		}

		if (i < rValue.getSize())
		{
			coefficient -= rValue.get—oefficient(i);
		}

		for (; coefficient < 0; coefficient += resultModul) {}

		if (resultModul)
		{
			coefficient %= resultModul;
		}

		result.push_back(coefficient);
	}

	for (; result.size() && result.back() == 0; result.pop_back()) {}

	IPOLY Result(result, resultModul);

	return Result;
}

IPOLY IPOLY::operator*(IPOLY rValue)
{
	vector < int > result;
	int resultModul = modul;

	for (int i = 0; i < polySize; i++)
	{
		for (int j = 0; j < rValue.getSize(); j++)
		{
			int coefficient = (thisPoly[i] * rValue.get—oefficient(j));

				if (resultModul)
				{
					coefficient %= resultModul;
				}

			if (i + j >= result.size())
			{
				result.push_back(coefficient);
			}
			else
			{
				result[i + j] += coefficient;

				if (resultModul)
				{
					result[i + j] %= resultModul;
				}
			}
		}
	}

	for (; result.size() && result.back() == 0; result.pop_back()) {}

	IPOLY Result(result, resultModul);

	return Result;
}

IPOLY IPOLY::operator/(IPOLY rValue)
{
	vector < int > result;
	int resultModul = modul;
	
	if (rValue.getSize() == 0)
	{
		IPOLY Result(result, modul);

		return Result;
	}

	vector < int > current = thisPoly;
	
	for (int i = polySize; i >= rValue.getSize(); i--)
	{
		int coefficient = current[i - 1] / rValue.get—oefficient(rValue.getSize()-1);

		for (int j = 1; j <= rValue.getSize(); j++)
		{
			current[i - j] -= (rValue.get—oefficient(rValue.getSize() - j) * coefficient);

			if (resultModul)
			{
				for(; current[i-j] < 0; current[i-j] += resultModul){}
			}
		}

		result.push_back(coefficient);
	}

	reverse(result.begin(), result.end());

	for (; result.size() > 0 && result.back() == 0; result.pop_back()) {}

	IPOLY Result(result, resultModul);

	return Result;
}

IPOLY IPOLY::operator%(IPOLY rValue)
{
	vector < int > result;
	int resultModul = modul;

	if (rValue.getSize() == 0)
	{
		IPOLY Result(result, modul);

		return Result;
	}

	vector < int > current = thisPoly;

	for (int i = polySize; i >= rValue.getSize(); i--)
	{
		int coefficient = current[i - 1] / rValue.get—oefficient(rValue.getSize() - 1);

		for (int j = 1; j <= rValue.getSize(); j++)
		{
			current[i - j] -= (rValue.get—oefficient(rValue.getSize() - j) * coefficient);

			if (resultModul)
			{
				for (; current[i - j] < 0; current[i - j] += resultModul) {}
			}
		}

		result.push_back(coefficient);
	}

	reverse(result.begin(), result.end());

	for (; current.size() > 0 && current.back() == 0; current.pop_back()) {}

	IPOLY Result(current, resultModul);

	return Result;
}

bool IPOLY::operator == (IPOLY rValue)
{
	if (rValue.getSize() != polySize)
	{
		return 0;
	}

	if (rValue.getModul() != modul)
	{
		return 0;
	}

	for (int i = 0; i < polySize; i++)
	{
		if (rValue.get—oefficient(i) != thisPoly[i])
		{
			return 0;
		}
	}

	return 1;
}

IPOLY IPOLY::integral()
{
	vector < int >  result;
	result.push_back(0);

	int resultModul = modul;

	for (int i = 0; i < polySize; i++)
	{
		int res = thisPoly[i] / (i + 1);

		result.push_back(res);
	}

	for (; result.size() > 0 && result.back() == 0; result.pop_back()) {}

	IPOLY Result(result, resultModul);

	return Result;
}

IPOLY IPOLY::derevative()
{
	vector < int > result;
	int resulModul = modul;

	for (int i = 1; i < polySize; i++)
	{
		int value = thisPoly[i] * i;

		if (resulModul)
		{
			value %= modul;
		}

		result.push_back(value);
	}

	for (; result.size() > 0 && result.back() == 0; result.pop_back()) {}

	IPOLY Result(result, resulModul);

	return Result;
}

double IPOLY::value(double point)
{
	double result = 0;
	double step = 1;

	for (int i = 0; i < polySize; i++)
	{
		result += thisPoly[i] * step;

		step *= point;
	}

	return result;
}

double IPOLY::integral(double from, double to)
{
	IPOLY P = integral();

	double result = P.value(to) - P.value(from);

	return result;
}

int IPOLY::getSize()
{
	return polySize;
}

int IPOLY::getModul()
{
	return modul;
}

int IPOLY::get—oefficient(int position)
{
	if (position >= polySize)
	{
		return 0;
	}

	return thisPoly[position];
}

ostream& operator << (ostream & out, const IPOLY & poly)
{
	for (int i = poly.polySize - 1; i >= 0; i--)
	{
		if (poly.thisPoly[i] == 0)
		{
			continue;
		}

		if (i != poly.polySize - 1)
		{
			out << " + ";
		}

		if (i == 0)
		{
			out << poly.thisPoly[i];

			continue;
		}

		if (poly.thisPoly[i] > 1)
		{
			out << poly.thisPoly[i] << "*x";

			if (i > 1)
			{
				out << "^" << i;
			}

		}else
		{
			out << "x";

			if (i > 1)
			{
				out << "^" << i;
			}
		}
	}

	return out;
}

istream& operator >> (istream & in, IPOLY & poly)
{
	vector < int > thisPoly;
	int modul, sz;

	in >> modul >> sz;

	for (int i = 0; i < sz; i++)
	{
		int x;

		in >> x;

		if (modul)
		{
			for (; x < 0; x += modul) {}

			x %= modul;
		}

		thisPoly.push_back(x);
	}

	reverse(thisPoly.begin(), thisPoly.end());

	poly = IPOLY(thisPoly, modul);

	return in;
}

ofstream& operator << (ofstream & out, const IPOLY & poly)
{
	for (int i = poly.polySize - 1; i >= 0; i--)
	{
		if (poly.thisPoly[i] == 0)
		{
			continue;
		}

		if (i != poly.polySize - 1)
		{
			out << " + ";
		}

		if (i == 0)
		{
			out << poly.thisPoly[i];

			continue;
		}

		if (poly.thisPoly[i] > 1)
		{
			out << poly.thisPoly[i] << "*x^" << i;
		}else
		{
			out << "x^" << i;
		}
	}

	return out;
}

ifstream& operator >> (ifstream & in, IPOLY & poly)
{
	vector < int > thisPoly;
	int modul, sz;

	in >> modul >> sz;

	for (int i = 0; i < sz; i++)
	{
		int x;

		in >> x;

		if (modul)
		{
			for (; x < 0; x += modul) {}

			x %= modul;
		}

		thisPoly.push_back(x);
	}

	reverse(thisPoly.begin(), thisPoly.end());

	poly = IPOLY(thisPoly, modul);

	return in;
}
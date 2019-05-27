#include "SplineClass.h"



SPLINE::SPLINE()
{

}

SPLINE::SPLINE(vector < IPOLY > & _polys, vector < double > _nodes, int _defect)
{
	polys = _polys;
	nodes = _nodes;
	defect = _defect;
}

SPLINE SPLINE::operator+(SPLINE rValue)
{
	if (rValue.getCountPoly() == 0 || polys.size() == 0)
	{
		SPLINE Result;

		return Result;
	}

	if (nodes[0] > rValue.getNode(rValue.getCountPoly()) || rValue.getNode(0) > nodes.back())
	{
		SPLINE Result;

		return Result;
	}

	int pointerThis = 0;
	int pointerRValue = 0;

	vector < double > resultNodes;
	vector < IPOLY > resultPolys;
	int resultDefect = min(defect, rValue.getDefect());

	double l, r;

	for (; pointerRValue < rValue.getCountPoly() && pointerThis < polys.size();)
	{
		l = max(rValue.getNode(pointerRValue), nodes[pointerThis]);
		r = min(rValue.getNode(pointerRValue+1), nodes[pointerThis+1]);

		if (r < l)
		{
			continue;
		}
		else
		{
			resultNodes.push_back(l);
			IPOLY current = polys[pointerThis] + rValue.getPoly(pointerRValue);

			if (nodes[pointerThis + 1] < rValue.getNode(pointerRValue + 1))
			{
				pointerThis++;
			}
			else
			{
				pointerRValue++;
			}

			resultPolys.push_back(current);
		}
	}

	resultNodes.push_back(r);

	SPLINE Result(resultPolys, resultNodes, resultDefect);
	return Result;
}

SPLINE SPLINE::operator-(SPLINE rValue)
{
	if (rValue.getCountPoly() == 0 || polys.size() == 0)
	{
		SPLINE Result;

		return Result;
	}

	if (nodes[0] > rValue.getNode(rValue.getCountPoly()) || rValue.getNode(0) > nodes.back())
	{
		SPLINE Result;

		return Result;
	}

	int pointerThis = 0;
	int pointerRValue = 0;

	vector < double > resultNodes;
	vector < IPOLY > resultPolys;
	int resultDefect = min(defect, rValue.getDefect());

	double l, r;

	for (; pointerRValue < rValue.getCountPoly() && pointerThis < polys.size();)
	{
		l = max(rValue.getNode(pointerRValue), nodes[pointerThis]);
		r = min(rValue.getNode(pointerRValue + 1), nodes[pointerThis + 1]);

		if (r < l)
		{
			continue;
		}
		else
		{
			resultNodes.push_back(l);
			IPOLY current = polys[pointerThis] - rValue.getPoly(pointerRValue);

			if (nodes[pointerThis + 1] < rValue.getNode(pointerRValue + 1))
			{
				pointerThis++;
			}
			else
			{
				pointerRValue++;
			}

			resultPolys.push_back(current);
		}
	}

	resultNodes.push_back(r);

	SPLINE Result(resultPolys, resultNodes, resultDefect);
	return Result;
}

SPLINE SPLINE::operator*(SPLINE rValue)
{
	if (rValue.getCountPoly() == 0 || polys.size() == 0)
	{
		SPLINE Result;

		return Result;
	}

	if (nodes[0] > rValue.getNode(rValue.getCountPoly()) || rValue.getNode(0) > nodes.back())
	{
		SPLINE Result;

		return Result;
	}

	int pointerThis = 0;
	int pointerRValue = 0;

	vector < double > resultNodes;
	vector < IPOLY > resultPolys;
	int resultDefect = min(defect, rValue.getDefect());

	double l, r;

	for (; pointerRValue < rValue.getCountPoly() && pointerThis < polys.size();)
	{
		l = max(rValue.getNode(pointerRValue), nodes[pointerThis]);
		r = min(rValue.getNode(pointerRValue + 1), nodes[pointerThis + 1]);

		if (r < l)
		{
			continue;
		}
		else
		{
			resultNodes.push_back(l);
			IPOLY current = polys[pointerThis] * rValue.getPoly(pointerRValue);

			if (nodes[pointerThis + 1] < rValue.getNode(pointerRValue + 1))
			{
				pointerThis++;
			}
			else
			{
				pointerRValue++;
			}

			resultPolys.push_back(current);
		}
	}

	resultNodes.push_back(r);

	SPLINE Result(resultPolys, resultNodes, resultDefect);
	return Result;
}

SPLINE SPLINE::operator/(SPLINE rValue)
{
	if (rValue.getCountPoly() == 0 || polys.size() == 0)
	{
		SPLINE Result;

		return Result;
	}

	if (nodes[0] > rValue.getNode(rValue.getCountPoly()) || rValue.getNode(0) > nodes.back())
	{
		SPLINE Result;

		return Result;
	}

	int pointerThis = 0;
	int pointerRValue = 0;

	vector < double > resultNodes;
	vector < IPOLY > resultPolys;
	int resultDefect = min(defect, rValue.getDefect());

	double l, r;

	for (; pointerRValue < rValue.getCountPoly() && pointerThis < polys.size();)
	{
		l = max(rValue.getNode(pointerRValue), nodes[pointerThis]);
		r = min(rValue.getNode(pointerRValue + 1), nodes[pointerThis + 1]);

		if (r < l)
		{
			continue;
		}
		else
		{
			resultNodes.push_back(l);
			IPOLY current = polys[pointerThis] / rValue.getPoly(pointerRValue);

			if (nodes[pointerThis + 1] < rValue.getNode(pointerRValue + 1))
			{
				pointerThis++;
			}
			else
			{
				pointerRValue++;
			}

			resultPolys.push_back(current);
		}
	}

	resultNodes.push_back(r);

	SPLINE Result(resultPolys, resultNodes, resultDefect);
	return Result;
}

SPLINE SPLINE::operator%(SPLINE rValue)
{
	if (rValue.getCountPoly() == 0 || polys.size() == 0)
	{
		SPLINE Result;

		return Result;
	}

	if (nodes[0] > rValue.getNode(rValue.getCountPoly()) || rValue.getNode(0) > nodes.back())
	{
		SPLINE Result;

		return Result;
	}

	int pointerThis = 0;
	int pointerRValue = 0;

	vector < double > resultNodes;
	vector < IPOLY > resultPolys;
	int resultDefect = min(defect, rValue.getDefect());

	double l, r;

	for (; pointerRValue < rValue.getCountPoly() && pointerThis < polys.size();)
	{
		l = max(rValue.getNode(pointerRValue), nodes[pointerThis]);
		r = min(rValue.getNode(pointerRValue + 1), nodes[pointerThis + 1]);

		if (r < l)
		{
			continue;
		}
		else
		{
			resultNodes.push_back(l);
			IPOLY current = polys[pointerThis] % rValue.getPoly(pointerRValue);

			if (nodes[pointerThis + 1] < rValue.getNode(pointerRValue + 1))
			{
				pointerThis++;
			}
			else
			{
				pointerRValue++;
			}

			resultPolys.push_back(current);
		}
	}

	resultNodes.push_back(r);

	SPLINE Result(resultPolys, resultNodes, resultDefect);
	return Result;
}

ofstream& operator << (ofstream & out, const SPLINE & spline)
{
	for (int i = 0; i < spline.nodes.size(); i++)
	{
		out << spline.nodes[i] << " ";
	}out << "\n";

	for (int i = 0; i < spline.polys.size(); i++)
	{
		out << spline.polys[i];
		out << "\n";
	}

	return out;
}

ostream& operator << (ostream & out, const SPLINE & spline)
{

	for (int i = 0; i < spline.nodes.size(); i++)
	{
		out << spline.nodes[i] << " ";
	}out << "\n";

	for (int i = 0; i < spline.polys.size(); i++)
	{
		out << spline.polys[i];
		out << "\n";
	}

	return out;
}

ifstream& operator >> (ifstream & in, SPLINE & spline)
{
	int countPolys;

	in >> countPolys;

	for (int i = 0; i <= countPolys; i++)
	{
		double x;
		in >> x;

		spline.nodes.push_back(x);
	}

	for (int i = 0; i < countPolys; i++)
	{
		IPOLY x;
		in >> x;

		spline.polys.push_back(x);
	}

	return in;
}

istream& operator >> (istream & in, SPLINE & spline)
{
	int countPolys;

	in >> countPolys;

	for (int i = 0; i <= countPolys; i++)
	{
		double x;
		in >> x;

		spline.nodes.push_back(x);
	}

	for (int i = 0; i < countPolys; i++)
	{
		IPOLY x;
		in >> x;

		spline.polys.push_back(x);
	}

	return in;
}

bool SPLINE::operator == (SPLINE rValue)
{
	if (defect != rValue.getDefect())
	{
		return 0;
	}

	if (polys.size() != rValue.getCountPoly())
	{
		return 0;
	}

	for (int i = 0; i < polys.size(); i++)
	{
		if (!(polys[i] == rValue.getPoly(i)))
		{
			return 0;
		}

		if (abs(nodes[i] - rValue.getNode(i)) > eps)
		{
			return 0;
		}
	}

	if(nodes.size() && abs(nodes.back() - rValue.getNode(rValue.getCountPoly())) > eps)
	{
		return 0;
	}

	return 1;
}

double SPLINE::value(double point)
{
	if (nodes.size() == 0 || point < nodes[0] - eps || point > nodes.back() + eps)
	{
		return 0;
	}

	for (int i = 0; i < polys.size(); i++)
	{
		if (point > nodes[i] - eps && point < nodes[i + 1] + eps)
		{
			return polys[i].value(point);
		}
	}

	return 0;
}

SPLINE SPLINE::derivate()
{
	vector < IPOLY > poly;

	for (int i = 0; i < polys.size(); i++)
	{
		poly.push_back(polys[i].derevative());
	}

	SPLINE Result(poly, nodes, defect);

	return Result;
}

SPLINE SPLINE::integral()
{
	vector < IPOLY > poly;

	for (int i = 0; i < polys.size(); i++)
	{
		poly.push_back(polys[i].integral());
	}

	SPLINE Result(poly, nodes, defect);

	return Result;
}

double SPLINE::integral(double from, double to)
{
	double result = 0;

	for (int i = 0; i < polys.size(); i++)
	{
		if (nodes[i + 1] + eps < from)
		{
			continue;
		}

		if (nodes[i] - eps > to)
		{
			continue;
		}

		double l = max(nodes[i], from);
		double r = min(nodes[i + 1], to);

		result += polys[i].integral(l, r);
	}

	return result;
}

int SPLINE::getCountPoly()
{
	return polys.size();
}

IPOLY SPLINE::getPoly(int position)
{
	IPOLY result;

	if (position >= polys.size())
	{
		return result;
	}
	else
	{
		result = polys[position];
		return result;
	}
}

int SPLINE::getDefect()
{
	return defect;
}

double SPLINE::getNode(int position)
{
	if (position >= nodes.size())
	{
		return 0;
	}

	return nodes[position];
}


SPLINE::~SPLINE()
{

}

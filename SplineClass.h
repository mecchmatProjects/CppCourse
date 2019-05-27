#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <time.h>
#include <random>
#include <memory.h>
#include <bitset>

#include "IPolyClass.h"

using namespace std;

class SPLINE
{
	double eps = 1e-6;

	int countSegment = 0;
	int defect = 0;
	vector < IPOLY > polys;
	vector < double > nodes;

public:
	SPLINE();
	SPLINE(vector < IPOLY > & _polys, vector < double > _nodes, int _defect);

	SPLINE operator+(SPLINE rValue);
	SPLINE operator-(SPLINE rValue);
	SPLINE operator*(SPLINE rValue);
	SPLINE operator/(SPLINE rValue);
	SPLINE operator%(SPLINE rValue);

	bool operator == (SPLINE rValue);

	friend ofstream& operator << (ofstream & out, const SPLINE & spline);
	friend ostream& operator << (ostream & out, const SPLINE & spline);

	friend istream& operator >> (istream & in, SPLINE & spline);
	friend ifstream& operator >> (ifstream & in, SPLINE & spline);

	double value(double point);

	SPLINE derivate();
	SPLINE integral();
	double integral(double from, double to);

	int getCountPoly(); 
	IPOLY getPoly(int position);
	int getDefect();
	double getNode(int position);

	~SPLINE();
};
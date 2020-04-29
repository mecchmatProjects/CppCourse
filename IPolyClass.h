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
using namespace std;

#ifndef IPOLY_CLASS
#define IPOLY_CLASS

class IPOLY
{
	vector < int > thisPoly;
	int polySize = 0;
	int modul = 0;

public:

	IPOLY();
	IPOLY(const vector < int > & _poly, int _modul);

	IPOLY operator + (IPOLY rValue);
	IPOLY operator - (IPOLY rValue);
	IPOLY operator * (IPOLY rValue);
	IPOLY operator / (IPOLY rValue);
	IPOLY operator % (IPOLY rValue);

	bool operator == (IPOLY rValue);

	friend ostream& operator << (ostream & out, const IPOLY & poly);
	friend istream& operator >> (istream & in, IPOLY & poly);

	friend ofstream& operator << (ofstream & out, const IPOLY & poly);
	friend ifstream& operator >> (ifstream & in, IPOLY & poly);
	 
	IPOLY integral();
	IPOLY derevative();

	double value(double point);
	double integral(double from, double to);

	int getSize();
	int getModul();
	int get—oefficient(int position);

	~IPOLY();
};

#endif



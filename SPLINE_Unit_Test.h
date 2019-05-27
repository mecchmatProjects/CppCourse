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

#include "SplineClass.h"

using namespace std;

class SPLINE_Unit_Test
{
	int countTests = 0;
	int countPassed = 0;

public:
	SPLINE_Unit_Test();
	~SPLINE_Unit_Test();

	void addTest();
	void multTest();
	void difTest();
	void divTest();
	void modTest();

	void valueTest();
	void derivateTest();
	void integralTest();

	void makeTest();
};


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

class IPOLY_Unit_Test
{
	int countTests = 0;
	int countPassed = 0;

public:
	IPOLY_Unit_Test();
	~IPOLY_Unit_Test();

	void addingTest();
	void differenceTest();
	void multiplyingTest();
	void dividingTest();
	void modTest();
	void integralTest();
	void derivateTest();
	void valueTest();

	void makeTest();
};


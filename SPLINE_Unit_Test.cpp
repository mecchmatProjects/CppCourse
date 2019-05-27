#include "SPLINE_Unit_Test.h"



SPLINE_Unit_Test::SPLINE_Unit_Test()
{
}


SPLINE_Unit_Test::~SPLINE_Unit_Test()
{
}

void SPLINE_Unit_Test::addTest()
{
	countTests += 2;

	cout << "make '+' test\n";

	cout << " -> make test 1\n";

	vector < int > test1_poly1_coef;
	vector < int > test1_poly2_coef;
	vector < int > test1_poly3_coef;

	vector < double > test1_nodes1;
	vector < double > test1_nodes2;
	vector < double > test1_nodes3;

	test1_poly1_coef.push_back(1);
	test1_poly2_coef.push_back(1);
	test1_poly3_coef.push_back(2);

	IPOLY test1_poly1(test1_poly1_coef, 0);
	IPOLY test1_poly2(test1_poly2_coef, 0);
	IPOLY test1_poly3(test1_poly3_coef, 0);

	vector < IPOLY > test1_polys1;
	vector < IPOLY > test1_polys2;
	vector < IPOLY > test1_polys3;

	test1_polys1.push_back(test1_poly1);
	test1_polys2.push_back(test1_poly2);
	test1_polys3.push_back(test1_poly3);

	test1_nodes1.push_back(0);
	test1_nodes1.push_back(1);
	test1_nodes2.push_back(0);
	test1_nodes2.push_back(1);
	test1_nodes3.push_back(0);
	test1_nodes3.push_back(1);

	SPLINE test1_spline1(test1_polys1, test1_nodes1, 0);
	SPLINE test1_spline2(test1_polys2, test1_nodes2, 0);
	SPLINE test1_spline3(test1_polys3, test1_nodes3, 0);

	if (test1_spline1 + test1_spline2 == test1_spline3)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test1_spline1 + test1_spline2 << "\n";
		cout << test1_spline3 << "\n";
	}

	cout << " -> make test 2\n";

	vector < int > test2_poly1_coef;
	vector < int > test2_poly2_coef;

	vector < double > test2_nodes1;
	vector < double > test2_nodes2;

	test2_poly1_coef.push_back(1);
	test2_poly2_coef.push_back(1);

	IPOLY test2_poly1(test2_poly1_coef, 0);
	IPOLY test2_poly2(test2_poly2_coef, 0);

	vector < IPOLY > test2_polys1;
	vector < IPOLY > test2_polys2;

	test2_polys1.push_back(test2_poly1);
	test2_polys2.push_back(test2_poly2);

	test2_nodes1.push_back(0);
	test2_nodes1.push_back(1);
	test2_nodes2.push_back(2);
	test2_nodes2.push_back(3);

	SPLINE test2_spline1(test2_polys1, test2_nodes1, 0);
	SPLINE test2_spline2(test2_polys2, test2_nodes2, 0);
	SPLINE test2_spline3;

	if (test2_spline1 + test2_spline2 == test2_spline3)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test2_spline1 + test2_spline2 << "\n";
		cout << test2_spline3 << "\n";
	}
}

void SPLINE_Unit_Test::multTest()
{
	countTests += 2;

	cout << "make '*' test\n";

	cout << " -> make test 1\n";

	vector < int > test1_poly1_coef;
	vector < int > test1_poly2_coef;
	vector < int > test1_poly3_coef;

	vector < double > test1_nodes1;
	vector < double > test1_nodes2;
	vector < double > test1_nodes3;

	test1_poly1_coef.push_back(2);
	test1_poly2_coef.push_back(2);
	test1_poly3_coef.push_back(4);

	IPOLY test1_poly1(test1_poly1_coef, 0);
	IPOLY test1_poly2(test1_poly2_coef, 0);
	IPOLY test1_poly3(test1_poly3_coef, 0);

	vector < IPOLY > test1_polys1;
	vector < IPOLY > test1_polys2;
	vector < IPOLY > test1_polys3;

	test1_polys1.push_back(test1_poly1);
	test1_polys2.push_back(test1_poly2);
	test1_polys3.push_back(test1_poly3);

	test1_nodes1.push_back(0);
	test1_nodes1.push_back(1);
	test1_nodes2.push_back(0);
	test1_nodes2.push_back(1);
	test1_nodes3.push_back(0);
	test1_nodes3.push_back(1);

	SPLINE test1_spline1(test1_polys1, test1_nodes1, 0);
	SPLINE test1_spline2(test1_polys2, test1_nodes2, 0);
	SPLINE test1_spline3(test1_polys3, test1_nodes3, 0);

	if (test1_spline1 * test1_spline2 == test1_spline3)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test1_spline1 * test1_spline2 << "\n";
		cout << test1_spline3 << "\n";
	}

	cout << " -> make test 2\n";

	vector < int > test2_poly1_coef;
	vector < int > test2_poly2_coef;

	vector < double > test2_nodes1;
	vector < double > test2_nodes2;

	test2_poly1_coef.push_back(2);
	test2_poly2_coef.push_back(2);

	IPOLY test2_poly1(test2_poly1_coef, 0);
	IPOLY test2_poly2(test2_poly2_coef, 0);

	vector < IPOLY > test2_polys1;
	vector < IPOLY > test2_polys2;

	test2_polys1.push_back(test2_poly1);
	test2_polys2.push_back(test2_poly2);

	test2_nodes1.push_back(0);
	test2_nodes1.push_back(1);
	test2_nodes2.push_back(2);
	test2_nodes2.push_back(3);

	SPLINE test2_spline1(test2_polys1, test2_nodes1, 0);
	SPLINE test2_spline2(test2_polys2, test2_nodes2, 0);
	SPLINE test2_spline3;

	if (test2_spline1 * test2_spline2 == test2_spline3)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test2_spline1 * test2_spline2 << "\n";
		cout << test2_spline3 << "\n";
	}
}

void SPLINE_Unit_Test::difTest()
{
	countTests += 2;

	cout << "make '-' test\n";

	cout << " -> make test 1\n";

	vector < int > test1_poly1_coef;
	vector < int > test1_poly2_coef;
	vector < int > test1_poly3_coef;

	vector < double > test1_nodes1;
	vector < double > test1_nodes2;
	vector < double > test1_nodes3;

	test1_poly1_coef.push_back(2);
	test1_poly2_coef.push_back(1);
	test1_poly3_coef.push_back(1);

	IPOLY test1_poly1(test1_poly1_coef, 0);
	IPOLY test1_poly2(test1_poly2_coef, 0);
	IPOLY test1_poly3(test1_poly3_coef, 0);

	vector < IPOLY > test1_polys1;
	vector < IPOLY > test1_polys2;
	vector < IPOLY > test1_polys3;

	test1_polys1.push_back(test1_poly1);
	test1_polys2.push_back(test1_poly2);
	test1_polys3.push_back(test1_poly3);

	test1_nodes1.push_back(0);
	test1_nodes1.push_back(1);
	test1_nodes2.push_back(0);
	test1_nodes2.push_back(1);
	test1_nodes3.push_back(0);
	test1_nodes3.push_back(1);

	SPLINE test1_spline1(test1_polys1, test1_nodes1, 0);
	SPLINE test1_spline2(test1_polys2, test1_nodes2, 0);
	SPLINE test1_spline3(test1_polys3, test1_nodes3, 0);

	if (test1_spline1 - test1_spline2 == test1_spline3)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test1_spline1 - test1_spline2 << "\n";
		cout << test1_spline3 << "\n";
	}

	cout << " -> make test 2\n";

	vector < int > test2_poly1_coef;
	vector < int > test2_poly2_coef;

	vector < double > test2_nodes1;
	vector < double > test2_nodes2;

	test2_poly1_coef.push_back(2);
	test2_poly2_coef.push_back(1);

	IPOLY test2_poly1(test2_poly1_coef, 0);
	IPOLY test2_poly2(test2_poly2_coef, 0);

	vector < IPOLY > test2_polys1;
	vector < IPOLY > test2_polys2;

	test2_polys1.push_back(test2_poly1);
	test2_polys2.push_back(test2_poly2);

	test2_nodes1.push_back(0);
	test2_nodes1.push_back(1);
	test2_nodes2.push_back(2);
	test2_nodes2.push_back(3);

	SPLINE test2_spline1(test2_polys1, test2_nodes1, 0);
	SPLINE test2_spline2(test2_polys2, test2_nodes2, 0);
	SPLINE test2_spline3;

	if (test2_spline1 - test2_spline2 == test2_spline3)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test2_spline1 - test2_spline2 << "\n";
		cout << test2_spline3 << "\n";
	}
}

void SPLINE_Unit_Test::divTest()
{
	countTests += 2;

	cout << "make '/' test\n";

	cout << " -> make test 1\n";

	vector < int > test1_poly1_coef;
	vector < int > test1_poly2_coef;
	vector < int > test1_poly3_coef;

	vector < double > test1_nodes1;
	vector < double > test1_nodes2;
	vector < double > test1_nodes3;

	test1_poly1_coef.push_back(2);
	test1_poly2_coef.push_back(2);
	test1_poly3_coef.push_back(1);

	IPOLY test1_poly1(test1_poly1_coef, 0);
	IPOLY test1_poly2(test1_poly2_coef, 0);
	IPOLY test1_poly3(test1_poly3_coef, 0);

	vector < IPOLY > test1_polys1;
	vector < IPOLY > test1_polys2;
	vector < IPOLY > test1_polys3;

	test1_polys1.push_back(test1_poly1);
	test1_polys2.push_back(test1_poly2);
	test1_polys3.push_back(test1_poly3);

	test1_nodes1.push_back(0);
	test1_nodes1.push_back(1);
	test1_nodes2.push_back(0);
	test1_nodes2.push_back(1);
	test1_nodes3.push_back(0);
	test1_nodes3.push_back(1);

	SPLINE test1_spline1(test1_polys1, test1_nodes1, 0);
	SPLINE test1_spline2(test1_polys2, test1_nodes2, 0);
	SPLINE test1_spline3(test1_polys3, test1_nodes3, 0);

	if (test1_spline1 / test1_spline2 == test1_spline3)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test1_spline1 / test1_spline2 << "\n";
		cout << test1_spline3 << "\n";
	}

	cout << " -> make test 2\n";

	vector < int > test2_poly1_coef;
	vector < int > test2_poly2_coef;

	vector < double > test2_nodes1;
	vector < double > test2_nodes2;

	test2_poly1_coef.push_back(2);
	test2_poly2_coef.push_back(2);

	IPOLY test2_poly1(test2_poly1_coef, 0);
	IPOLY test2_poly2(test2_poly2_coef, 0);

	vector < IPOLY > test2_polys1;
	vector < IPOLY > test2_polys2;

	test2_polys1.push_back(test2_poly1);
	test2_polys2.push_back(test2_poly2);

	test2_nodes1.push_back(0);
	test2_nodes1.push_back(1);
	test2_nodes2.push_back(2);
	test2_nodes2.push_back(3);

	SPLINE test2_spline1(test2_polys1, test2_nodes1, 0);
	SPLINE test2_spline2(test2_polys2, test2_nodes2, 0);
	SPLINE test2_spline3;

	if (test2_spline1 / test2_spline2 == test2_spline3)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test2_spline1 / test2_spline2 << "\n";
		cout << test2_spline3 << "\n";
	}
}

void SPLINE_Unit_Test::modTest()
{
	countTests += 2;

	cout << "make '%' test\n";

	cout << " -> make test 1\n";

	vector < int > test1_poly1_coef;
	vector < int > test1_poly2_coef;
	vector < int > test1_poly3_coef;

	vector < double > test1_nodes1;
	vector < double > test1_nodes2;
	vector < double > test1_nodes3;

	test1_poly1_coef.push_back(3);
	test1_poly2_coef.push_back(2);
	test1_poly3_coef.push_back(1);

	IPOLY test1_poly1(test1_poly1_coef, 0);
	IPOLY test1_poly2(test1_poly2_coef, 0);
	IPOLY test1_poly3(test1_poly3_coef, 0);

	vector < IPOLY > test1_polys1;
	vector < IPOLY > test1_polys2;
	vector < IPOLY > test1_polys3;

	test1_polys1.push_back(test1_poly1);
	test1_polys2.push_back(test1_poly2);
	test1_polys3.push_back(test1_poly3);

	test1_nodes1.push_back(0);
	test1_nodes1.push_back(1);
	test1_nodes2.push_back(0);
	test1_nodes2.push_back(1);
	test1_nodes3.push_back(0);
	test1_nodes3.push_back(1);

	SPLINE test1_spline1(test1_polys1, test1_nodes1, 0);
	SPLINE test1_spline2(test1_polys2, test1_nodes2, 0);
	SPLINE test1_spline3(test1_polys3, test1_nodes3, 0);

	if (test1_spline1 % test1_spline2 == test1_spline3)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test1_spline1 % test1_spline2 << "\n";
		cout << test1_spline3 << "\n";
	}

	cout << " -> make test 2\n";

	vector < int > test2_poly1_coef;
	vector < int > test2_poly2_coef;

	vector < double > test2_nodes1;
	vector < double > test2_nodes2;

	test2_poly1_coef.push_back(3);
	test2_poly2_coef.push_back(2);

	IPOLY test2_poly1(test2_poly1_coef, 0);
	IPOLY test2_poly2(test2_poly2_coef, 0);

	vector < IPOLY > test2_polys1;
	vector < IPOLY > test2_polys2;

	test2_polys1.push_back(test2_poly1);
	test2_polys2.push_back(test2_poly2);

	test2_nodes1.push_back(0);
	test2_nodes1.push_back(1);
	test2_nodes2.push_back(2);
	test2_nodes2.push_back(3);

	SPLINE test2_spline1(test2_polys1, test2_nodes1, 0);
	SPLINE test2_spline2(test2_polys2, test2_nodes2, 0);
	SPLINE test2_spline3;

	if (test2_spline1 % test2_spline2 == test2_spline3)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test2_spline1 % test2_spline2 << "\n";
		cout << test2_spline3 << "\n";
	}
}

void SPLINE_Unit_Test::valueTest()
{
	double eps = 1e-6;

	countTests += 3;

	cout << "make 'value()' test\n";

	cout << " -> make test 1\n";

	vector < int > test1_poly1_coef;

	vector < double > test1_nodes1;

	test1_poly1_coef.push_back(1);
	test1_poly1_coef.push_back(1);

	IPOLY test1_poly1(test1_poly1_coef, 0);

	vector < IPOLY > test1_polys1;

	test1_polys1.push_back(test1_poly1);

	test1_nodes1.push_back(0);
	test1_nodes1.push_back(3);

	SPLINE test1_spline1(test1_polys1, test1_nodes1, 0);

	double test1_point = 2;
	double test1_result = 3;

	if (abs(test1_spline1.value(test1_point) - test1_result) < eps)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test1_spline1.value(test1_point) << "\n";
		cout << test1_result << "\n";
	}

	cout << " -> make test 2\n";

	double test2_point = 4;
	double test2_result = 0;

	if (abs(test1_spline1.value(test2_point) - test2_result) < eps)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test1_spline1.value(test2_point) << "\n";
		cout << test1_result << "\n";
	}

	cout << " -> make test 3\n";

	SPLINE test3_spline1;

	if (abs(test3_spline1.value(test2_point) - test2_result) < eps)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test3_spline1.value(test2_point) << "\n";
		cout << test2_result << "\n";
	}
}
void SPLINE_Unit_Test::derivateTest()
{
	countTests += 1;

	cout << "make 'derivate()' test\n";

	cout << " -> make test 1\n";

	vector < int > test1_poly1_coef;
	vector < int > test1_poly2_coef;

	vector < double > test1_nodes1;
	vector < double > test1_nodes2;

	test1_poly1_coef.push_back(3);
	test1_poly1_coef.push_back(2);
	test1_poly2_coef.push_back(2);

	IPOLY test1_poly1(test1_poly1_coef, 0);
	IPOLY test1_poly2(test1_poly2_coef, 0);

	vector < IPOLY > test1_polys1;
	vector < IPOLY > test1_polys2;

	test1_polys1.push_back(test1_poly1);
	test1_polys2.push_back(test1_poly2);

	test1_nodes1.push_back(0);
	test1_nodes1.push_back(1);
	test1_nodes2.push_back(0);
	test1_nodes2.push_back(1);

	SPLINE test1_spline1(test1_polys1, test1_nodes1, 0);
	SPLINE test1_spline2(test1_polys2, test1_nodes2, 0);

	if (test1_spline1.derivate() == test1_spline2)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test1_spline1.derivate() << "\n";
		cout << test1_spline2 << "\n";
	}
}
void SPLINE_Unit_Test::integralTest()
{
	countTests += 1;

	cout << "make 'intedgral()' test\n";

	cout << " -> make test 1\n";

	vector < int > test1_poly1_coef;
	vector < int > test1_poly2_coef;

	vector < double > test1_nodes1;
	vector < double > test1_nodes2;

	test1_poly1_coef.push_back(2);
	test1_poly2_coef.push_back(0);
	test1_poly2_coef.push_back(2);

	IPOLY test1_poly1(test1_poly1_coef, 0);
	IPOLY test1_poly2(test1_poly2_coef, 0);

	vector < IPOLY > test1_polys1;
	vector < IPOLY > test1_polys2;

	test1_polys1.push_back(test1_poly1);
	test1_polys2.push_back(test1_poly2);

	test1_nodes1.push_back(0);
	test1_nodes1.push_back(1);
	test1_nodes2.push_back(0);
	test1_nodes2.push_back(1);

	SPLINE test1_spline1(test1_polys1, test1_nodes1, 0);
	SPLINE test1_spline2(test1_polys2, test1_nodes2, 0);

	if (test1_spline1.integral() == test1_spline2)
	{
		cout << "     -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "     -> result: FAILED\n\n";

		cout << test1_spline1.integral() << "\n";
		cout << test1_spline2 << "\n";
	}
}

void SPLINE_Unit_Test::makeTest()
{
	cout << "START UNIT TEST\n\n";

	addTest();
	multTest();
	difTest();
	divTest();
	modTest();
	valueTest();
	derivateTest();
	integralTest();

	cout << countTests << " test(s) passed (" << countPassed << " test(s) ACCEPTED, " << countTests - countPassed << " test(s) FAILED)\n";
}
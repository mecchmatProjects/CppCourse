#include "IPOLY_Unit_Test.h"



IPOLY_Unit_Test::IPOLY_Unit_Test()
{
}


IPOLY_Unit_Test::~IPOLY_Unit_Test()
{
}

void IPOLY_Unit_Test::addingTest()
{
	cout << "make '+' test:\n\n";
	cout << "-> make test 1 (same modul - true, modul overload - false)\n";

	countTests++;

	int modul1 = 0;
	vector < int > coefficient11;
	vector < int > coefficient21;
	vector < int > coefficient31;

	coefficient11.push_back(1);
	coefficient21.push_back(1);
	coefficient31.push_back(2);

	IPOLY A1(coefficient11, modul1);
	IPOLY B1(coefficient21, modul1);
	IPOLY C1(coefficient31, modul1);

	if(A1+B1 == C1)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      B      = " << B1 <<" (modul = " << B1.getModul() << ")\n";
		cout << "      A+B    = " << A1 + B1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      Answer = " << C1 << " (modul = " << C1.getModul() << ")\n\n";
	}									  

	cout << "-> make test 2 (same modul - true, modul overload - true)\n";

	countTests++;

	int modul2 = 3;
	vector < int > coefficient12;
	vector < int > coefficient22;
	vector < int > coefficient32;

	coefficient12.push_back(2);
	coefficient22.push_back(2);
	coefficient32.push_back(1);

	IPOLY A2(coefficient12, modul2);
	IPOLY B2(coefficient22, modul2);
	IPOLY C2(coefficient32, modul2);

	if(A2+B2 == C2)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A2 << " (modul = " << A2.getModul() << ")\n";
		cout << "      B      = " << B2 << " (modul = " << B2.getModul() << ")\n";
		cout << "      A+B    = " << A2 + B2 << " (modul = " << A2.getModul() << ")\n";
		cout << "      Answer = " << C2 << " (modul = " << C2.getModul() << ")\n\n";
	}

	cout << "-> make test 3 (same modul - false, modul overload - false)\n";

	countTests++;

	int modul31 = 3;
	int modul32 = 4;
	vector < int > coefficient13;
	vector < int > coefficient23;
	vector < int > coefficient33;

	coefficient13.push_back(1);
	coefficient23.push_back(1);
	coefficient33.push_back(2);

	IPOLY A3(coefficient13, modul31);
	IPOLY B3(coefficient23, modul32);
	IPOLY C3(coefficient33, modul31);

	if(A3+B3 == C3)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A3 << " (modul = " << A3.getModul() << ")\n";
		cout << "      B      = " << B3 << " (modul = " << B3.getModul() << ")\n";
		cout << "      A+B    = " << A3 + B3 << " (modul = " << A3.getModul() << ")\n";
		cout << "      Answer = " << C3 << " (modul = " << C3.getModul() << ")\n\n";
	}

	cout << "-> make test 4 (same modul - false, modul overload - true)\n";

	countTests++;

	int modul41 = 3;
	int modul42 = 4;
	vector < int > coefficient14;
	vector < int > coefficient24;
	vector < int > coefficient34;

	coefficient14.push_back(1);
	coefficient14.push_back(2);
	coefficient24.push_back(1);
	coefficient24.push_back(1);
	coefficient34.push_back(2);

	IPOLY A4(coefficient14, modul41);
	IPOLY B4(coefficient24, modul42);
	IPOLY C4(coefficient34, modul41);

	if(A4+B4 == C4)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A4 << " (modul = " << A4.getModul() << ")\n";
		cout << "      B      = " << B4 << " (modul = " << B4.getModul() << ")\n";
		cout << "      A+B    = " << A4 + B4 << " (modul = " << A4.getModul() << ")\n";
		cout << "      Answer = " << C4 << " (modul = " << C4.getModul() << ")\n\n";
	}
}

void IPOLY_Unit_Test::differenceTest()
{
	cout << "make '-' test:\n\n";
	cout << "-> make test 1 (same modul - true, modul overload - false)\n";

	countTests++;

	int modul1 = 0;
	vector < int > coefficient11;
	vector < int > coefficient21;
	vector < int > coefficient31;

	coefficient11.push_back(2);
	coefficient21.push_back(1);
	coefficient31.push_back(1);

	IPOLY A1(coefficient11, modul1);
	IPOLY B1(coefficient21, modul1);
	IPOLY C1(coefficient31, modul1);

	if (A1 - B1 == C1)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      B      = " << B1 <<" (modul = " << B1.getModul() << ")\n";
		cout << "      A-B    = " << A1 -  B1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      Answer = " << C1 << " (modul = " << C1.getModul() << ")\n\n";
	}									  

	cout << "-> make test 2 (same modul - true, modul overload - true)\n";

	countTests++;

	int modul2 = 4;
	vector < int > coefficient12;
	vector < int > coefficient22;
	vector < int > coefficient32;

	coefficient12.push_back(1);
	coefficient22.push_back(3);
	coefficient32.push_back(2);

	IPOLY A2(coefficient12, modul2);
	IPOLY B2(coefficient22, modul2);
	IPOLY C2(coefficient32, modul2);

	if (A2 - B2 == C2)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A2 << " (modul = " << A2.getModul() << ")\n";
		cout << "      B      = " << B2 << " (modul = " << B2.getModul() << ")\n";
		cout << "      A-B    = " << A2 - B2 << " (modul = " << A2.getModul() << ")\n";
		cout << "      Answer = " << C2 << " (modul = " << C2.getModul() << ")\n\n";
	}

	cout << "-> make test 3 (same modul - false, modul overload - false)\n";

	countTests++;

	int modul31 = 3;
	int modul32 = 4;
	vector < int > coefficient13;
	vector < int > coefficient23;
	vector < int > coefficient33;

	coefficient13.push_back(2);
	coefficient23.push_back(1);
	coefficient33.push_back(1);

	IPOLY A3(coefficient13, modul31);
	IPOLY B3(coefficient23, modul32);
	IPOLY C3(coefficient33, modul31);

	if (A3 - B3 == C3)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A3 << " (modul = " << A3.getModul() << ")\n";
		cout << "      B      = " << B3 << " (modul = " << B3.getModul() << ")\n";
		cout << "      A-B    = " << A3 - B3 << " (modul = " << A3.getModul() << ")\n";
		cout << "      Answer = " << C3 << " (modul = " << C3.getModul() << ")\n\n";
	}

	cout << "-> make test 4 (same modul - false, modul overload - true)\n";

	countTests++;

	int modul41 = 3;
	int modul42 = 4;
	vector < int > coefficient14;
	vector < int > coefficient24;
	vector < int > coefficient34;

	coefficient14.push_back(1);
	coefficient14.push_back(2);
	coefficient24.push_back(2);
	coefficient24.push_back(2);
	coefficient34.push_back(2);

	IPOLY A4(coefficient14, modul41);
	IPOLY B4(coefficient24, modul42);
	IPOLY C4(coefficient34, modul41);

	if (A4 - B4 == C4)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A4 << " (modul = " << A4.getModul() << ")\n";
		cout << "      B      = " << B4 << " (modul = " << B4.getModul() << ")\n";
		cout << "      A-B    = " << A4 - B4 << " (modul = " << A4.getModul() << ")\n";
		cout << "      Answer = " << C4 << " (modul = " << C4.getModul() << ")\n\n";
	}
}
void IPOLY_Unit_Test::multiplyingTest()
{
	cout << "make '*' test:\n\n";
	cout << "-> make test 1 (same modul - true, modul overload - false)\n";

	countTests++;

	int modul1 = 0;
	vector < int > coefficient11;
	vector < int > coefficient21;
	vector < int > coefficient31;

	coefficient11.push_back(2);
	coefficient21.push_back(1);
	coefficient31.push_back(2);

	IPOLY A1(coefficient11, modul1);
	IPOLY B1(coefficient21, modul1);
	IPOLY C1(coefficient31, modul1);

	if (A1 * B1 == C1)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      B      = " << B1 << " (modul = " << B1.getModul() << ")\n";
		cout << "      A*B    = " << A1 * B1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      Answer = " << C1 << " (modul = " << C1.getModul() << ")\n\n";   

	}

	cout << "-> make test 2 (same modul - true, modul overload - true)\n";

	countTests++;

	int modul2 = 4;
	vector < int > coefficient12;
	vector < int > coefficient22;
	vector < int > coefficient32;

	coefficient12.push_back(2);
	coefficient22.push_back(3);
	coefficient32.push_back(2);

	IPOLY A2(coefficient12, modul2);
	IPOLY B2(coefficient22, modul2);
	IPOLY C2(coefficient32, modul2);

	if (A2 * B2 == C2)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n"; 
		cout << "      A      = " << A2 << " (modul = " << A2.getModul() << ")\n";
		cout << "      B      = " << B2 << " (modul = " << B2.getModul() << ")\n";
		cout << "      A*B    = " << A2 * B2 << " (modul = " << A2.getModul() << ")\n";
		cout << "      Answer = " << C2 << " (modul = " << C2.getModul() << ")\n\n";
	}

	cout << "-> make test 3 (same modul - false, modul overload - false)\n";

	countTests++;

	int modul31 = 3;
	int modul32 = 4;
	vector < int > coefficient13;
	vector < int > coefficient23;
	vector < int > coefficient33;

	coefficient13.push_back(2);
	coefficient23.push_back(1);
	coefficient33.push_back(2);

	IPOLY A3(coefficient13, modul31);
	IPOLY B3(coefficient23, modul32);
	IPOLY C3(coefficient33, modul31);

	if (A3 * B3 == C3)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A3 << " (modul = " << A3.getModul() << ")\n";
		cout << "      B      = " << B3 << " (modul = " << B3.getModul() << ")\n";
		cout << "      A*B    = " << A3 * B3 << " (modul = " << A3.getModul() << ")\n";
		cout << "      Answer = " << C3 << " (modul = " << C3.getModul() << ")\n\n";
	}

	cout << "-> make test 4 (same modul - false, modul overload - true)\n";

	countTests++;

	int modul41 = 4;
	int modul42 = 6;
	vector < int > coefficient14;
	vector < int > coefficient24;
	vector < int > coefficient34;

	coefficient14.push_back(2);
	coefficient14.push_back(2);
	coefficient24.push_back(3);
	coefficient24.push_back(2);
	coefficient34.push_back(2);
	coefficient34.push_back(2);

	IPOLY A4(coefficient14, modul41);
	IPOLY B4(coefficient24, modul42);
	IPOLY C4(coefficient34, modul41);

	if (A4 * B4 == C4)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A4 << " (modul = " << A4.getModul() << ")\n";
		cout << "      B      = " << B4 << " (modul = " << B4.getModul() << ")\n";
		cout << "      A*B    = " << A4 * B4 << " (modul = " << A4.getModul() << ")\n";
		cout << "      Answer = " << C4 << " (modul = " << C4.getModul() << ")\n\n";
	}
}

void IPOLY_Unit_Test::dividingTest()
{
	cout << "make '/' test:\n\n";
	cout << "-> make test 1 (same modul - true, modul overload - false)\n";

	countTests++;

	int modul1 = 0;
	vector < int > coefficient11;
	vector < int > coefficient21;
	vector < int > coefficient31;

	coefficient11.push_back(4);
	coefficient11.push_back(4);
	coefficient11.push_back(1);
	coefficient21.push_back(2);
	coefficient21.push_back(1);
	coefficient31.push_back(2);
	coefficient31.push_back(1);

	IPOLY A1(coefficient11, modul1);
	IPOLY B1(coefficient21, modul1);
	IPOLY C1(coefficient31, modul1);

	if (A1 / B1 == C1)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      B      = " << B1 << " (modul = " << B1.getModul() << ")\n";
		cout << "      A/B    = " << A1 / B1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      Answer = " << C1 << " (modul = " << C1.getModul() << ")\n\n";

	}

	cout << "-> make test 2 (same modul - true, modul overload - false)\n";

	countTests++;

	int modul2 = 0;
	vector < int > coefficient12;
	vector < int > coefficient22;
	vector < int > coefficient32;

	coefficient12.push_back(2);
	coefficient22.push_back(3);

	IPOLY A2(coefficient12, modul2);
	IPOLY B2(coefficient22, modul2);
	IPOLY C2(coefficient32, modul2);

	if (A2 / B2 == C2)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A2 << " (modul = " << A1.getModul() << ")\n";
		cout << "      B      = " << B2 << " (modul = " << B1.getModul() << ")\n";
		cout << "      A/B    = " << A2 / B2 << " (modul = " << A1.getModul() << ")\n";
		cout << "      Answer = " << C2 << " (modul = " << C1.getModul() << ")\n\n";

	}
}

void IPOLY_Unit_Test::modTest()
{
	cout << "make '/' test:\n\n";
	cout << "-> make test 1 (same modul - true, modul overload - false)\n";

	countTests++;

	int modul1 = 0;
	vector < int > coefficient11;
	vector < int > coefficient21;
	vector < int > coefficient31;

	coefficient11.push_back(4);
	coefficient11.push_back(4);
	coefficient11.push_back(1);
	coefficient21.push_back(2);
	coefficient21.push_back(1);

	IPOLY A1(coefficient11, modul1);
	IPOLY B1(coefficient21, modul1);
	IPOLY C1(coefficient31, modul1);

	if (A1 % B1 == C1)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A      = " << A1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      B      = " << B1 << " (modul = " << B1.getModul() << ")\n";
		cout << "      A%B    = " << A1 % B1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      Answer = " << C1 << " (modul = " << C1.getModul() << ")\n\n";

	}
}

void IPOLY_Unit_Test::integralTest()
{
	cout << "make 'integrl()' test:\n\n";
	cout << "-> make test 1\n";

	countTests++;

	int modul1 = 0;
	vector < int > coefficient11;
	vector < int > coefficient21;

	coefficient11.push_back(1);
	coefficient11.push_back(2);
	coefficient21.push_back(0);
	coefficient21.push_back(1);
	coefficient21.push_back(1);

	IPOLY A1(coefficient11, modul1);
	IPOLY B1(coefficient21, modul1);

	if (A1.integral() == B1)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A.integral() = " << A1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      B            = " << B1 << " (modul = " << B1.getModul() << ")\n";
	}

	cout << "-> make test 2\n";

	countTests++;

	int modul2 = 0;
	vector < int > coefficient12;
	vector < int > coefficient22;

	coefficient12.push_back(0);
	coefficient12.push_back(0);
	coefficient12.push_back(1);

	IPOLY A2(coefficient12, modul2);
	IPOLY B2(coefficient22, modul2);

	if (A2.integral() == B2)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A.integral() = " << A2 << " (modul = " << A2.getModul() << ")\n";
		cout << "      B            = " << B2 << " (modul = " << B2.getModul() << ")\n";
	}
}

void IPOLY_Unit_Test::derivateTest()
{
	cout << "make 'derivate()' test:\n\n";
	cout << "-> make test 1\n";

	countTests++;

	int modul1 = 0;
	vector < int > coefficient11;
	vector < int > coefficient21;

	coefficient21.push_back(1);
	coefficient21.push_back(2);
	coefficient11.push_back(0);
	coefficient11.push_back(1);
	coefficient11.push_back(1);

	IPOLY A1(coefficient11, modul1);
	IPOLY B1(coefficient21, modul1);

	if (A1.derevative() == B1)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A.derivate() = " << A1 << " (modul = " << A1.getModul() << ")\n";
		cout << "      B            = " << B1 << " (modul = " << B1.getModul() << ")\n";
	}

	cout << "-> make test 2\n";

	countTests++;

	int modul2 =3;
	vector < int > coefficient12;
	vector < int > coefficient22;

	coefficient22.push_back(1);
	coefficient22.push_back(1);
	coefficient12.push_back(0);
	coefficient12.push_back(1);
	coefficient12.push_back(2);

	IPOLY A2(coefficient12, modul2);
	IPOLY B2(coefficient22, modul2);

	if (A2.derevative() == B2)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A.derivate() = " << A2 << " (modul = " << A1.getModul() << ")\n";
		cout << "      B            = " << B2 << " (modul = " << B1.getModul() << ")\n";
	}
}

void IPOLY_Unit_Test::valueTest()
{
	cout << "make 'value()' test:\n\n";
	cout << "-> make test 1\n";

	countTests++;

	int modul = 0;
	vector < int > coefficient;
	double result = 6.;
	double point = 2.;
	double eps = 1e-6;

	coefficient.push_back(0);
	coefficient.push_back(1);
	coefficient.push_back(1);

	IPOLY A(coefficient, modul);

	if (abs(A.value(point) - result) < eps)
	{
		cout << "   -> result: ACCEPTED\n\n";
		countPassed++;
	}
	else
	{
		cout << "   -> result: FAILD\n";
		cout << "      A.value(" << point << ") = " << A.value(point) << "\n";
		cout << "      Answer = "<< result << "\n";
	}
}

void IPOLY_Unit_Test::makeTest()
{
	cout << "START UNIT TESTS:\n\n";

	addingTest();
	differenceTest();
	multiplyingTest();
	dividingTest();
	modTest();
	integralTest();
	derivateTest();
	valueTest();

	cout << countTests << " test(s) finished (" << countPassed << " test(s) ACCEPTED, " << countTests - countPassed << " test(s) FAILED)\n\n";

	return;
}
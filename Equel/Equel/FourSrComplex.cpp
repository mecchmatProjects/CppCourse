#include "FourSrComplex.h"

using namespace std;

FourSrComplex::FourSrComplex()
{
	inputCoef();

	showX();
}


FourSrComplex::~FourSrComplex()
{
}


void FourSrComplex::ComputeABG()
{
	alpha = ((-3) * pow(b, 2)) / (8 * pow(a, 2)) + c / a;
	betta = ((pow(b, 3)) / (8 * pow(a, 3))) - ((b * c) / (2 * pow(a, 2))) + d / a;
	gamma = (((-3) * pow(b, 4)) / (256 * pow(a, 4))) + ((c * pow(b, 2)) / (16 * pow(a, 3))) - ((b * d) / (4 * pow(a, 2))) + e / a;
}


void FourSrComplex::inputCoef()
{
	cout << "Please enter A, and press 'Enter': " << endl;
	cin >> a;
	cout << "Please enter B, and press 'Enter': " << endl;
	cin >> b;
	cout << "Please enter C, and press 'Enter': " << endl;
	cin >> c;
	cout << "Please enter D, and press 'Enter': " << endl;
	cin >> d;
	cout << "Please enter E, and press 'Enter': " << endl;
	cin >> e;
}

void FourSrComplex::showX()
{
	if (betta == 0)
		{
		char* u1, * u2, * u3, * u4, * x1, * x2, * x3, * x4; //Попытка ввода числа i=sqrt(-1). Неудачно.
		char* i[1] = 'i';
		if ((pow(alpha, 2) - (4 * gamma)) >= 0)
			{
			if (((-alpha + sqrt(pow(alpha, 2) - (4 * gamma))) / 2) >= 0)
				{
				* u1 = sqrt((-alpha + sqrt(pow(alpha, 2) - (4 * gamma))) / 2);
				* u2 = (-1) * sqrt((-alpha + sqrt(pow(alpha, 2) - (4 * gamma))) / 2);
				* u3 = sqrt((-alpha - sqrt(pow(alpha, 2) - (4 * gamma))) / 2);
				* u4 = (-1) * sqrt((-alpha - sqrt(pow(alpha, 2) - (4 * gamma))) / 2);
				cout << *u1 << endl << *u2 << endl << *u3 << endl << *u4;
				}
			else
				{
				* u1 = "i" * sqrt((-1) * ((-alpha + sqrt(pow(alpha, 2) - (4 * gamma))) / 2));
				* u2 = (*i) * (-1) * sqrt((-1) * ((-alpha + sqrt(pow(alpha, 2) - (4 * gamma))) / 2));
				* u3 = (*i) * sqrt((-1) * ((-alpha - sqrt(pow(alpha, 2) - (4 * gamma))) / 2));
				* u4 = (*i) * (-1) * sqrt((-1) * ((-alpha - sqrt(pow(alpha, 2) - (4 * gamma))) / 2));
				cout << *u1 << endl << *u2 << endl << *u3 << endl << *u4;
				}
			}
		else
			{
			* u1 = sqrt((-alpha + sqrt(pow(alpha, 2) - (4 * gamma))) / 2);
			* u2 = (-1) * sqrt((-alpha + sqrt(pow(alpha, 2) - (4 * gamma))) / 2);
			* u3 = sqrt((-alpha - sqrt(pow(alpha, 2) - (4 * gamma))) / 2);
			* u4 = (-1) * sqrt((-alpha - sqrt(pow(alpha, 2) - (4 * gamma))) / 2);
			}
		* x1 = *u1 - (b / (4 * a));
		* x2 = *u2 - (b / (4 * a));
		* x3 = *u3 - (b / (4 * a));
		* x4 = *u4 - (b / (4 * a));
		cout << "The roots equalization pars: " << endl << endl;
		cout << "x_1= " << *x1 << endl;
		cout << "x_2= " << *x2 << endl;
		cout << "x_3= " << *x3 << endl;
		cout << "x_4= " << *x4 << endl;
		}
}
#include "LinearEq.h"
#include "SquareEq.h"
#include "CubEq.h"
#include "FourStEq.h"
#include <iostream>
#include <fstream>

void			show_menu();
int				choice();

int main()
{
	show_menu();

	return 0;
}

void show_menu()
{
	switch (choice())
	{
	case 1:
	{
		int answer;
		std::cout << "Input from:\n" << "1. Consol\n" << "2. Test File" << std::endl;
		while (!(std::cin >> answer))
		{
			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Try aganin: ";
		}
		//std::cin >> answer;
		if (answer == 1)
		{
			LinearEq* lin = new LinearEq();

			lin->showX();
		}
		else
		{
			if (answer == 2)
			{
				std::ifstream fin("testLin.txt");
				int n;
				fin >> n;
				for (int i = 0; i < n; i++)
				{
					double a, b;
					fin >> a >> b;

					std::cout << a << "x + " << b << " = 0" << std::endl;

					LinearEq* lin = new LinearEq(a, b);
					lin->showX();

					std::cout << "\n---------------" << std::endl;
				}
				fin.close();
			}
		}

		system("pause");
		system("cls");

		show_menu();

		return;
	}
	case 2:
	{
		int answer = 0;
		std::cout << "Input from:\n" << "1. Consol\n" << "2. Test File" << std::endl;
		while (!(std::cin >> answer))
		{
			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Try aganin: ";
		}
		//std::cin >> answer;
		if (answer == 1)
		{
			SquareEq* sq = new SquareEq();

			sq->showX();

		}
		else
		{
			if (answer == 2)
			{
				std::ifstream fin("testSq.txt");
				int n;
				fin >> n;
				for (int i = 0; i < n; i++)
				{
					double a, b, c;
					fin >> a >> b >> c;

					std::cout << a << "x^2 + " <<b << "x + " << c << std::endl;

					SquareEq* sq = new SquareEq(a, b, c);
					sq->showX();

					std::cout << "\n---------------" << std::endl;
				}
				fin.close();
			}
		}

		system("pause");
		system("cls");
		show_menu();
		return;
	}
	case 3:
	{
		int answer;
		std::cout << "Input from:\n" << "1. Consol\n" << "2. Test File" << std::endl;
		while (!(std::cin >> answer))
		{
			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Try aganin: ";
		}
		//std::cin >> answer;
		if (answer == 1)
		{
			CubEq* cb = new CubEq();

			cb->showX();

			int n;
			n = cb->getN();
			std::cout << "n = " << n;
		}
		else
		{
			if (answer == 2)
			{
				std::ifstream fin("test.txt");
				int n;
				fin >> n;
				for (int i = 0; i < n; i++)
				{
					double a, b, c, d;
					fin >> a >> b >> c >> d;

					std::cout << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << std::endl;

					CubEq* cb = new CubEq(a, b, c, d);
					cb->showX();

					std::cout << "\n---------------" << std::endl;
				}
				fin.close();
			}
		}


		

		system("pause");
		system("cls");
		show_menu();
		return;
	}
	case 4:
	{
		int answer;
		std::cout << "Input from:\n" << "1. Consol\n" << "2. Test File" << std::endl;
		while (!(std::cin >> answer))
		{
			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Try aganin: ";
		}
		//std::cin >> answer;
		if (answer == 1)
		{
			FourStEq* fs = new FourStEq();

			fs->showX();
		}
		else
		{
			if (answer == 2)
			{
				std::ifstream fin("testFs.txt");
				int n;
				fin >> n;
				for (int i = 0; i < n; i++)
				{
					double a, b, c, d, e;
					fin >> a >> b >> c >> d >> e;

					std::cout << a << "x^4 + " << b << "x^3 + " << c << "x^2 + " << d << "x + " << e << std::endl;

					FourStEq* fs = new FourStEq(a, b, c, d, e);
					fs->showX();

					std::cout << "\n---------------" << std::endl;
				}
				fin.close();
			}
		}

		system("pause");
		system("cls");
		show_menu();
		return;
	}
	case 5:
	{
		return;
	}
	default:
		return;
	}
}

int choice()
{
	bool answer = false;
	do
	{
		std::cout << "\t\t\tMenu\n\n";
		std::cout << "All tasks:\n" << "\t1. Linear equation \n" << "\t2. Square equation \n" << "\t3. Cube equation \n" << "\t4. 4-th equation \n" << "\t5. Exit\n" << std::endl;
		std::cout << "Please, enter your choice (1-5): ";
		int choice;

		while (!(std::cin >> choice))
		{
			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Try aganin: ";
		}

		switch (choice)
		{
		case 1: return 1;
		case 2: return 2;
		case 3: return 3;
		case 4: return 4;
		case 5: return 5;
		default: answer = true; system("cls"); break;
		}
	} while (answer);

	return -1;
}


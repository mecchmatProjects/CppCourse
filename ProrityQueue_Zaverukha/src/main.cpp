#include "../headers/PriorityQueue.h"
#include <iostream>
#include <string>
#include <sstream>
#include "../tests/tests.h"

using namespace std;

int main()
{
	string c[2] = { "add", "pop" };
	vector<string> commands(c, c+2);
	PriorityQueue queue;
	if (tests::test_insert() && tests::test_pop_and_order(1000))
		cout << "tests: OK\n";
	else
	{
		cout << "tests failed";
	}
	while (true)
	{
		
		try
		{
			string input;
			std::getline(cin, input);
			stringstream sin(input);
			string command;
			sin >> command;
			if (command == "add")
			{
				string surname;
				int time, sum;
				sin >> surname >> time >> sum;
				queue.insert(Customer(surname, time, sum));
			}
			else if (command == "trigger")
			{
				int sum;
				sin >> sum;
				vector<Customer> popped;
				popped = queue.trigger(sum);
				cout << "list of triggered:\n";
				for (int i = 0; i < popped.size(); ++i)
				{
					cout << popped[i].get_data() << '\n';
				}
			}
			else if (command == "pop")
			{
				Customer popped = queue.pop();
				if (popped.get_data() == "-1 -1 -1")
				{
					cout << "queue is empty\n";

				}
				else
				{
					cout << popped.get_data() << '\n';
				}
			}
			else
			{
				cout << "wrong command\n";
			}
		}
		catch (const std::exception&)
		{
			cout << "incorrect input\n";
		}
	}
}
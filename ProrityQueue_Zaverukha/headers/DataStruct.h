#pragma once
#include <vector>
#include <array>
#include <string>

using std::vector;
using std::array;
using std::string;

struct Customer
{
	string surname;
	int time;
	int sum;
	Customer() {};
	Customer(string surname, int time, int sum) : surname(surname), time(time), sum(sum) {};
	bool operator<(Customer other)
	{
		int t1 = this->time;
		int t2 = other.time;
		return t1 > t2;
	}
	string get_data()
	{
		return surname + " " + std::to_string(time) + " " + std::to_string(sum);
	}
};

class DataStruct
{	
private:
public:
	explicit DataStruct(vector<Customer> v) {};
	explicit DataStruct(Customer* v, size_t n) {};
	explicit DataStruct(size_t n) {};
	explicit DataStruct() {};

	virtual bool insert(Customer item) = 0;
	virtual bool swap(Customer customer_1, Customer customer_2) = 0;
	virtual vector<Customer> trigger(int sum) = 0;
	virtual Customer pop() = 0;
	virtual bool is_present(Customer customer) = 0;
	virtual bool is_empty() = 0;
	virtual ~DataStruct() {};
};


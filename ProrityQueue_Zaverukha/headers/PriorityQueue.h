#pragma once
#include <vector>
#include <array>
#include <string>
#include <set>
#include "DataStruct.h"

using std::vector;
using std::array;
using std::string;
using std::set;



inline bool operator<(Customer x, Customer y)
{
	return x.time > y.time;
}

class PriorityQueue : public DataStruct
{
private:
	set<Customer> customers;
public:
	
	PriorityQueue(vector<Customer> v);
	PriorityQueue(Customer* v, size_t n);
	PriorityQueue(size_t n);
	PriorityQueue();

	bool insert(Customer item);
	bool insert(PriorityQueue items);
	bool intersection(PriorityQueue items);
	bool swap(Customer customer_1, Customer customer_2);
	vector<Customer> trigger(int sum);
	Customer pop();
	bool is_present(Customer customer);
	bool is_empty();



	~PriorityQueue();
};


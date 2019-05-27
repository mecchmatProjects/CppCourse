#include "../headers/PriorityQueue.h"



Customer PriorityQueue::pop()
{
	try
	{
		if (!is_empty())
		{
			Customer item = *(customers.begin());
			customers.erase(*(customers.begin()));
			return item;
		}
		else
		{
			return Customer("-1", -1, -1);
		}
		
	}
	catch (const std::exception&)
	{

	}
	
}

bool PriorityQueue::is_present(Customer customer)
{
	return (customers.find(customer) != customers.end());
}

PriorityQueue::PriorityQueue(vector<Customer> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		insert(v[i]);
	}
}

PriorityQueue::PriorityQueue(Customer * v, size_t n)
{
	for (int i = 0; i < n; ++i)
	{
		insert(v[i]);
	}
}

PriorityQueue::PriorityQueue(size_t n)
{
	for (int i = 0; i < n; ++i)
	{
		insert(Customer(std::to_string(rand()), rand(), rand()));
	}
}

PriorityQueue::PriorityQueue()
{
}

bool PriorityQueue::insert(Customer item)
{
	try
	{
		customers.insert(item);
	}
	catch (const std::exception&)
	{

		return false;
	}
	return true;
}

bool PriorityQueue::insert(PriorityQueue items)
{
	try
	{
		for (set<Customer>::iterator iter = items.customers.begin(); iter != items.customers.end(); ++iter)
		{
			Customer item = *iter;
			insert(item);
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool PriorityQueue::intersection(PriorityQueue items)
{
	try
	{
		set<Customer> new_queue;
		for (set<Customer>::iterator iter = items.customers.begin(); iter != items.customers.end(); ++iter)
		{
			Customer item = *iter;
			if (is_present(item))
			{
				new_queue.insert(item);
			}
		}
		customers = new_queue;
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

bool PriorityQueue::swap(Customer customer_1, Customer customer_2)
{
	try
	{
		if (is_present(customer_1) && is_present(customer_2))
		{
			customers.erase(customer_1);
			customers.erase(customer_2);
			int time_1 = customer_1.time;
			customer_1.time = customer_2.time;
			customer_2.time = time_1;
			insert(customer_1);
			insert(customer_2);

		}
		else
		{
			return false;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
	return false;
}

vector<Customer> PriorityQueue::trigger(int sum)
{
	vector<Customer> popped;
	while (!customers.empty())
	{
		Customer front = *(customers.begin());
		if (front.sum > sum)
		{
			popped.push_back(front);
			customers.erase(front);
		}
		else
		{
			break;
		}
	}
	return  popped;
}

bool PriorityQueue::is_empty()
{
	return customers.empty();
}


PriorityQueue::~PriorityQueue()
{
}

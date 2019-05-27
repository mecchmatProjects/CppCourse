#include "../headers/PriorityQueue.h"
#include <algorithm>

namespace tests
{
	bool test_pop_and_order(int n)
	{
		PriorityQueue queue(n);
		Customer prev = queue.pop();
		for (int i = 1; i < n && queue.is_empty(); ++i)
		{
			Customer cur = queue.pop();
			if (cur.time > prev.time)
			{
				return false;
			}
		}
		return true;
	}

	

	bool test_pop_untill_empty(PriorityQueue &queue)
	{
		Customer prev;
		if (!queue.is_empty())
		{
			prev = queue.pop();
		}
		while (!queue.is_empty())
		{
			Customer cur = queue.pop();
			if (cur.time > prev.time)
			{
				return false;
			}
		}
		return true;
	}

	bool test_insert()
	{
		PriorityQueue queue;
		Customer customer_1("1", 1, 1), customer_2("1", 2, 1), customer_3("1", 3, 1), customer_4("1", 4, 1);
		queue.insert(customer_1);
		queue.insert(customer_2);
		queue.insert(customer_3);
		queue.insert(customer_4);

		if (!(queue.is_present(customer_1) && queue.is_present(customer_2) && queue.is_present(customer_3) && queue.is_present(customer_4)))
		{
			return false;
		}

		return test_pop_untill_empty(queue);
	}
}
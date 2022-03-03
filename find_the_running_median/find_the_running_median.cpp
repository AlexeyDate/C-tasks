/*
	https://www.hackerrank.com/challenges/find-the-running-median/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_min_heap(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	int value;
	double mid;
	vector<int> min_heap;
	vector<int> max_heap;

	cin >> n;
	
	cin >> value;
	mid = value;
	min_heap.push_back(value);
	push_heap(min_heap.begin(), min_heap.end(), cmp_min_heap);
	cout << mid << endl;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> value;

		if (value > mid)
		{
			if (static_cast<int>(min_heap.size()) - static_cast<int>(max_heap.size()) > 0)
			{
				max_heap.push_back(min_heap[0]);
				push_heap(max_heap.begin(), max_heap.end());
				pop_heap(min_heap.begin(), min_heap.end(), cmp_min_heap);
				min_heap.pop_back();
			}

			min_heap.push_back(value);
			push_heap(min_heap.begin(), min_heap.end(), cmp_min_heap);
		}
		else
		{
			if (static_cast<int>(max_heap.size()) - static_cast<int>(min_heap.size()) > 0)
			{
				min_heap.push_back(max_heap[0]);
				push_heap(min_heap.begin(), min_heap.end(), cmp_min_heap);
				pop_heap(max_heap.begin(), max_heap.end());
				max_heap.pop_back();
			}

			max_heap.push_back(value);
			push_heap(max_heap.begin(), max_heap.end());
		}

		if (max_heap.size() == min_heap.size())
		{
			mid = static_cast<double>(max_heap[0] + min_heap[0]) / 2;
		}

		if (max_heap.size() > min_heap.size())
		{
			mid = max_heap[0];
		}

		if (max_heap.size() < min_heap.size())
		{
			mid = min_heap[0];
		}

		cout << mid << endl;
	}

	return 0;
}


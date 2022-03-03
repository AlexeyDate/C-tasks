#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	int all;
	int size;
	int subarrays;
	int value;
	deque<int> deq;

	cin >> all;

	for (int i = 0; i < all; i++)
	{
		cin >> size >> subarrays;
		deq.clear();

		for (int j = 0; j < size; j++)
		{
			cin >> value;
			deq.push_back(value);
		}

		int max = 1;
		int max_it = 0;
		int k;
		for (int j = 0; j < size; j++)
		{ 
			if (j - subarrays == max_it)
			{
				max = 1;
				k = max_it + 1;
				for (; k < j; k++)
				{
					if (deq[k] > max)
					{
						max = deq[k];
						max_it = k;
					}
				}
			}

			if (deq[j] > max)
			{
				max = deq[j];
				max_it = j;
			}

			if (j >= subarrays - 1)
			{
				cout << max << ' ';
			}
		}
		cout << endl;
	}
	
	return 0;
}

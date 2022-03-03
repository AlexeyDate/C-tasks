/*
A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. 
Given an integer, d, rotate the array that many steps left and return the result.
*/

#include <iostream>
#include <array>
using namespace std;


int main()
{
	int d, n;
	int temp_value;
	const int SIZE = 100000;

	cin >> n >> d;

	array<int,SIZE> arr;

	for (array<int, SIZE>::iterator it = arr.begin(); it != arr.begin() + n; it++)
	{
		cin >> *it;
	}

	for (int i = 0; i < d; i++)
	{
		temp_value = *arr.begin();
		for (array<int, SIZE>::iterator it = arr.begin(); it != arr.begin() + n; it++)
		{
			*it = *(it + 1);
		}
		*(arr.begin() + n - 1) = temp_value;
	}

	for (array<int,SIZE>::const_iterator it = arr.cbegin(); it != arr.cbegin() + n; it++)
	{
		cout << *it << ' ';
	}

	return 0;
}

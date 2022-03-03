#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n;
	bool error;
	char inv_s;

	string s;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		error = false;
		stack<char> brackets; // [ { (
		for (int j = 0; j < s.length(); j++)
		{
			brackets.push(s[j]);
			if (s[j] == '}') inv_s = '{';
			if (s[j] == ')') inv_s = '(';
			if (s[j] == ']') inv_s = '[';

			if (brackets.top() == '}' || brackets.top() == ')' || brackets.top() == ']')
			{
				brackets.pop();
				if (brackets.empty())
				{
					error = true;
					break;
				}

				if (brackets.top() != inv_s)
				{
					error = true;
					break;
				}
				brackets.pop();
			}

		}
		
		if (brackets.empty() && !error)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}


	return 0;
}


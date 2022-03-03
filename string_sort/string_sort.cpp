/*
С помощью объектов и методов std::string, std::vector написать программу,
которая принимала бы на вход строку(последовательность символов, не содержащую символов перевода строки)
и выводила бы в качестве результата текст, состоящий из тех же самых слов, что и исходная строка,
но которые следуют в порядке возрастания длины слова.За слово считается любая последовательность не - пробелов.
Слова в исходном тексте могут быть разделены несколькими пробелами, но в выходном тексте достаточно одного.

Пример:  “C++ is a very performant language.\n”  ->
		 “a is C++ very language.performant”
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int min(vector<int> vec)
{
	int res = INT_MAX;
	int pos = -1;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] < res && vec[i] > 0)
		{
			res = vec[i];
			pos = i;
		}
	}

	return pos;
}

int main()
{
	string s;
	string out;
	vector<int> s_length;
	
	int start = 0;
	int end = 0;

	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			end++;
		}
		else
		{
			if (start != end)
			{
				s_length.push_back(end - start);
			}
			start = i;
			end = i;
		}
	}
	s_length.push_back(end - start);

	int j;
	int it;
	int current_it;
	for (int i = 0; i < s_length.size(); i++)
	{
		it = min(s_length);
		s_length[it] = -1;

		current_it = 0;
		start = 0;
		end = 0;
		for (j = 0; j < s.length(); j++)
		{
			if (s[j] != ' ')
			{
				end++;
			}

			else 
			{
				if (start != end)
				{
					if (current_it == it)
					{
						if (it != 0) out.append(s, start + 1, end - start);
						if (it == 0) out.append(s, start, end - start);

						out += ' ';
						break;
					}
					current_it++;
				}

				start = j;
				end = j;
			}
		}

		if (j == s.length())
		{
			if (it != 0) out.append(s, start + 1, end - start);
			if (it == 0) out.append(s, start, end - start);

			out += ' ';
		}
	}

	cout << out << endl;

	return 0;
}
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int size_1;
    int size_2;
    int size_3;
    int value;
    stack<int> st_1;
    stack<int> st_2;
    stack<int> st_3;

    cin >> size_1;
    cin >> size_2;
    cin >> size_3;

    for (int i = 0; i < size_1; i++)
    {
        cin >> value;
        st_1.push(value);
    }

    for (int i = 0; i < size_2; i++)
    {
        cin >> value;
        st_2.push(value);
    }

    for (int i = 0; i < size_3; i++)
    {
        cin >> value;
        st_3.push(value);
    }

    int h1 = 0;
    int h2 = 0;
    int h3 = 0;
    int temp_val = 0;
    int max_val = 0;

    temp_val = st_1.top();
    for (int j = 0; j < (size_1 + size_2 + size_3) - 2; j++)
    {
        if (!st_1.empty())
        {
            if (h1 + st_1.top() <= temp_val)
            {
                h1 += st_1.top();
                st_1.pop();
            }

            else if (h1 + st_1.top() > temp_val && h1 != temp_val)
            {
                h1 += st_1.top();
                st_1.pop();
                temp_val = h1;
            }
        }

        if (!st_2.empty())
        {
            if (h2 + st_2.top() <= temp_val)
            {
                h2 += st_2.top();
                st_2.pop();
            }

            else if (h2 + st_2.top() > temp_val && h2 != temp_val)
            {
                h2 += st_2.top();
                st_2.pop();
                temp_val = h2;
            }
        }

        if (!st_3.empty())
        {
            if (h3 + st_3.top() <= temp_val)
            {
                h3 += st_3.top();
                st_3.pop();
            }

            else if (h3 + st_3.top() > temp_val && h3 != temp_val)
            {
                h3 += st_3.top();
                st_3.pop();
                temp_val = h3;
            }
        }


        if (h1 == temp_val && h2 == temp_val && h3 == temp_val)
        {
            max_val = temp_val;
            if (!st_1.empty())  temp_val += st_1.top();
            else if (!st_2.empty()) temp_val += st_2.top();
            else if (!st_3.empty()) temp_val += st_3.top();
        }


    }

    cout << max_val << endl;

    return 0;
}


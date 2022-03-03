#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int size;
    int value;
    vector<int> data;

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> value;
        data.push_back(value);
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        vector<int>::const_iterator it = lower_bound(data.cbegin(), data.cend(), value);
        
        if (*it == value)
        {
            cout << "Yes ";
        }
        else
        {
            cout << "No ";
        }
        cout << it - data.cbegin() + 1 << endl;
    }

    return 0;
}



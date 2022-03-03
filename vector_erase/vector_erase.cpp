#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int x;
    int a, b;
    vector<int> vec;

    cin >> n;
    vec.resize(n);

    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cin >> *it;
    }
    
    cin >> x;
    vec.erase(vec.begin() + x - 1, vec.begin() + x);

    cin >> a >> b;
    vec.erase(vec.begin() + a - 1, vec.begin() + b - 1);

    cout << vec.size() << endl;
    for (vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); it++)
    {
        cout << *it << ' ';
    }
    
    return 0;
}



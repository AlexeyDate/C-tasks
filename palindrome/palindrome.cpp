#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int j = s.length() - 1;
    for (int i = 0; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            cout << "Is not palindrome" << endl;
            return -1;
        }
    }

    cout << "Palindrome!" << endl;

    return 0;
}


/*
С использованием итераторов написать функцию, 
удаляющую из вектора целых чисел все нулевые элементы и подгоняющую его результирующую емкость (capacity)
к его результирующему размеру (size).
*/

#include <iostream>
#include <vector>
using namespace std;

void del_null(vector<int>& v)
{
    int size = 0;
    vector<int> copy_v;
    vector<int>::iterator it = v.begin();

    for (; it != v.end(); it++)
    {
         if (*it != 0)
         {
             size++;
             copy_v.push_back(*it);
         }
    }

    copy_v.shrink_to_fit();
    v.clear();
    v.shrink_to_fit();
    v = copy_v;
}

int main()
{
    vector<int> vec = {1,2,0,4,5,0,6,7,8,0,0};

    for (auto a : vec)
    {
        cout << a << ' ';
    }

    cout << endl << "size: " << vec.size() << endl << "capacity: " << vec.capacity() << endl << endl;

    del_null(vec);

    for (auto a : vec)
    {
        cout << a << ' ';
    }

    cout << endl << "size: " << vec.size() << endl << "capacity: " << vec.capacity() << endl;

    return 0;
}


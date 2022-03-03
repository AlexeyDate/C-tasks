// Виртуальный дестркутор

#include <iostream>
using namespace std;

class Base
{
private:
    char* m_buf;
public:
    Base() { m_buf = new char[40]; }
    virtual ~Base() { delete[] m_buf; cout << "Base\n"; }
};

class Derived : public Base
{
private:
    int* m_int_buf;
public:
    Derived() { m_int_buf = new int[40]; }
    ~Derived() override { delete[] m_int_buf; cout << "Derived\n"; }
};


int main()
{
    Base* p_base = new Base();
    Derived* p_derived = new Derived();
    Base* p_upcast = (Base*)p_derived;

   // delete p_base;
    delete p_upcast;

    return 0;
}


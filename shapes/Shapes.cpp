//virtual func

#include <iostream>
using namespace std;

class shape
{
protected:
	int uid;
	static int count;
public:
	virtual void aboutShape() = 0;
};

int shape::count = 0;

class circle : public shape
{
private:
	int r;
public:
	
	circle(int r)
	{
		this->r = r; 
		uid = count;
		count++;
	}

	void aboutShape()
	{
		cout << "Result: " << 2 * 3.14 * r << "\nShape id: " << uid << endl;
	}
};

class rectangle : public shape
{
private:
	int w, h;
public:

	rectangle(int w, int h)
	{
		this->w = w;
		this->h = h;
		uid = count;
		count++;
	}

	void aboutShape()
	{
		cout << "Result: " << w * h << "\nShape id: " << uid << endl;
	}
};

int main()
{
	shape* sh;
	circle* cl = new circle(4);
	rectangle* rec = new rectangle(3, 4);

	sh = static_cast<shape*>(cl);
	sh->aboutShape();

	sh = static_cast<shape*>(rec);
	sh->aboutShape();

	return 0;
}

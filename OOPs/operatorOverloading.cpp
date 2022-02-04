#include<bits/stdc++.h>
using namespace std;

class demo{

	int x;

public:

	demo(int y)
	{
		x=y;
	}

	void operator ++() //operator overloading 1
	{
		x++;
	}

	void operator +(demo d) // operator overloading 2
	{
		x=x+d.x;
	}

	void display()
	{
		cout<<x<<endl;
	}

};

int main()
{

	demo d(20);
	demo d1(21);

	d.display();
	d1.display();

	++d; // operator overloading 1
	d.display();

	d1+d; // operator overloading 2 -- the object written second will become the argument
	d1.display();

	return 0;
}

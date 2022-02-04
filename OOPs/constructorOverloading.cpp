#include<bits/stdc++.h>
using namespace std;

class Complex{
	int x,y;
public:
	Complex(int a,int b)
	{
		x=a;
		y=b;
	}
	Complex(int a)
	{
		x=a;
		y=-1;
	}

	void printData()
	{
		cout<<x<<" "<<y<<endl;
	}
};

int main()
{
	Complex c1(2,3);
	Complex c2(5);

	c1.printData();
	c2.printData();

	return 0;
}

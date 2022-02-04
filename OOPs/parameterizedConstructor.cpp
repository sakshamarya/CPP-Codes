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

	void printData()
	{
		cout<<x<<" "<<y<<endl;
	}
};

int main()
{

	Complex c1(2,3); // implicit call
	Complex c2 = Complex(4,5); // explicit call

	c1.printData();
	// c2.printData();

	return 0;
}

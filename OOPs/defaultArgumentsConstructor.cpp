#include<bits/stdc++.h>
using namespace std;

class Complex{
	int x,y,z;
public:

	// we cannot use the below three constructors together because they will give ambiguity

	// Complex(int a,int b,int c)
	// {
	// 	x=a;
	// 	y=b;
	// 	z=c;
	// }
	Complex(int a,int b,int c=-1)
	{
		cout<<"hello1"<<endl;
		x=a;
		y=b;
		z=c;
	}
	// Complex(int a)
	// {
	// 	x=a;
	// 	y=-1;
	// 	z=-1;
	// }
	Complex(int a,float b,int c=-1)
	{
		cout<<"hello2"<<endl;
		x=a;
		y=b;
		z=c;
	}

	void printData()
	{
		cout<<x<<" "<<y<<" "<<z<<endl;
	}
};

int main()
{
	Complex c1(2,3);
	// Complex c2(2,3.0); // gives ambiguity error since compiler is not able to decide what constructer it has to choose
	Complex c2(2,float(3.0)); // works fine since we have already told the compiler that we have inserted a floating argument

	// Complex c3; // gives error since we haven't created any default constructor

	c1.printData();
	c2.printData();

	return 0;
}

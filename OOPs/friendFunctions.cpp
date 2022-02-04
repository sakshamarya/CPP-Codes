// A friend function of a class is a function that has the permission to access the private data members of a class.

#include<bits/stdc++.h>
using namespace std;


class Complex{

	int a,b;

public:

	void setNumber(int x,int y) // a setter
	{
		a=x;
		b=y;
	}

	void printNumber()
	{
		cout<<a<<" + i"<<b<<endl;
	}

	friend Complex sumOfComplexNumbers(Complex n1,Complex n2); // declaring sumOfComplexNumbers as a friend function

};

Complex sumOfComplexNumbers(Complex n1,Complex n2)
{

	Complex n3;

	n3.a=n1.a+n2.a; // a is a private member of complex class
	n3.b=n1.b+n2.b; // b is a private member of complex class

	return n3;
}


int main()
{

	Complex n1,n2;
	n1.setNumber(1,2);
	n2.setNumber(2,3);

	Complex n3= sumOfComplexNumbers(n1,n2);
	n3.printNumber();

	return 0;
}


// Properties
// --> friend function can be also declared in private section of the class
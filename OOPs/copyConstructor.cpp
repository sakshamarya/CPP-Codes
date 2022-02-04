#include<bits/stdc++.h>
using namespace std;

class Number{
	int x;
public:
	Number()
	{
		x=0;
	}
	Number(int a)
	{
		x=a;
	}
	Number(Number& a)
	{
		cout<<"Hello from copy constructor"<<endl;
		x=a.x;
	}

	void display()
	{
		cout<<x<<endl;
	}
};

int main()
{

	Number n1,n2(10);
	Number n3(n2); // copy constructor is invoked

	n1.display();
	n2.display();
	n3.display();

	Number n4;
	n4=n3; // copy constructor is not invoked

	n4.display();

	Number n5=n3; // here, the copy constructor will be invoked

	n5.display();

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

class A{

	int a;
public:

	A(int a)
	{
		this->a=a;
	}

	A func()
	{
		return (*this);
	}

	int getdata()
	{
		return this->a;
	}
};


int main()
{
	A a1(10);
	A a2=a1.func();

	cout<<a2.getdata();

	return 0;
}

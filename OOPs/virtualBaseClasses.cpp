#include<bits/stdc++.h>
using namespace std;

class A{
public:
	int a=10;
};

class B: virtual public A{

};


class C: virtual public A{

};

class D: public B, public C{

public:
	void show()
	{
		cout<<a<<endl;
	}

};


int main()
{

	D obj;
	obj.show();

	return 0;
}

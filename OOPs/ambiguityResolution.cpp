#include<bits/stdc++.h>
using namespace std;

class base1{

public:
	void say()
	{
		cout<<"base1"<<endl;
	}
};


class base2{
public:
	void say()
	{
		cout<<"base2"<<endl;
	}
};

class derived: public base1, public base2{

public:
	void say()
	{
		base2::say(); // this will resolve the ambiguity on calling derived.say()
	}

};

int main()
{

	derived d;
	d.say();

	return 0;
}

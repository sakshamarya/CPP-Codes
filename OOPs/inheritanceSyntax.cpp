#include<bits/stdc++.h>
using namespace std;

class Animals{

public:
	string type;
	Animals(string s)
	{
		type=s;
	}

	void display1()
	{
		cout<<type<<endl;
	}

	Animals()
	{
		cout<<"inside animal constructor"<<endl;
	}

};

class Birds : public Animals{

	string name;
public:
	Birds(string s,string s1)
	{
		name=s;
		type=s1;
	}	

	void display()
	{
		cout<<name<<endl;
	}
};

int main()
{

	Animals a1("Bird");
	Birds b1("sparrow","Bird");

	b1.display1();



	return 0;
}

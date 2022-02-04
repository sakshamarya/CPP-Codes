#include<bits/stdc++.h>
using namespace std;

class class_1;

class class_2{

public:
	int sum(class_1);
};

class class_1{

	int x,y;
	// friend int class_2::sum(class_1); // declaring friend function
	friend class class_2;  // declaring friend class
	

public:
	class_1(int a,int b)
	{
		x=a;
		y=b;
	}
};



int class_2::sum(class_1 temp)
{
	return temp.x+temp.y;
}	


int main()
{

	class_1 temp1(2,3);

	class_2 temp2;

	cout<<temp2.sum(temp1);

	return 0;
}

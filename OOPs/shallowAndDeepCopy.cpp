#include<bits/stdc++.h>
using namespace std;

// studies from saurav shukla sir video

class dummy{

	int x,y,*p;

public:
	dummy(int a,int b,int c){
		x=a;
		y=b;
		p=new int;
		*p=c;
	}

	// dummy(dummy &d) // User defined constructor -- deep copy
	// {
	// 	x=d.x;
	// 	y=d.y;
	// 	p=new int;
	// 	*p=*(d.p);
	// }

	void setter(int a,int b,int c)
	{
		x=a;
		y=b;
		*p=c;
	}
	void display()
	{
		cout<<x<<" "<<y<<" "<<*p<<endl;
	}
};

int main()
{

	dummy a(2,3,4);
	dummy b=a;

	a.display();
	b.display();

	a.setter(4,5,8);

	a.display();
	b.display();

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

float add(float a,int b)
{
	cout<<"2 arguments float function"<<endl;
	return a+b;
}

int add(int a,int b)
{
	cout<<"2 arguments"<<endl;
	return a+b;
}

int add(int a,int b,int c)
{

	cout<<"3 arguments"<<endl;
	return a+b+c;
}

int volume(double r,double h)
{
	return (3.14)*(r*r)*h;
}

int volume(int a)
{
	return a*a*a;
}

int volume(int l,int b)
{
	return (l*b);
}


int main()
{

	//cout<<add(3.0,6)<<endl; // this is giving ambiguous error 
	cout<<add(3,6)<<endl;
	cout<<add(3,4,5)<<endl;

	cout<<"vol of cube "<<volume(3)<<endl;
	cout<<"vol of cuboid "<<volume(2,3)<<endl;
	cout<<"vol of cylinder "<<volume(2,3)<<endl;

	return 0;
}

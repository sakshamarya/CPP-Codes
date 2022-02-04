#include<bits/stdc++.h>
using namespace std;

class A{

	int a1,a2;
public:
	A(){
		cout<<"A constructor"<<endl;
	}
};

class B{
	int b1,b2;
public:
	B(){
		cout<<"B constructor"<<endl;
	}
};

class C: public A, virtual public B{ // since b has been inherited virtually, it's constructor will be invoked first

	int c1,c2;
public:
	C(){
		cout<<"C constructor"<<endl;
	}
};

int main()
{

	C obj;

	return 0;
}

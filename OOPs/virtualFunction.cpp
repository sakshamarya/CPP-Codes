#include<iostream>
using namespace std;
class BaseClass{
    public:
        int var_base;
        virtual void display(){
            cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public:
            int var_derived;
            void display(){
                cout<<"From Derived: Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"From Derived:Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};

int main(){
    BaseClass * base_class_pointer;
    DerivedClass obj_derived;
    base_class_pointer = &obj_derived; // Pointing base class pointer to derived class

    base_class_pointer->var_base = 34;
    base_class_pointer->display();

    return 0;
}


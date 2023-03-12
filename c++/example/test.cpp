#include<iostream>
#include<fstream>
#include <csignal>
using std::cout;
using std::endl;
int val =  10;

class A{
    public:
    A()
    {
        cout<<"A"<<endl;
    }
    virtual void func() {}
};
class B : public A{
    public:
    B()
    {
        cout<<"B"<<endl;
    }
    void func() 
    {

    }
};

int main()
{
    int j=10,i;
    i=(j++,j+100,j+888);
    cout<<i;
    enum e{a,b};
    cout<<a;
    
}
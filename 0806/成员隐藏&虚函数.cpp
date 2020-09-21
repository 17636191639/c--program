#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    int m_a = 5;
    virtual void func();
    //void func();
};

void A::func() 
{
    cout << "A::func()" << endl; 
}

class B : public A
{
public:
    int m_a = 10;
    void func();
};

void B::func() 
{
    cout << "B::func()" << endl; 
}

class C : public B
{
public:
    int m_a = 10;
    void func();
};

void C::func() 
{
    cout << "C::func()" << endl; 
}

class D: public A
{
public:
    int m_a = 10;
    void func();
};

void D::func() 
{
    cout << "D::func()" << endl; 
}


///派生来成员会隐藏基类的同名成员
int main(void)
{
    ////////函数隐藏///////////
    // B b;
    // b.func();
    // cout << b.m_a << endl;

    ////////函数隐藏///////////

    A *a;
    B b;
    C c;
    D d;

    a = &b;     a->func();
    a = &c;     a->func();
    a = &d;     a->func();

    return 0;
}
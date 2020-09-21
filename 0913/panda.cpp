#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Child_A
{
public:
    Child_A() { cout << "Child_A()" << endl;}
    ~Child_A(){ cout << "~Child_A()" << endl; }    
};

class Child_B
{
public:
    Child_B() { cout << "Child_B()" << endl;}
    ~Child_B(){ cout << "~Child_B()" << endl; }    
};

class Cat
{
public:
    Cat(const string & name = "Ã¨") { cout << "Cat()" << endl; m_name = name; }
    ~Cat(){ cout << "~Cat()" << endl; }

    void climbTree() const { cout << "ÉÏÊ÷" << endl; }
private:
    string m_name;
};

class Bear
{
public:
    Bear(const string & name = "ÐÜ") { cout << "Bear()" << endl; m_name = name; }
    ~Bear(){ cout << "~Bear()" << endl; }

    void assault() const { cout << "¹¥»÷" << endl; }
private:
    string m_name;
};

class Panda : public Bear, public Cat
{
public:
    Panda();
    ~Panda(){ cout << "~Panda()" << endl; }

private:
    Child_B m_b;
    Child_A m_a;
};

Panda::Panda() : m_b(), Bear(), Cat(), m_a()
{ 
    cout << "Panda()" << endl;
}

int main(void)
{
    Panda p;
    p.climbTree();
    p.assault();
	return 0;
}
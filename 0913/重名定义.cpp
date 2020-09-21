#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Cat
{
public:
    Cat(const string & name = "è") { m_name = name; }
    ~Cat(){}

    void climbTree() const { cout << "����" << endl; }
// private:
    void display() const { cout << m_name << endl; }
    string m_name;
};

class Bear
{
public:
    Bear(const string & name = "��") { m_name = name; }
    ~Bear(){ }

    void assault() const { cout << "����" << endl; }
    void display() const { cout << m_name << endl; }
// private:
    string m_name;
};

class Panda : public Bear, public Cat
{
public:
    using Cat::display;
    using Bear::m_name;
    Panda();
    ~Panda(){}
};

Panda::Panda()
{
}

int main(void)
{
    Panda p;
    p.display();
    cout << p.m_name << endl;
	return 0;
}
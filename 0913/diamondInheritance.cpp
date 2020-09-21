// #include <iostream>
// #include <string>
// #include <stdio.h>
// using namespace std;

// class Animal
// {
// public:
//     Animal() { cout << "Animal()" << endl; }
//     ~Animal() { cout << "~Animal()" << endl; }

//     int m_name;
// };


// class Bear : public Animal
// {
// public:
//     Bear() { cout << "Bear()" << endl; }
//     ~Bear() { cout << "~Bear()" << endl; }
// };

// class Cat : public Animal
// {
// public:
//     Cat() { cout << "Cat()" << endl; }
//     ~Cat() { cout << "~Cat()" << endl; }
// };

// class Panda : public Bear, public Cat
// {
// public:
//     Panda() { cout << "Panda()" << endl; }
//     ~Panda() { cout << "~Panda()" << endl; }
// };

// int main(void)
// {
//     Panda p;
//     p.Cat::m_name = 10;
//     cout << sizeof(p) << endl;//保存有两份animal

// 	return 0;
// }

//////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Animal
{
public:
    Animal() { cout << "Animal()" << endl; }
    ~Animal() { cout << "~Animal()" << endl; }
    
    int m_name;
};

class Bear : virtual public Animal
{
public:
    Bear() { cout << "Bear()" << endl; }
    ~Bear() { cout << "~Bear()" << endl; }
};

class Cat : virtual public Animal
{
public:
    Cat() { cout << "Cat()" << endl; }
    ~Cat() { cout << "~Cat()" << endl; }
};

class Panda : public Bear, public Cat
{
public:
    Panda() { cout << "Panda()" << endl; }
    ~Panda() { cout << "~Panda()" << endl; }
};

int main(void)
{
    Panda p;
    p.m_name = 10;
    cout << sizeof(p) << endl;
	return 0;
}
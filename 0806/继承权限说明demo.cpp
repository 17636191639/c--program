#include <iostream>
using namespace std;

class A
{
public:
    int a_pub;
    
protected:
    int a_pro;
    
private:
    int a_pri;
    void a_func()
    {
        a_pub = 5;
        a_pro = 2;
        a_pri = 10;
    }
};

class B : private A
{
public:
    int b_pub;
    
protected:
    int b_pro;
    
private:
    int b_pri;
    void b_func()
    {
        a_pub = 5;
        a_pro = 2;
        // a_pri = 10;
    }
};

class C: public B
{
    void c_func()
    {
        //a_pub = 5;
        //a_pro = 2;
        // a_pri = 10;
    }
};

/// A.1. 类A的对象只能访问类A的公有成员
/// A.2. 类A的成员函数能访问类A的所有成员

/// B.1. 类B的对象和成员函数都不能直接访问类A的私有成员
/// B.2. 类A的保护和公有成员是类B中的成员 (根据继承方式，访问权限不同)
/// B.3. 类B的对象和成员函数访问类B的成员 同类A(A.1  A.2)

/// C.1. 类C的对象和成员函数都不能直接访问类B的私有成员 (同B.1)
/// C.2. 类B的保护和公有成员是类C中的成员 (同B.2)
/// C.3. 类C的对象和成员函数访问类C的成员 (同B.3)

int main(void)
{
    B b;
    // b.a_pub = 10;

    return 0;
}
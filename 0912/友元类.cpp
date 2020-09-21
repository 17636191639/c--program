#include <iostream>
using namespace std;

class X
{
public:
    friend class Y; // 类Y是类X的友元类

    void set(int i)  { m = i; }
    void display()
    {
        cout<< "m=" << m << "," << "n=" << n <<endl;
    }

private:
    int m;
    static int n; //静态数据说明
};

int X::n = 10; //静态数据定义并初始化

class Y
{
public:
    Y(int i,int j);
    void display();

private:
    X a; //数据成员为类X的对象
};

Y::Y(int i,int j)
{
    a.m = i;  
    X::n = j;
}
void Y::display()
{
    cout << "m=" << a.m << "," << "n=" << X::n << endl;
}

int main()
{
    X b;
    b.set(5);
    b.display();

    Y c(6,9);
    c.display();
    
    b.display();// X可以访问Y的数据


    return 0;
}

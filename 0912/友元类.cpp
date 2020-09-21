#include <iostream>
using namespace std;

class X
{
public:
    friend class Y; // ��Y����X����Ԫ��

    void set(int i)  { m = i; }
    void display()
    {
        cout<< "m=" << m << "," << "n=" << n <<endl;
    }

private:
    int m;
    static int n; //��̬����˵��
};

int X::n = 10; //��̬���ݶ��岢��ʼ��

class Y
{
public:
    Y(int i,int j);
    void display();

private:
    X a; //���ݳ�ԱΪ��X�Ķ���
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
    
    b.display();// X���Է���Y������


    return 0;
}

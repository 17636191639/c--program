#include <iostream>
using namespace std;

class Temp
{
public:
    void func();
    template <typename T> void func(T t);
private:
    int a;
};

void Temp::func()           /// ��ͨ��ĳ�Ա����
{
}

template <typename T> 
void Temp::func(T t)        /// ��ͨ���ģ�庯��
{
}

/// ��ģ���ģ�����ʹ�� < class T >
/// ����ģ���ģ�����ʹ�� < typename T >
template <class U>    
class Test
{
public:
    void func();
    template <typename T> void func(T t); 
private:
    U a;
};

template <class U>   
void Test<U>::func()        /// ģ����ĳ�Ա����
{
}

template <class U>          /// ��ʶ����Ϊģ����ĺ���
template <typename T>       /// ��ʶ����Ϊģ�庯��
void Test<U>::func(T t)     /// ģ�����ģ�庯��
{
}

int main()
{
    Temp t;
    Test<char> te;
    return 0;
}


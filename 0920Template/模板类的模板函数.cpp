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

void Temp::func()           /// 普通类的成员函数
{
}

template <typename T> 
void Temp::func(T t)        /// 普通类的模板函数
{
}

/// 类模板的模板参数使用 < class T >
/// 函数模板的模板参数使用 < typename T >
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
void Test<U>::func()        /// 模板类的成员函数
{
}

template <class U>          /// 标识函数为模板类的函数
template <typename T>       /// 标识函数为模板函数
void Test<U>::func(T t)     /// 模板类的模板函数
{
}

int main()
{
    Temp t;
    Test<char> te;
    return 0;
}


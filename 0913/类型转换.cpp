#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int func(int a, int b)
{
    return a + b;
}

typedef char (*FuncPtr) (int, int);




int main(void)
{
    // FuncPtr ptr = reinterpret_cast<FuncPtr>(func);
    // cout << ptr(90,7) << endl;
    
    // const int a = 65;
    // int &p = const_cast<int &>(a);      /// 去const属性
    // char c = static_cast<char>(a);      /// 静态类型转换，基本数据类型的转换

	return 0;
}
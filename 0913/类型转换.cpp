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
    // int &p = const_cast<int &>(a);      /// ȥconst����
    // char c = static_cast<char>(a);      /// ��̬����ת���������������͵�ת��

	return 0;
}
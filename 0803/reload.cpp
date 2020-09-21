#include <iostream>

void func(int a, int b)
{
    std::cout <<"a:" << a << " b: "<< b << std::endl;
    printf("int \n");
}
void func(double a, double b = 3.14)     //b 有默认参数值yiou
{
    std::cout <<"a:" << a << " b: "<< b << std::endl;
    printf("double\n");
}

int main()
{
    func(1.02);
    func(10,15);
    return 0;
}
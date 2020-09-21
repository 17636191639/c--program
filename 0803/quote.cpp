#include <iostream>

int main()
{
    int a = 3;
    int &m = a;
    int n = m;
    int *p = &m;

    std::cout << m << std::endl;
    return 0;
}
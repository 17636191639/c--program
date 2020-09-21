#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

const char *h = "china";

namespace first
{
    int a;
}

int main()
{
    first::a = 10;
    int a = 5;
    int *pp = NULL;
    char *p = NULL;

    pp = new int(5);
    p = new char[100];
    strcpy(p, "hello");
    strcat(p, " world");

    cout << *pp << endl;
    cout << p << endl;
    cout << h << endl;

    delete pp;
    delete [] p;
    // cout << "hello world!"<<  " " << first::a * a << std::endl;
    // printf("hello world!\n");
    return 0;
}

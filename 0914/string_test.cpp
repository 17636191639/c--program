#include <iostream>
#include <string>

using namespace std;

int map(int value, int fromStart, int fromEnd,int toStart, int toEnd) 
{
     return ((int)(value - fromStart) * (toEnd - toStart)) / (fromEnd - fromStart) + toStart;
}
int main()
{
    // string str = "hello world";
    // str = str + "nihao ";
    // cout << str[0] << endl;
    // cout << str.length()  <<endl; 
    // int speed = 50;
    // cout << map(abs(speed),0,100,0, 1000) << endl;

    string str;

    // istream is;
    // is >> a;
    // 
    cin >> str;

    
    

    return 0;
}   
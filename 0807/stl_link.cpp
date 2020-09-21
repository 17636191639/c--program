#include <iostream>
#include <string>
#include <list>

using namespace std;

void str_print(string &str)
{

    //string::iterator p;      //迭代器（类似C语言指针）
    //for(p = str.begin(); p != str.end(); p++) //正向

    string::reverse_iterator p; 
    for(p = str.rbegin(); p != str.rend(); p++)  //反向迭代器   
    
    {
        cout << *p << endl;
    }
}
void list_print(list<string> &strlist)
{
    list<string>::iterator p; // 
    for(p = strlist.begin(); p != strlist.end(); p++)
    {
        cout << *p << endl;
    }

}
   
int main()
{
    // string str("0123456");
    // str_print(str);

    list<string> strlist;   //产生一个空容器
    strlist.push_front("0");
    strlist.push_front("1");
    strlist.push_front("2");
    list_print(strlist);
    return 0;
}

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    string str("hello");
    cout<< str << " size(): " <<  str.size() << " length(): " << str.length() <<endl;

    str.append(" world!");  //×Ö·û´®Æ´½Ó
    str  += " ~world";      //×Ö·û´®Æ´½Ó
    cout<< str <<endl;

 
    str.assign("0123456789");   //×Ö·û´®Ìæ»»
    str.replace(2, 4, "[0]");   //£¿£¿£¿£¿£¿
    str.push_back('a');         //Íù×Ö·û´®ºó±ßÌí¼Ó×Ö·û
    cout<< str <<endl;

    const char *p = str.c_str(); //½«stringÀà×ª»¯³É×Ö·û´®£¨'\0'½áÎ²£©²¢·µ»Ø×Ö·û´®Ö¸Õë
    cout<< p <<endl;
    printf("%s\n", p);

    cout << str.at(0) << endl; 
    return 0;
}
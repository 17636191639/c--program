#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    string str("hello");
    cout<< str << " size(): " <<  str.size() << " length(): " << str.length() <<endl;

    str.append(" world!");  //�ַ���ƴ��
    str  += " ~world";      //�ַ���ƴ��
    cout<< str <<endl;

 
    str.assign("0123456789");   //�ַ����滻
    str.replace(2, 4, "[0]");   //����������
    str.push_back('a');         //���ַ����������ַ�
    cout<< str <<endl;

    const char *p = str.c_str(); //��string��ת�����ַ�����'\0'��β���������ַ���ָ��
    cout<< p <<endl;
    printf("%s\n", p);

    cout << str.at(0) << endl; 
    return 0;
}
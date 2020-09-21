#include <iostream>
#include <string.h>
#include <string>

int main()
{
    std::string str;  
    std::string str2;                                             //char a[100];
    std::string str3;

    str = "hello";                                                //strcpy(a, "hello");
    std::cout << " str " << str << " len : " << str.length() << std::endl;       // strlen(a) 

    str3.append(str);  
    str = str + " world";                                         //strcat(a, " world");
                                       
    std::cout << " str " << str << " len : " << str.length() << std::endl;

    std::cout << " str3 " << str3 << " len : " << str3.length() << std::endl;
    str2 = str;

    std::cout << " str2 " << str2 << " len : " << str2.length() << std::endl;

    str3 = str.substr();

    std::cout << " str3 " << str3 << " len : " << str3.length() << std::endl;
    return 0;
}
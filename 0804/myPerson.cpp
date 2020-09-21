#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//class采用驼峰命名
class Person
{
public:
    Person(const char *name = "001", int age = 0);
    ~Person();

    void display();
    void setAge(int age);
    void setName(const char *name);
private:
    char *m_name; //std::string m_name;
    int m_age;
};


Person::~Person()
{
    delete [] m_name;
    cout << "Space release completed" << endl;
}

Person::Person(const char *name, int age)
{
    //m_name = name;
    cout << "constructor function init" << endl;
    m_name = new char[sizeof(strlen(name) + 1)]; 
    strcpy(m_name, name);
    m_age = age;
}

void Person::display()
{
    std::cout << m_name << " age: " << m_age << std::endl;
}

void Person::setAge(int age)
{
    m_age = age;
}

void Person::setName(const char *name)
{
    delete [] m_name;
    m_name = new char[sizeof(strlen(name) + 1)]; 
    strcpy(m_name, name);
}

int main()
{
    Person p;              //构造函数在申请空间时自动执行        在Person p的栈空间释放前会自动调用析构函数
    //p.initPerson("hello", 20);
    p.display();
    p.setName("小明");
    p.display();

    Person *p2 = new Person("world", 30);
    p2->display();                    
    delete p2;                          //在释放p2前会自动调用析构函数

    return 0;
}
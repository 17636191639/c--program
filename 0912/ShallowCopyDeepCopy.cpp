#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class Person  ///每个单词的首字母大写
{
public:
    Person();
    Person(const char *name, int age);
    Person(const Person &p);
    Person &operator=(const Person &p);
    ~Person();

    void setName(const char* name);  ///成员函数
    void setAge(int age);
    const char *getName(void) const;
    int getAge(void) const;
    virtual void display(void) const;
private:
	char *m_name;  ///m_前缀 类的成员
	int m_age;
};

Person::Person()
{
    cout << "Person::Person()" << endl;
    m_name = NULL;
    m_age = 0;
}

Person::Person(const char *name, int age)
{
    cout << "Person::Person(const char *name, int age)" << endl;
    m_name = new char[strlen(name)+1];
	strcpy(m_name, name);
	m_age = age;
}

Person::Person(const Person &p)
{
    cout << "Person::Person(const Person &p)" << endl;
    // m_name = p.m_name;  ///浅拷贝
    m_name = new char[strlen(p.m_name)+1];  ///深拷贝
	strcpy(m_name, p.m_name);

    m_age = p.m_age;
}

Person::~Person()
{
    cout << "Person::~Person()" << endl;
    if(m_name != NULL)
    {
        delete []m_name;
    }
}

void Person::setName(const char* name)
{
	if(m_name != NULL)
    {
        delete []m_name;
    }
	m_name = new char[strlen(name)+1];
	strcpy(m_name, name);
}

void Person::setAge(int age)
{
	m_age = age;
}

const char *Person::getName(void) const
{
    return m_name;
}
int Person::getAge(void) const
{
    return m_age;
}

void Person::display() const
{
    printf("%p, %p\n", &m_name, m_name);
	// if(m_name == NULL)
    // {
    //     cout << "No name!!" << endl;

    // }else
    // {
    //     cout << "Name:" << m_name << endl;
    // }

	// cout << "Age:" << m_age << endl;
}

Person &Person::operator=(const Person &p)
{
    cout << "Person::operator=(const Person &p)" << endl;
    // m_name = p.m_name;
    if(m_name != NULL)  ///赋值函数，对象已经存在，所以需要判断m_name指针的有效性
    {
        delete []m_name;
    }
	m_name = new char[strlen(p.m_name)+1];
	strcpy(m_name, p.m_name);
    m_age = p.m_age;
    return *this;
}

////////////////////////////////////////Main()///////////////////////////////////////////////

int main(void)
{
    // int a, b , c;
    // a = b = c = 5;
    // cout << a << ", " << b << ", " << c << endl;
	Person p("小明", 20);
    Person p1 = p;
    Person p2;
    p2.operator=(p1.operator=(p)); //p2 = p1 = p;
    p.display();
    p1.display();
    p2.display();
    

	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
    Person(const char *name, int age); //解析函数
    ~Person();                         //析构函数
    void display()const;
    void setName(const char *name);
    void setAge(int age);
    const char *getName()const;
    int getAge();

private:
    char *m_name;
    int m_age;
};

Person::Person(const char *name, int age)
{
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    this->m_age = age;
}
Person::~Person()
{
    if (m_name != NULL)
    {
        delete[] m_name;
        cout << "free complete" << endl;
    }
}
void Person::display()const
{
    cout << "name: " << m_name << " age: " << m_age << endl;
}

void Person::setName(const char *name)
{
    if(m_name != NULL)
    {
        delete [] m_name;
    }
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    cout << "set name sucess~!" << endl;
}
void Person::setAge(int age)
{
    m_age = age;
}
const char *Person::getName() const
{
    return m_name;
}
int Person::getAge()
{
    return m_age;
}

int main()
{
    Person p("xin", 20);
    p.setName("girl");
    p.setAge(10);
    //p.display();
    cout << "name: " << p.getName() << " age: " << p.getAge() << endl;
    return 0;
}
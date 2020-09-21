#include <iostream>
#include <string.h>
using namespace std;
class Person
{
public:
    void initPerson(const char *name, int age);
    void setName(const char *name);
    void setAge(int age);
    void display(void);

private:
    char *m_name;
    int m_age;
};

void Person::initPerson(const char *name, int age)
{
    this->m_name = new char[strlen(name) + 1];
    strcpy(this->m_name, name);
    this->m_age = age;
}

void Person::setName(const char *name)
{
    if (this->m_name != NULL)
    {
        delete[] this->m_name;
    }
    this->m_name = new char[100];
    strcpy(this->m_name, name);
}

void Person::setAge(int age)
{
    this->m_age = age;
}

void Person::display()
{
    cout << "Name:" << this->m_name
         << endl;
    cout << "Age:" << this->m_age
         << endl;
}

int main(void)
{
    Person one;
    one.initPerson("Lisa", 18);
    one.display();
    one.setName("Mind");
    one.setAge(20);
    one.display();
}
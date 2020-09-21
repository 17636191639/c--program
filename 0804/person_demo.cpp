#include <iostream>
#include <string.h>

using namespace std;

struct Person
{
    char *m_name;
    int m_age;
};

void initPerson(Person *p, const char *name, int age)
{
    p->m_name = new char[strlen(name) + 1];
    strcpy(p->m_name, name);
    p->m_age = age;
}

void setName(Person *p, const char *name)
{
    if (p->m_name != NULL)
    {
        delete[] p->m_name;
    }
    p->m_name = new char[100];
    strcpy(p->m_name, name);
}

void setAge(Person *p, int age) 
{
     p->m_age = age;
}

void display(Person *p)
{
    cout << "Name:" << p->m_name << endl;
    cout << "Age:" << p->m_age << endl;
}
int main(void)
{
    Person one;
    initPerson(&one, "Lisa", 18);
    display(&one);
    setName(&one, "Mind");
    setAge(&one, 20);
    display(&one);
    return 0;
}
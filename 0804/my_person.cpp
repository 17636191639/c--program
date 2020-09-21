#include <iostream>
#include <string>

class Person
{
public:
    Person(const char *name, int age);
    ~Person();
    void display() const;
    void setAge(int age) const;
private:
    const std::string m_name;
    int m_age;
};

Person::~Person()
{
    //delete [] m_name;
    std::cout << "Space release completed" << std::endl;
}

void Person::setAge(int age) const
{
    ((Person*)this)->m_age = age;                           //将const this指针转换
}

Person::Person(const char *name, int age) :m_name(name)
{
    // m_name = name;
    m_age = age;
}

void Person::display() const
{
    std::cout << m_name << " age: " << m_age << std::endl;
}


int main()
{
    const Person p("hello", 0);
    p.setAge(10);
    p.display();

    return 0;
}

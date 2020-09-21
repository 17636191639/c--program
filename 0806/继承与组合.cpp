#include <iostream>
#include <string>
using namespace std;

class Children
{
public:
    Children();
    Children(const string &name, int age);
    ~Children();
private:
    string m_name;      ///数据成员--子对象
    int m_age;
};

Children::Children()
{
    cout << "Children::Children()" << endl;
}
Children::Children(const string &name, int age)
{
    cout << "Children::Children(const string &name, int age)" << endl;
}
Children::~Children()
{
    cout << "Children::~Children()" << endl;
}


class Person
{
public:
    Person();
    Person(const string &name, int age);
    ~Person();
private:
    string m_name;      ///数据成员--子对象
    int m_age;
};

Person::Person()
{
    cout << "Person::Person()" << endl;
}
Person::Person(const string &name, int age)
{
    cout << "Person::Person(const string &name, int age)" << endl;
}
Person::~Person()
{
    cout << "Person::~Person()" << endl;
}

class Student : public Person
{
public:
    Student();
    Student(const string &name, int age, const string &id, int grade);
    ~Student();
private:
    Children m_child;      ///数据成员--子对象
    int m_grade;
};

Student::Student() : Person("xiaoming", 20), m_grade(20), m_child("xiaoming", 20)
{
    cout << "Student::Student()" << endl;
}
Student::Student(const string &name, int age, const string &id, int grade) 
    : Person(name, age), m_child("xiaoming", 20)
{
    cout << "Student::Student(const string &id, int grade)" << endl;
    m_grade = grade;
}
Student::~Student()
{
    cout << "Student::~Student()" << endl;
}

int main(void)
{
    Student stu[5];

    return 0;
}
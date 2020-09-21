#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

////////////////////////////////////////Person///////////////////////////////////////////////
class Person  ///每个单词的首字母大写
{
public:
    Person();
    Person(const char *name, int age);
    Person(const Person &p);
    Person &operator=(const Person &p);
    virtual ~Person();

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
    //printf("%p, %p\n", &m_name, m_name);
	if(m_name == NULL)
    {
        cout << "No name!!" << endl;

    }else
    {
        cout << "Name:" << m_name << endl;
    }

	cout << "Age:" << m_age << endl;
}

Person &Person::operator=(const Person &p)
{
    cout << "Person::operator=(const Person &p)" << endl;
    if(this == &p) return *this;  ///避免出现p=p的情况
    if(m_name != NULL)  ///赋值函数，对象已经存在，所以需要判断m_name指针的有效性
    {
        delete []m_name;
    }
	m_name = new char[strlen(p.m_name)+1];
	strcpy(m_name, p.m_name);
    m_age = p.m_age;
    return *this;  ///返回值用于连等于，a = b = c; this指向运算符的左值
}

/////////////////////////////////////////////////////////////////////////Student///////////////////////////////////////////////

class Student : public Person
{
public:
    Student();
    Student(const char *name, int age, const char *id, int grade);
    Student(const Student &stu);
    Student &operator=(const Student &stu);
    ~Student();

    void display() const;

    void setID(const char* id);  ///成员函数
    void setGrade(int grade);
    const char *getID(void) const;
    int getGrade(void) const;
    

private:
    char *m_id;
    int m_grade;
};

void Student::setID(const char* id)
{
    if(m_id != NULL)
    {
        delete []m_id;
    }
	m_id = new char[strlen(id)+1]; 
	strcpy(m_id, id);
  
}  

Student::Student(const Student &p)//拷贝函数
{
    cout << "Student::Student(const Student &p)" << endl;
    
    this->setName(p.getName());
    this->setAge(p.getAge());

    // m_name = p.m_name;  ///浅拷贝
    m_id = new char[strlen(p.m_id)+1];  ///深拷贝
	strcpy(m_id, p.m_id);

    m_grade = p.m_grade;
}

void Student::display() const
{
    this->Person::display();
    if(m_id == NULL)
    {
        cout << "No id!!" << endl;

    }else
    {
        cout << "ID:" << m_id << endl;
    }

	cout << "grade:" << m_grade << endl;
    
}

Student::Student()
{
    cout << "Student::Student()" << endl;
    m_id = NULL;
    m_grade = 0;
}

Student::Student(const char *name, int age, const char *id, int grade)
{
    this->setName(name);
    this->setAge(age);

    m_id = new char[strlen(id)+1];
	strcpy(m_id, id);

    m_grade = grade;
}

Student::~Student()
{
    cout << "Student::~Student()" << endl;

    if(m_id != NULL)
    {
        delete []m_id;
    }
}
Student &Student::operator=(const Student &stu)
{
    cout << "Student &Student::operator=(const Student &stu)" << endl;
    if(this == &stu) return *this;  ///避免出现p=p的情况
    
    if(m_id != NULL)  
    {
        delete []m_id;
    }
	m_id = new char[strlen(stu.m_id)+1];
	strcpy(m_id, stu.m_id);
    m_grade = stu.m_grade;

    return *this;  ///返回值用于连等于，a = b = c; this指向运算符的左值
}
////////////////////////////////////////Main()///////////////////////////////////////////////

int main(void)
{
    /// 1
    Student ming("xiaoming", 10, "201952647", 59);
    ming.display();

    /// 2
    Student hong = ming;
    hong.setName("xiaohong");
    hong.setID("201952658");
    hong.display();

    /// 3
    Student gang("xiaogang", 20, "201952562", 59);
    gang.display();
    ming = gang;
    ming.display();

	return 0;
}

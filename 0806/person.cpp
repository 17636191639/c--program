#include <iostream>
#include <cstring>
using namespace std;
////////////////////////////////////children///////////////////////////////////////////////////////
class Children
{
public:
    Children();                               //鏋勯€犲嚱鏁扮殑閲嶈浇
    Children(const char *name, int age);
    ~Children();
private:
    char *m_name;
    int m_age;
};

Children::Children()
{
    m_name = NULL;
    m_age = 0;
}

Children::Children(const char *name, int age)
{
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    m_age = age;
}

////////////////////////////////////////////////////PERSON/////////////////////////////////////////////////
class Person
{
public:
    Person();                               //鏋勯€犲嚱鏁扮殑閲嶈浇
    Person(const char *name, int age);
    ~Person();

    void display() const;

    void setName(const char *name);
    void setAge(int age);

    const char *getName() const;
    const int& getAge() const;

private:
    char *m_name;
    int m_age;
};

Person::Person()
{
    m_name = NULL;
    m_age = 0;
}

Person::Person(const char *name, int age)
{
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    m_age = age;
}
Person::~Person()
{
    if(m_name != NULL)
    {
        delete [] m_name;
    }
}
void Person::display() const
{
    if(m_name != NULL)
    {
        cout << "name: " << getName() << " age: " << m_age << endl;
    }else
    {
        cout << "NoName " << " age: " << m_age << endl;
    }
    
}

void Person::setName(const char *name)
{
    if(m_name != NULL)
    {
        delete [] m_name;
    }
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);

}
void Person::setAge(int age)
{
    m_age = age;
}

const char *Person::getName() const
{
    return m_name;
}
const int& Person::getAge() const    //杩斿洖甯稿紩鐢�
{
    return this->m_age;
}

////////////////////////////////////////////////////////STUDENT//////////////////////////////////////////////
class Student : public Person
{
public:
    Student();
    Student(int id, int grade);
    Student(const char *name, int age, int id, int grade);
    void display() const;
private:
    //Children child;   //鏁版嵁鎴愬憳--瀛愬璞�
    int m_ID;
    int m_Grade;
};
Student::Student()
{
    m_ID = 10;
    m_Grade = 100;
}
Student::Student(int id, int grade)
{
    m_ID = id;
    m_Grade = grade;
}

Student::Student(const char *name, int age, int id, int grade) 
    : Person(name, age)                                         //鍦ㄥ垵濮嬪寲鍒楄〃瀵瑰熀绫诲垵濮嬪寲
{
    m_ID = id;
    m_Grade = grade;
}

void Student::display() const
{
    
    if(getName() != NULL)
    {
        cout << "name: " << getName()  << " age: " << getAge() << endl;
    }else
    {
        cout << "NoName " << " age: " << getAge() << endl;
    }
    //Person::display();                                              //鍦ㄦ淳鐢熺被涓熀绫绘槸闅愯棌鐨勶紝鍙互閫氳繃鍩虹被浣滅敤鍩熻皟鐢� 
    cout << "id: " << m_ID  << " grade: " << m_Grade << endl;
}

//////////////////////////////////////////main//////////////////////////////////////
int main()
{
    Student stu("init", 20, 2050, 99);
    
    stu.Person::display();
    
    return 0;
}
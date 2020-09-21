#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
public:
    //MyString();
    MyString(const char *str = "");
    MyString(const MyString &str);
    ~MyString();

    MyString &operator=(const MyString &str);
    MyString &operator=(const char *str);

    char &operator[](unsigned int index);
    const char &operator[](unsigned int index) const;

    MyString &operator+=(const MyString &str);
    friend MyString operator+(const MyString &s1, const MyString &s2);

    friend ostream &operator<<(ostream &os, const MyString &str);

    friend istream &operator>>(istream &is, MyString &str);

    int length() const;
    bool isEmpty() const;

    void display(void);

private:
    char *m_data;
    unsigned int m_len;
};
int MyString::length() const
{
    return m_len;
}
bool MyString::isEmpty() const
{
    return (m_len == 0);
}

istream &operator>>(istream &is, MyString &str) //ÊäÈëÁ÷
{
    char tmp[1024];
    is >> tmp;
    if(str.m_data != NULL)
    {
        delete []str.m_data;
    }
    str.m_data = new char[(str.m_len = strlen(tmp)) + 1];
    strcpy(str.m_data, tmp);
    return is;
}
ostream &operator<<(ostream &os, const MyString &str)  // <<
{
    return os << str.m_data;
}

MyString operator+(const MyString &s1, const MyString &s2) // +
{
    MyString str;
    str.m_data = new char[s1.m_len + s2.m_len + 1];

    strcpy(str.m_data, s1.m_data);
    strcat(str.m_data, s2.m_data);

    str.m_len = s1.m_len + s2.m_len;
    return str;
}

MyString &MyString::operator+=(const MyString &str) //  +=
{
    int len = this->m_len + str.length();
    char *dest = new char[len + 1];

    strcpy(dest, m_data);

    // int i;
    // for (i = 0; str.m_data[i] != '\0'; i++)
    // {
    //     dest[m_len + i] = str.m_data[i];
    // }

    // dest[m_len + i] = '\0';
    strcat(dest, str.m_data);

    if (m_data != NULL)
    {
        delete[] m_data;
    }
    m_data = dest;
    m_len = len;

    return *this;
}
const char &MyString::operator[](unsigned int index) const // operator[]
{
    return m_data[index];
}

char &MyString::operator[](unsigned int index)
{
    return m_data[index];
}

MyString &MyString::operator=(const char *str) //operator=
{
    if (m_data != NULL)
    {
        delete[] m_data;
    }
    m_data = new char[strlen(str) + 1];
    strcpy(m_data, str);

    m_len = strlen(str);
    return *this;
}

MyString &MyString::operator=(const MyString &str)
{
    if (m_data != NULL)
    {
        delete[] m_data;
    }
    m_data = new char[str.m_len + 1];
    strcpy(m_data, str.m_data);

    m_len = str.m_len;

    return *this;
}

void MyString::display(void) ////////////////////////display/////////////////
{
    if (m_data != NULL)
    {
        cout << "data: " << m_data << endl;
    }
    cout << "len: " << m_len << endl;
}

// MyString::MyString()
// {
//     m_data = NULL;
//     m_len = 0;
// }

MyString::MyString(const char *str)
{
    m_data = new char[strlen(str) + 1];
    strcpy(m_data, str);

    m_len = strlen(str);
}

MyString::MyString(const MyString &str)
{

    m_data = new char[str.m_len + 1];
    strcpy(m_data, str.m_data);

    m_len = str.m_len;
}
MyString::~MyString()
{
    if (m_data != NULL)
    {
        delete[] m_data;
    }
}
////////////////////////////////////////////////////////////main()////////////////////////////////////////////////
int main()
{
    MyString str = "hello";
    str.display();

    cin >> str;
    str.display();

    // const char *str3 = "i love";

    // MyString str2;
    // str2 = str3;
    // str2.display();

    // str += "str2";
    // str.display();
    // //str = str2 + str3;
    // str = str2 + "nihao ";
    // str.display();
    // cout << str << endl;
    // cout << str.length() << endl;

    return 0;
}
#include <iostream>
using namespace std;

/// 作业：
/// 1. operator+    : 友元/成员函数
/// 2. operator+=   : 成员/友元函数
/// 3. operator<<   : 友元
/// 4. operator==   : 友元/成员函数
class Time
{
public:
    Time(){  m_hour = m_minute = m_second = 0;  }
    Time(int hour, int minute, int second)
    {
        m_hour = hour;
        m_minute = minute;
        m_second = second;
    }
    void display() const { cout << m_hour << ":" << m_minute << ":" << m_second << endl; }

    // friend Time &operator+=(Time &t1, const Time &t2);  // a += b; operator+=(a, b);
    Time &operator+=(const Time &t);                    // a += b; a.operator+=(b);
    // friend Time operator+(const Time &t1, const Time &t2);  // c = a + b; c = operator+(a, b);
    Time operator+(const Time &t2) const;                  // c = a + b; c = a.operator+(b);

    /// cout 是 ostream 的对象
    friend ostream& operator<<(ostream& os, Time& t);  /// cout << a << endl;  cout << t << endl;

private:
    int m_hour;
    int m_minute;
    int m_second;
};

/// 0.确定友元还是成员函数来 重载运算符
/// 1.确定函数名 operator+;
/// 2.确定参数，引用与常引用
/// 3.确定返回值，传值 or 传引用
/// 4.根据运算符逻辑，实现函数

// int c = a + b;
// Time operator+(const Time &t1, const Time &t2)
// {
//     cout << "Time operator+(const Time &t1, const Time &t2)" << endl;
//     Time t;
//     t.m_hour = t1.m_hour + t2.m_hour;
//     t.m_minute = t1.m_minute + t2.m_minute;
//     t.m_second = t1.m_second + t2.m_second;
    
//     return t;
// }

Time Time::operator+(const Time &t2) const
{
    cout << "Time Time::operator+(const Time &t2) const" << endl;
    Time t;
    t.m_hour = m_hour + t2.m_hour;
    t.m_minute = m_minute + t2.m_minute;
    t.m_second = m_second + t2.m_second;
    
    return t;
}

// a += b; int c = a += b;
// Time &operator+=(Time &t1, const Time &t2)
// {
//     cout << "friend Time &operator+=(Time &t1, const Time &t2)" << endl;
//     t1.m_hour += t2.m_hour;
//     t1.m_minute += t2.m_minute;
//     t1.m_second += t2.m_second;
    
//     return t1;
// }

Time &Time::operator+=(const Time &t)                    // a += b; a.operator+=(b);
{
    cout << "Time &Time::operator+=(const Time &t)" << endl;
    this->m_hour += t.m_hour;
    this->m_minute += t.m_minute;
    this->m_second += t.m_second;

    return *this;
}

ostream& operator<<(ostream& os, Time& t)  ///流运算符只能用友元重载 cout.operator<<(t);
{
    return os << t.m_hour << ":" << t.m_minute << ":" << t.m_second;
}

int main()
{
    Time t1(2,5,7);         // int a = 5;
    cout << t1 << endl;     // cout << a << endl;

    return 0;
}
#include <iostream>
using namespace std;

/// ��ҵ��
/// 1. operator+    : ��Ԫ/��Ա����
/// 2. operator+=   : ��Ա/��Ԫ����
/// 3. operator<<   : ��Ԫ
/// 4. operator==   : ��Ԫ/��Ա����
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

    /// cout �� ostream �Ķ���
    friend ostream& operator<<(ostream& os, Time& t);  /// cout << a << endl;  cout << t << endl;

private:
    int m_hour;
    int m_minute;
    int m_second;
};

/// 0.ȷ����Ԫ���ǳ�Ա������ ���������
/// 1.ȷ�������� operator+;
/// 2.ȷ�������������볣����
/// 3.ȷ������ֵ����ֵ or ������
/// 4.����������߼���ʵ�ֺ���

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

ostream& operator<<(ostream& os, Time& t)  ///�������ֻ������Ԫ���� cout.operator<<(t);
{
    return os << t.m_hour << ":" << t.m_minute << ":" << t.m_second;
}

int main()
{
    Time t1(2,5,7);         // int a = 5;
    cout << t1 << endl;     // cout << a << endl;

    return 0;
}
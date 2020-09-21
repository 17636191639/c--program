#include <iostream>
using namespace std;

class Time
{
public:
    Time();
    Time(int hour, int minute, int second);
    void display() const;
    friend Time operator+(const Time &t1, const Time &t2); //友元函数定义 +
    //Time operator+(const Time &t);// 成员函数定义 +

    friend Time &operator+=(Time &t1, const Time &t2);  //友元函数定义 +=
    //Time &operator+=(const Time &t);     //成员函数定义 +=

    friend ostream &operator<<(ostream &os, const Time &t);//stream

    //friend bool operator==(Time &t1, const Time &t2);  //友元函数定义 ==
    bool operator==(Time &t);  //成员函数定义 ==

    //Time &operator++();//成员函数实现 ++t
    friend Time &operator++(Time &t); //友元函数实现 ++t

    Time operator++(int);//成员函数实现 t++    //参数起标识作用 亚元
    

private:
    int m_hour;
    int m_minute;
    int m_second;
};

Time Time::operator++(int)//成员函数实现 t++
{
    cout << "Time Time::operator++(int)//成员函数实现 t++" << endl;
    Time t = *this;
    this->m_second++;
    return t;
}

Time &operator++(Time &t) //友元函数实现 ++t
{
    cout << "Time &operator++(Time &t); //友元函数实现 ++t" << endl;
    t.m_second++;
    return t;
}
// Time & Time::operator++()//成员函数实现 ++t
// {
//     cout << "Time & Time::operator++()//成员函数实现 ++t" << endl;
//     m_second++;
//     return *this;
// }

Time::Time()
{
    m_hour = m_minute = m_second = 0;
}

Time::Time(int hour, int minute, int second)
{
    m_hour = hour;
    m_minute = minute;
    m_second = second;
}

void Time::display() const
{
    cout << "time: " << m_hour << " : " << m_minute << " : " << m_second << endl;
}

Time operator+(const Time &t1, const Time &t2) //友元函数实现 +
{
    Time t;
    t.m_hour = t1.m_hour + t2.m_hour;
    t.m_minute = t1.m_minute + t2.m_minute;
    t.m_second = t1.m_second + t2.m_second;
    return t;
}

// Time Time::operator+(const Time &t)// 成员函数定义 +
// {
//     Time out;
//     out.m_hour = m_hour + t.m_hour;
//     out.m_minute = m_minute + t.m_minute;
//     out.m_second = m_second + t.m_second;
//     return out;

// }

// Time &Time::operator+=(const Time &t)     //成员函数实现 +=
// {
//     m_hour += t.m_hour;
//     m_minute += t.m_minute;
//     m_second += t.m_second;
//     return *this;
// }

Time &operator+=(Time &t1, const Time &t2)  //友元函数实现 +=
{
    t1.m_hour += t2.m_hour;
    t1.m_minute += t2.m_minute;
    t1.m_second += t2.m_second;

    return t1;
}

ostream &operator<<(ostream &os, const Time &t)  //流函数实现
{
    os << t.m_hour << " : " << t.m_minute << " : " << t.m_second << endl;
    return os;
}

// bool operator==(Time &t1, const Time &t2)  //友元函数实现 ==
// {
//     if((t1.m_hour == t2.m_hour) && (t1.m_minute == t2.m_minute) && (t1.m_second == t2.m_second))
//     {
//          return 1;
//     }
//     return 0;
// }

bool Time::operator==(Time &t)  //成员函数定义 ==
{
    if((m_hour == t.m_hour) && (m_minute == t.m_minute) && (m_second == t.m_second))
    {
         return 1;
    }
    return 0;
}

int main()
{
    Time t1(3, 50, 20);
    t1.display();
    
    Time t2 = ++t1;
    t1.display();
    t2.display();

    t2 = t1++;
    t1.display();
    t2.display();
    
    return 0;    
}
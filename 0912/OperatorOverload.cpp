#include <iostream>
using namespace std;

class Time
{
public:
    Time();
    Time(int hour, int minute, int second);
    void display() const;
    friend Time operator+(const Time &t1, const Time &t2); //��Ԫ�������� +
    //Time operator+(const Time &t);// ��Ա�������� +

    friend Time &operator+=(Time &t1, const Time &t2);  //��Ԫ�������� +=
    //Time &operator+=(const Time &t);     //��Ա�������� +=

    friend ostream &operator<<(ostream &os, const Time &t);//stream

    //friend bool operator==(Time &t1, const Time &t2);  //��Ԫ�������� ==
    bool operator==(Time &t);  //��Ա�������� ==

    //Time &operator++();//��Ա����ʵ�� ++t
    friend Time &operator++(Time &t); //��Ԫ����ʵ�� ++t

    Time operator++(int);//��Ա����ʵ�� t++    //�������ʶ���� ��Ԫ
    

private:
    int m_hour;
    int m_minute;
    int m_second;
};

Time Time::operator++(int)//��Ա����ʵ�� t++
{
    cout << "Time Time::operator++(int)//��Ա����ʵ�� t++" << endl;
    Time t = *this;
    this->m_second++;
    return t;
}

Time &operator++(Time &t) //��Ԫ����ʵ�� ++t
{
    cout << "Time &operator++(Time &t); //��Ԫ����ʵ�� ++t" << endl;
    t.m_second++;
    return t;
}
// Time & Time::operator++()//��Ա����ʵ�� ++t
// {
//     cout << "Time & Time::operator++()//��Ա����ʵ�� ++t" << endl;
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

Time operator+(const Time &t1, const Time &t2) //��Ԫ����ʵ�� +
{
    Time t;
    t.m_hour = t1.m_hour + t2.m_hour;
    t.m_minute = t1.m_minute + t2.m_minute;
    t.m_second = t1.m_second + t2.m_second;
    return t;
}

// Time Time::operator+(const Time &t)// ��Ա�������� +
// {
//     Time out;
//     out.m_hour = m_hour + t.m_hour;
//     out.m_minute = m_minute + t.m_minute;
//     out.m_second = m_second + t.m_second;
//     return out;

// }

// Time &Time::operator+=(const Time &t)     //��Ա����ʵ�� +=
// {
//     m_hour += t.m_hour;
//     m_minute += t.m_minute;
//     m_second += t.m_second;
//     return *this;
// }

Time &operator+=(Time &t1, const Time &t2)  //��Ԫ����ʵ�� +=
{
    t1.m_hour += t2.m_hour;
    t1.m_minute += t2.m_minute;
    t1.m_second += t2.m_second;

    return t1;
}

ostream &operator<<(ostream &os, const Time &t)  //������ʵ��
{
    os << t.m_hour << " : " << t.m_minute << " : " << t.m_second << endl;
    return os;
}

// bool operator==(Time &t1, const Time &t2)  //��Ԫ����ʵ�� ==
// {
//     if((t1.m_hour == t2.m_hour) && (t1.m_minute == t2.m_minute) && (t1.m_second == t2.m_second))
//     {
//          return 1;
//     }
//     return 0;
// }

bool Time::operator==(Time &t)  //��Ա�������� ==
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
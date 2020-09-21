#include <iostream>
using namespace std;

////////////////////////////////////Time类///////////////////////////////////////
class Time
{
public:
    Time() { m_hour = m_minute = m_second = 0; }
    Time(int hour, int minute, int second)
    {
        m_hour = hour;
        m_minute = minute;
        m_second = second;
    }
    void display() const { cout << m_hour << ":" << m_minute << ":" << m_second << endl; }

    Time &operator+=(const Time &t);                       // a += b; a.operator+=(b);
    friend Time operator+(const Time &t1, const Time &t2); // c = a + b; c = operator+(a, b);
    friend bool operator>(const Time &t1, const Time &t2);

    /// cout 是 ostream 的对象
    friend ostream &operator<<(ostream &os, const Time &t); /// cout << a << endl;  cout << t << endl;
    
    friend Time &operator++(Time &t);
    Time operator++(int); // t++; 参数其标识作用 ~ 亚元

private:
    int m_hour;
    int m_minute;
    int m_second;
};
bool operator>(const Time &t1, const Time &t2)
{
    int tt1 = t1.m_hour * 3600 + t1.m_minute * 60 + t1.m_second;
    int tt2 = t2.m_hour * 3600 + t2.m_minute * 60 + t2.m_second;
    if(tt1 > tt2)
    {
        return true;
    }
    return false;
}
Time &operator++(Time &t)
{
    cout << "const Time & operator++(Time &t)" << endl;
    t.m_second++;
    return t;
}

Time Time::operator++(int) //time t2 = t1++;
{
    cout << "Time Time::operator++(int)" << endl;
    Time t = *this;
    this->m_second++;
    return t;
}

/// 0.确定友元还是成员函数来 重载运算符
/// 1.确定函数名 operator+;
/// 2.确定参数，引用与常引用
/// 3.确定返回值，传值 or 传引用
/// 4.根据运算符逻辑，实现函数

// int c = a + b;
Time operator+(const Time &t1, const Time &t2)
{
    Time t;
    t.m_hour = t1.m_hour + t2.m_hour;
    t.m_minute = t1.m_minute + t2.m_minute;
    t.m_second = t1.m_second + t2.m_second;

    return t;
}

Time &Time::operator+=(const Time &t) // a += b; a.operator+=(b);
{
    this->m_hour += t.m_hour;
    this->m_minute += t.m_minute;
    this->m_second += t.m_second;

    return *this;
}

ostream &operator<<(ostream &os, const Time &t) ///流运算符只能用友元重载 cout.operator<<(t);
{
    return os << t.m_hour << ":" << t.m_minute << ":" << t.m_second;
}

///////////////////////////////////函数模板////////////////////////////////////////


/// 函数模板将代表着不同类型的一组函数, 它们都使用相同的函数体, 这样可以实现代码重用,避免重复劳动
//\ template 申明模板函数或模板类的关键字
//\ <> 模板的形参表
//\ typename T 是一个虚拟的类型
template <typename T>
T add(T a, T b)
{
    cout << "template: " << sizeof(a) << ", ";
    return a + b;
}
////////////////////////////////////////bubblesort//////////////////////////
void print_arr(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
}
void print_arr(double *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// void BubbleSort(int *a, int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {
//             if (a[j] > a[j + 1])
//             {
//                 swap(a[j + 1], a[j]);
//             }
//         }
//     }
// }
template <typename T >
void print_arr(T a, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
}

template <typename V, typename T >
void BubbleSort(T a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                V temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
   
}
//////////////////////////////////////////////////////////////////类模板/////////////////////////////////////////////////////////////
template <class T>  // 类模板的说明
class Stack
{
public:
    Stack(int s = 10);
    ~Stack(){ 
        delete [] m_stackPtr;
    }
    void push(const T& t);
    T& pop();

    bool isEmpty() { return m_top == 0; }
    bool isFull() { return m_top == m_size; }

private:
    int m_size;	
    int m_top;
    T* m_stackPtr;
};
template <class T> 
Stack<T>::Stack(int s)
{
    m_size = s;
    m_top = 0;
    m_stackPtr = new T[m_size + 1];
}
template <class T> 
void Stack<T>::push(const T& t)
{
    m_stackPtr[m_top++] = t;
}

template <class T> 
T& Stack<T>::pop()
{
    return m_stackPtr[--m_top];
}
///////////////////////////////////Main()////////////////////////////////////////

int main()
{
    // Time t[5] = {Time(1, 2 , 3), Time(2, 2 , 3), Time(5, 2 , 3), Time(0, 2 , 3), Time(3, 2 , 3)};
    // print_arr(t, 5);
    // BubbleSort<Time>(t, 5);
    // print_arr(t, 5);
    Stack<Time> st(20);
    for(int i = 0; i < 20; i++)
    {
        if(!st.isFull())
        {
            st.push(Time(i, i + 1, i + 2));
        }else
        {
            cout << "Full!!!" << endl;
            break;
        }
        
    }
    for(int i = 0; i < 20; i++)
    {
        if(!st.isEmpty())
        {
            cout << st.pop() << ", " ;
        }else
        {
            cout << endl << "Empty!!!" << endl;
            break;
        }
        
    }

    return 0;
}
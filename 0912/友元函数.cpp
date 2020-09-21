#include <iostream>    
#include <math.h>
using namespace std;

class Point
{
public:
    Point(double x, double y)
    { 
        m_x = x;  
        m_y = y;
    }

    void display();
    
    friend double my_distance(Point a, Point b); //友元函数的申明

private:
    double m_x;
    double m_y;
};

void Point::display() ///成员函数的实现
{ 
    cout << "(" << m_x << "," << m_y << ")" << endl; 
}

double my_distance(Point a, Point b)  //友元函数的实现
{      
    double dx = a.m_x - b.m_x; 
    double dy = a.m_y - b.m_y;
    return sqrt(dx*dx + dy*dy);
}

int main()
{
    Point p1(3,4);
    Point p2(6,8);
    p1.display(); 
    p2.display();

    double d = my_distance(p1,p2);          //友元函数的调用
    cout << "Distance is " << d << endl;
    return 0;
}

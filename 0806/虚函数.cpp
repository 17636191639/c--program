#include <iostream>
using namespace std;

class Point
{
public:
    Point(int x, int y) { m_x = x; m_y = y;}
    ///对比虚函数与普通函数的区别
    virtual void print() const;

    int m_x, m_y;
};
void Point::print()const
{
   cout << "[" << m_x << "," << m_y << "]" << endl;
}

class Point3D:public Point
{
public:
    Point3D(int x, int y, int z);
    void print()const;
private:
    int m_z;
};
Point3D::Point3D(int x, int y, int z):Point(x,y)
{
    m_z = z;
}

void Point3D::print() const
{
    cout << "[" << m_x << "," << m_y << "," << m_z << "]" << endl;
}

int main()
{
    Point p(3,4);
    cout << sizeof(p) << endl;
    Point *p1 = new Point3D(3, 4, 5);
    cout << sizeof(Point3D) << endl;
    p1->print();
    return 0;
}

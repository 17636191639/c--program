#include <iostream>
#include <cstring>
using namespace std;

class GirlFriend
{
public:
    GirlFriend(const char *name, int age , int height, int weight);
    ~GirlFriend();
    void display();
    void kiss();
    void seduction();
private:
    char *m_name;
    int m_age;
    int m_height;
    int m_weight;
};

GirlFriend::GirlFriend(const char *name, int age , int height, int weight)
{
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    m_age = age;
    m_height = height;
    m_weight = weight;
}
GirlFriend::~GirlFriend()
{
    delete [] m_name;
}
void GirlFriend::display()
{
    cout << "name: " << m_name <<endl;
    cout << "age: " << m_age << "岁" <<endl;
    cout << "height: " << m_height << "cm" <<endl;
    cout << "weight: " << m_weight << "kg" <<endl;
}

void GirlFriend::kiss()
{
    cout << m_name <<"亲了你一口" << endl;

}
void GirlFriend::seduction()
{
    cout << m_name << "邀请你进入她的房间" << endl;
}

int main()
{
    // GirlFriend xins("张鑫的女朋友", 18, 165, 50);
    // xins.display();
    // xins.kiss();
    GirlFriend *dongs = new GirlFriend("大栋的nv友",30, 155, 100);
    cout << strlen("hello") << endl;
    dongs->display();
    dongs->seduction();
    dongs->kiss();
    delete [] dongs;
    return 0;
}
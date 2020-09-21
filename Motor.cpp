//#pragma once
//#include<Arduino.h>
#include <iostream>
#include <string>
using namespace std;

typedef void(*funInit)(void);
typedef void(*funOut)(int, int);

#define STOP 0
#define FOR 1
#define REV -1

class Motor
{
public:
    Motor(int Pin1, int Pin2, string name = "Motor");

    //~Motor(); //��������

    void init(funInit pwmInit, funOut pwmOut);

    void setPwmFreq(int Freq);
    int getPwmFreq();
    void setDir(int dir); 
    int getDir();
    void setSpeed(int speed); 
    int getSpeed();

    void motorRun();
private:
    funInit m_pwmInit; //pwm��ʼ������
    funOut m_pwmOut;   //pwm�������

    string m_name; 
    int m_pwmPin1;  //����˿�
    int m_pwmPin2;  //����˿�
   
    int m_pwmFreq; //pwmƵ������
    int m_dir;     //�����������
    int m_speed;   //���õ���ٶ�

};
void Motor::init(funInit pwmInit, funOut pwmOut)
{
    m_pwmInit = pwmInit;
    m_pwmOut = pwmOut;  //pwmOut()  �ڵ��ת��ʱ���
    m_pwmInit();  //��ʼ��ʱִ��pwm��ʼ��
}

Motor::Motor(int Pin1,int Pin2, string name)
{
    m_pwmPin1 = Pin1;
    m_pwmPin2 = Pin2;
    m_name = name;
    m_dir = STOP;
    m_pwmFreq = 1000;  
    m_speed = 0;   //��ʼ�ٶ�Ϊ0
}

void Motor::setPwmFreq(int Freq)
{
    m_pwmFreq = Freq;
}
int Motor::getPwmFreq()
{
    return m_pwmFreq;
}

void Motor::setDir(int dir = STOP)
{
    m_dir = dir;
} 
int Motor::getDir()
{
    return m_dir;
}

void Motor::setSpeed(int speed)
{
    m_speed = speed;
} 
int Motor::getSpeed()
{
    return m_speed;
}

void Motor::motorRun()
{
    if(m_dir == STOP)
    {
        m_pwmOut(m_pwmPin1, 0);
        m_pwmOut(m_pwmPin2, 0);
    }else if(m_dir == FOR)
    {
        m_pwmOut(m_pwmPin1, m_speed);
        m_pwmOut(m_pwmPin2, 0);
    }else
    {
        
        m_pwmOut(m_pwmPin1, 0);
        m_pwmOut(m_pwmPin2, m_speed);
    }
    
}
int main()
{
    
    return 0;
}

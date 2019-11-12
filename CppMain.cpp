//
//  CppMain.cpp
//  HelloC
//
//  Created by apple on 2019/11/11.
//  Copyright © 2019 apple. All rights reserved.
//

#include "CppMain.hpp"

using namespace std;

static void ioTest() {
    cout<<"Nice to meet you!"<<"\njiek"<<endl<<"break line"<<endl<<endl;
    
    int a,b;
    cout<<"input number:"<<endl;
    cin>>a>>b;
    cout<<"Get "<<a<<endl<<b<<endl;
}

static void ioTest1() {
    int num;//学生学号
    char sex;//性别
    double score1;//科目一成绩
    double score2;//科目二成绩
    double score3;//科目三成绩
    cout<<"Please input student's ID、‘M’ or ‘W’、score1、score2 and score3"<<endl;
    cin>>num>>sex>>score1>>score2>>score3;
    cout<<"ID:"<<num<<" "<<sex<<" Total score is:"<<score1+score2+score3<<endl;//输出该学生信息及总成绩
}

static void typeTest() {
    int a=9;
    int b=10;
    bool r;//定义布尔类型变量r
    r = a>b;
    cout<<r<<endl;
    cout<<"bool size is:"<<sizeof(r)<<endl;// 1
    cout<<"int size is:"<<sizeof(int)<<endl;// 4
    cout<<"char size is:"<<sizeof(char)<<endl;// 1
    cout<<"short size is:"<<sizeof(short)<<endl;// 2
    cout<<"float size is:"<<sizeof(float)<<endl;// 4
    cout<<"double size is:"<<sizeof(double)<<endl;// 8
    cout<<"long size is:"<<sizeof(long)<<endl;// 8
}

void operatorTest() {
    int num;//待判断的这个三位数
    int units_digit;//三位数中的个位
    int decade_digit;//三位数中的十位
    int hundreds_digit;//三位数中的百位
    cin>>num;
    units_digit = num%10;
    decade_digit = num%100/10;
    hundreds_digit = num/100;
    cout<<units_digit<<" "<<decade_digit<<" "<<hundreds_digit<<endl;
}

void choiceTest() {//input=371, result=1. otherwise=0
    int a;//待判断的这个三位数
    int ge;//三位数中的个位
    int shi;//三位数中的十位
    int bai;//三位数中的百位
    cin>>a;
    ge = a%10;
    shi = a%100/10;
    bai = a/100;
    if(ge*ge*ge+shi*shi*shi+bai*bai*bai == a)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
    
    cout<<endl;
    double x;
    double y;
    cin>>x;

    if(x<1)
    {
        y=x;
    }
    else if(x>=1 && x<10)
    {
        y=2*x-1;
    }
    else
    {
        y=3*x-11;
    }
    cout<<fixed<<setprecision(2)<<y<<endl;
}

void whileTest() {
    int a,b;
    while(cin>>a>>b)
    {
        cout<<a+b<<endl;
    }
}

int Reverse(char a[],char b[])
{
    int i=0,n;
    n=strlen(a);
    while(a[i]!='\0')
    {
        b[n-i-1]=a[i];
        i++;
    }
    b[n]='\0';
    return 0;
}

void testReverse()
{
    char str1[100];
    char str2[100];
    cin>>str1;
    Reverse(str1,str2);
    cout<<str2<<endl;
}

int addDefault(int a=3,int b=5)
{
    return a+b;
}
 void testAdd()
{
    cout<<addDefault(10,20)<<endl;//将10和20分别给a和b
    cout<<addDefault(30)<<endl;//将30给a，b为默认的5
    cout<<addDefault()<<endl;//使用a、b的默认值3和5
}

int add(int a,int b)
{
    cout<<"(int ,int)\t";
    return a+b;
}
double add(double a,double b)
{
    cout<<"(doble ,double)\t";
    return a+b;
}
double add(double a,int b)
{
    cout<<"(double ,int)\t";
    return a+b;
}
double add(int a,double b)
{
    cout<<"(int ,double)\t";
    return a+b;
}
void testOverloading()//重载
{
    cout<<add(2,3)<<endl;
    cout<<add(2.9,15.3)<<endl;
    cout<<add(10,9.9)<<endl;
    cout<<add(11.5,5)<<endl;
}

template<class T1,class T2>
T1 add(T1 x,T2 y)
{
    cout<<sizeof(T1)<<","<<sizeof(T2)<<"\t";
    return x+y;
}
void testTemplate()
{
    cout<<add(10,20)<<endl;// (int ,int)    30
    cout<<add(3.14,5.98)<<endl;//    (doble ,double)    9.12
    cout<<add('A',2)<<endl;//1,4 C
}


inline int Max(int a,int b)
{
    return a>b?a:b;
}
void testInline()
{
    cout<<Max(3,5)<<endl;
    cout<<Max(7,9)<<endl;
}

int main()
{
//    ioTest();//input output test
//    ioTest1();//input output test
//    typeTest();//基本类型测试
//    operatorTest();
//    choiceTest();//选择结构
//    whileTest();//循环结构
//    testReverse();
//    testAdd();//形参可自带缺省值
//    testOverloading();//重载
//    testTemplate();//模板 template
//    testInline();//测试内联函数 inline https://www.dotcpp.com/course/cpp/200014.html
    
//    testConstruction();//测试构造函数 Student
//    testClass();//测试类的定义 Student
//    testFunctionPointer();//指针 Student
//    testFriend();//测试友元函数
//    testClock();
    
    return 0;
}

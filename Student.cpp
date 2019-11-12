//
//  Student.cpp
//  HelloC
//
//  Created by apple on 2019/11/12.
//  Copyright © 2019 apple. All rights reserved.
//

#include "Student.hpp"

using namespace std;

void Student::print()
{
    cout<<num<<" "<<name<<" "<<score;
}
//const int Student::GetScore()
//{
//    cout<<score<<endl;
//    return score;
//}

void Student::printf()//在类外定义完整的print函数
{
    cout<<endl<<endl;
    cout<<"printf::: "<<num<<" "<<name<<" "<<score<<" "<<age<<endl;
}
Student::Student(int n,char *str,int s):num(n),score(s), age(123)//构造中赋值
{
    //    num = n;
    this->name = new char[strlen(str)+1];
    //    strcpy(name,str);
    //    score = s;
    cout<<"Constructor"<<endl;
}
void Student::Set(int n,char *str,int s)
{
    num = n;
    strcpy(name,str);
    score = s;
}
Student::~Student()//cpp 析构函数
{
    cout<<num<<" "<<name<<" "<<score<<" ";
    cout<<"destructor"<<endl;
    delete []name;//释放 name 空间
}
Student::Student(Student &D):age(D.age) {
    cout<<"Copy Constructor"<<endl;
    this->num = D.num;
    //    this->name = new char[strlen(D.name)+1];//此两行的 this 打针形式都可行
    (*this).name = new char[strlen(D.name)+1];//
    strcpy(name, D.name);//深拷贝
    //    strcpy(this->name, D.name);//或写成指针指向 name
    this->score = D.score;
}

//--------------------

void testConstruction()
{
    Student A(100,"jiek",11);
    //    A.print();
    //    Student B(101,"frank",66);
    ////    A.printf();
    //    cout<<endl;
    
    Student C(A);
    C.num = 102;
    C.print();
    cout<<endl;
}

void testClass() {
    Student A(100, "jiek", 99);//直接构造对象，=java's new object
    A.num = 101;
    A.print();
    //    A.name = new char[10]
    strcpy(A.name, "jiek!!!");
    A.score = 100;
    //    A.print();
    A.printf();
}

void testFunctionPointer(){
    Student *p;
    Student A(100, "jiek", 99);//直接构造对象，=java's new object
    p = &A;
    A.num = 66;
    A.score = 99;
    p->print();
    //    p.printf();//此句为错误写法
    
    Student &Aq=A;//取别名
    Aq.printf();
}

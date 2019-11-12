//
//  Student.hpp
//  HelloC
//
//  Created by apple on 2019/11/12.
//  Copyright © 2019 apple. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include "iostream"
//#include<iomanip>
#include<math.h>

class Student
{
public:
    int num;
    char *name;//name[100];
    int score;
    const int age;
    void print();
    void printf();
    Student(int n,char *str,int s);//构造函数
    Student(Student &D);
    ~Student();//析构函数
    void Set(int n,char *str,int s);
//    const int GetScore();
};

//----------------
void testConstruction();
void testClass();
void testFunctionPointer();

#endif /* Student_hpp */

//
//  Point.cpp
//  HelloC
//
//  Created by apple on 2019/11/12.
//  Copyright © 2019 apple. All rights reserved.
//

#include "Point.hpp"

using namespace std;

Point::Point(double a,double b)
{
    x = a;
    y = b;
}

int Point::GetPoint()
{
    cout<<"("<<x<<","<<y<<")";
    return 0;
}

////求两点之间的距离
//double Point::Distance(Point &a,Point &b)
//{
//    double xx;
//    double yy;
//    xx = a.x-b.x;
//    yy = a.y-b.y;
//
//    return sqrt(xx*xx+yy*yy);
//}

double Tool::GetX(Point &A)
{
    cout<<A.x<<endl;
    return A.x;
}
double Tool::GetY(Point &A)
{
    cout<<A.y<<endl;
    return A.y;
}
double Tool::dis(Point &A)//距离原点的距离
{
    cout<<sqrt(A.x*A.x+A.y*A.y)<<endl;
    return  sqrt(A.x*A.x+A.y*A.y);
}


//----------------

void testFriend()
{
    Point A(2.0,3.0);
    Point B(1.0,2.0);
    double dis;
    dis = 1.2345678;
    dis = Distance(A,B);//友元调用
    //    dis = A.Distance(A,B);//普通函数调用
    cout<<setw(13)<<dis<<endl;
    cout<<setprecision(10)<<dis<<endl;//精度输出，3位有效数
    cout<<setw(32)<<setprecision(10)<<dis<<endl;//设置占位量
    cout<<setw(13)<<dis<<endl;
    
    //    cout<<A.a()<<endl;
    
    Tool T;
    T.GetX(A);
    T.GetY(A);
    T.dis(A);
}

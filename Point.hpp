//
//  Point.hpp
//  HelloC
//
//  Created by apple on 2019/11/12.
//  Copyright © 2019 apple. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include "iostream"
#include<math.h>
#include<iomanip>

class Point
{
private:
public:
    double x;
    double y;
    Point(double a,double b);
    int GetPoint();
    //    double Distance(Point &a,Point &b);
    friend    double Distance(Point &a,Point &b)//友元函数
    {
        double xx;
        double yy;
        xx = a.x-b.x;
        yy = a.y-b.y;
        
        return sqrt(xx*xx+yy*yy);
    };
    friend class Tool;//友元类
    //    int a();
};

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
//int Point::a() {
//    return 23;
//}

class Tool
{
public:
    double GetX(Point &A);
    double GetY(Point &A);
    double dis(Point &A);//距离原点的距离
};

//----------------
void testFriend();

#endif /* Point_hpp */

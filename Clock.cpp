//
//  Clock.cpp
//  HelloC
//
//  Created by apple on 2019/11/12.
//  Copyright © 2019 apple. All rights reserved.
//

#include "Clock.hpp"
#include <stdio.h>
#include "iostream"
#include<iomanip>

using namespace std;

int Clock::SetTime(int h,int m,int s)
{
    this->H = h;
    this->M = m;
    this->S = s;
    return 0;
}
void Clock::ShowTime()
{
    cout<<"Now:"<<H<<":"<<M<<":"<<S<<endl;
}


int AlarmClock::SetAlarm(int AH,int AM)
{
    this->AH = AH;
    this->AM = AM;
    return 0;
}
int AlarmClock::ShowAlarm()
{
    cout<<"AlarmTime:"<<AH<<":"<<AM<<endl;
    return 0;
}

//----------------

void testClock() {
    AlarmClock A;
    A.SetTime(19,15,50);
    A.ShowTime();
    A.SetAlarm(5,30);
    A.ShowAlarm();
}

//
//  Clock.hpp
//  HelloC
//
//  Created by apple on 2019/11/12.
//  Copyright © 2019 apple. All rights reserved.
//

#ifndef Clock_hpp
#define Clock_hpp

class Clock
{
private:
    int H;
    int M;
    int S;
public:
    int SetTime(int h,int m,int s);
    void ShowTime();
};

class AlarmClock:public Clock//冒号表示继承，其中public表示公有继承、private私有继承和protected保护继承
{
private:
    int AH;
    int AM;
public:
    int SetAlarm(int AH,int AM);
    int ShowAlarm();
};


//----------------
void testClock();

#endif /* Clock_hpp */

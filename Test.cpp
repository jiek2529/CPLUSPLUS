//
//  Test.cpp
//  HelloC
//
//  Created by apple on 2019/11/12.
//  Copyright © 2019 apple. All rights reserved.
//

#include "Test.hpp"
#include <stdio.h>
#include "iostream"

using namespace std;

Test::Test()
{
    cout<<"Hello World!"<<endl;
}

Test::~Test()
{
    cout<<"GoodBye!"<<endl;
}

void Test::Sumk()
{
    k = i + j;
}

#ifndef VISITOR_H_
#define VISITOR_H_

#include <iostream>
#include <string>

typedef unsigned int uint;

class Visitor
{
    Visitor();
    virtual ~Visitor();
    void getBicycleInfo();//获得部分车辆信息
    void getAvaiableBicycleInfo();
}
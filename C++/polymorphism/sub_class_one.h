#pragma once
#include "super_class.h"

class SubClassOne: public SuperClass
{
public:
    void print() override
    {
        SuperClass::print(); // to call print method of super class
        std::cout << "SubClassOne print()" << std::endl;
    }
};
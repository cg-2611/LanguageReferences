#pragma once
#include "super_class.h"

class SubClassTwo: public SuperClass
{
public:
    void print() override
    {
        std::cout << "SubClassTwo print()" << std::endl;
    }
};

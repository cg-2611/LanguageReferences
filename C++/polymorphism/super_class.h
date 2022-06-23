#pragma once
#include <iostream>

class SuperClass
{
public:
    virtual void print()
    {
        std::cout << "SuperClass print()" << std::endl;
    }
};

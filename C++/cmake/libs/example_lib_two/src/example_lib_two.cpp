#include <iostream>

#include "example_lib_two/example_lib_two_interface.h"

// libexample_lib_two.a created using (in ./..):
//      clang++ -I./include -c src/example_lib_two.cpp
//      ar rcs libexample_lib_two.a example_lib_two.o

ExampleClassTwo::ExampleClassTwo(int value)
{
    this->value = value;
}

int ExampleClassTwo::getValue()
{
    return this->value;
}

void ExampleClassTwo::printValue()
{
    std::cout << "Example Class Two value = " << this->getValue() << std::endl;
}

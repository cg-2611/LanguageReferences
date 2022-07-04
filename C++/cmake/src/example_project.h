#pragma once

#include <example_lib_one/example_lib_one_interface.h>

#include <example_lib_two/example_lib_two_interface.h>

class ExampleProjectClass
{
private:
    ExampleClassOne *exampleClassOne;
    ExampleClassTwo *exampleClassTwo;
public:
    ExampleProjectClass(char *string, int value);

    ExampleClassOne getExampleClassOne();
    ExampleClassTwo getExampleClassTwo();
};

#include "example_project.h"

ExampleProjectClass::ExampleProjectClass(char *string, int value)
{
    this->exampleClassOne = new ExampleClassOne(string);
    this->exampleClassTwo = new ExampleClassTwo(value);
}

ExampleClassOne ExampleProjectClass::getExampleClassOne()
{
    return *(this->exampleClassOne);
}

ExampleClassTwo ExampleProjectClass::getExampleClassTwo()
{
    return *(this->exampleClassTwo);
}

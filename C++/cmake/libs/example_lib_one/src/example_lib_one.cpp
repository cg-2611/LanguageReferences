#include <iostream>
#include <string>

#include "example_lib_one/example_lib_one_interface.h"

ExampleClassOne::ExampleClassOne(char *string)
{
    this->string = new char[strlen(string) + 1];

    if (this->string)
    {
        strcpy(this->string, string);
    }

}

ExampleClassOne::~ExampleClassOne()
{
    delete[] this->string;
}

char * ExampleClassOne::getString()
{
    return this->string;
}

void ExampleClassOne::printString()
{
    std::cout << "Example Class One string: " << this->getString() << std::endl;
}

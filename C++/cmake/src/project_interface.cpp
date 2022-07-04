#include "example_project/project_interface.h"

ProjectInterfaceClass::ProjectInterfaceClass(char *string, int value)
{
    this->exampleProjectClass = new ExampleProjectClass(string, value);
}

ProjectInterfaceClass::~ProjectInterfaceClass()
{
    delete this->exampleProjectClass;
}

ExampleProjectClass ProjectInterfaceClass::getExampleProjectClass()
{
    return *(this->exampleProjectClass);
}

void ProjectInterfaceClass::printMembers()
{
    this->getExampleProjectClass().getExampleClassOne().printString();
    this->getExampleProjectClass().getExampleClassTwo().printValue();
}

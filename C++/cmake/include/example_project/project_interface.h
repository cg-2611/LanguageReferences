#pragma once

#include "example_project.h"

class ProjectInterfaceClass
{
private:
    ExampleProjectClass *exampleProjectClass;
public:
    ProjectInterfaceClass(char *string, int value);
    ~ProjectInterfaceClass();

    ExampleProjectClass getExampleProjectClass();
    void printMembers();
};

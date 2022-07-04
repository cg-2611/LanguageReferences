#include "example_project/project_interface.h"

// IMPORTANT: THIS EXAMPLE IS FOR DEMONSTRATION PURPOSES ONLY AND SHOULD ONLY BE USED FOR REFERENCE
//            THERE ARE MEMORY LEAKS IN THIS PROGRAM THAT SHOULD NOT BE IGNORED

// build using:
//      mkdir build
//      cd build
//      cmake ..
//      make

// run using:
//      ./example_project

int main(int argc, char const *argv[])
{
    ProjectInterfaceClass projectInterface = ProjectInterfaceClass("example string", 19);

    projectInterface.printMembers();

    return 0;
}

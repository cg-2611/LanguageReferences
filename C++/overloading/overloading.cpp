#include <iostream>
#include <string>

// c++ allows all operators to be overloaded in a class, or as a function

// note the following example would be much better implemented using a template and variable arguments

void print_arguments(std::string arg)
{
    std::cout << arg << std::endl;
}

void print_arguments(std::string arg1, std::string arg2)
{
    std::cout << arg1 << " and " << arg2 << std::endl;
}

void print_arguments(std::string arg1, std::string arg2, std::string arg3)
{
    std::cout << arg1 << ", " << arg2 << " and " << arg3 << std::endl;
}

void print_arguments(int arg)
{
    std::cout << arg << std::endl;
}

void print_arguments(int arg1, int arg2)
{
    std::cout << arg1 << " and " << arg2 << std::endl;
}

void print_arguments(int arg1, int arg2, int arg3)
{
    std::cout << arg1 << ", " << arg2 << " and " << arg3 << std::endl;
}

int main(int argc, char const *argv[])
{
    print_arguments("Argument 1");
    print_arguments(2);

    print_arguments("Argument 1", "Argument 2");
    print_arguments(2, 4);

    print_arguments("Argument 1", "Argument 2", "Argument 3");
    print_arguments(2, 4, 6);

    return 0;
}

#include <iostream>

// variable arguments in c++ can be done the same way as c using cstdarg instead of stdarg.h
// however, they can also be done in the following way

template<class... Args>
void print_args(Args... args)
{
    (std::cout << ... << args) << std::endl;
}

int main(int argc, char const *argv[])
{
    print_args(1, "Argument 1");
    print_args(2, "Argument 1", "Argument 2");
    print_args(3, "Argument 1", "Argument 2", "Argument 3");
    print_args(6, "Argument 1", "Argument 2", "Argument 3", "Argument 4", "Argument 5", "Argument 6");

    return 0;
}

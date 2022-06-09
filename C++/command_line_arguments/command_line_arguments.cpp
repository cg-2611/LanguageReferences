#include <iostream>

int main(int argc, char const *argv[])
{
    // argc always >= 1 as program name is counted

    std::cout << "Number of arguments passed: " << argc << "\n\n";

    for (size_t i = 0; i < argc; i++) {
        std::cout << "Argument " << (i + 1) << ": " << argv[i] << std::endl;
    }

    std::cout << "First argument provided:" <<  argv[0] << std::endl;
    std::cout << "Last argument provided:" <<  argv[argc - 1] << std::endl;

    return 0;
}

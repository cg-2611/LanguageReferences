#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    // c input and output functions can also be used

    char character;
    std::cout << "Enter character: ";
    std::cin >> character;
    std::cout << "Character entered: " << character << std::endl;

    std::string string;
    std::cout << "\nEnter string: ";
    std::cin >> string;
    std::cout << "String entered: " << string << std::endl;

    int integer;
    std::cout << "\nEnter integer: ";
    std::cin >> integer;
    std::cout << "Integer entered: " << integer << std::endl;

    return 0;
}

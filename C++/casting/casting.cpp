#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{

    // all functions can be passed a base as an argument to convert to different number systems

    // converting between strings and integers
    std::string integer_as_string = "36";

    int integer = std::stoi(integer_as_string);
    std::cout << "string = " << integer_as_string << " integer = " << integer << std::endl;

    integer = 42;
    std::string string_from_integer = std::to_string(integer);
    std::cout << "integer = " << integer << " string = " << string_from_integer << std::endl;

    // converting between strings and floats, the same can be applied to doubles
    std::string float_as_string = "124.157";

    float float_from_string = std::stof(float_as_string);
    std::cout << "string = " << float_as_string << " float = " << float_from_string << std::endl;

    float string_as_float = 341.224;
    std::string string_from_float = std::to_string(string_as_float);
    std::cout << "float = " << string_as_float << " string = " << string_from_float << std::endl;

    return 0;
}

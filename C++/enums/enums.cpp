#include <iostream>

// by defining VALUE_4 = 4, the enumeration will being at 4
// e.g. VALUE_5 = 5 (VALUE_4 + 1) and VALUE_6 = 6 (VALUE_5 + 1)
enum non_scoped_example1
{
    VALUE_4 = 4,
    VALUE_5,
    VALUE_6
};

// the next enum will be one more than the previous, unless specified otherwise
// type of an enum is int by default, here the enum type is changed to a short
enum non_scoped_example2 : short
{
    VALUE_2 = 1,
    VALUE_7 = 7,
    VALUE_8,
    VALUE_11 = 11,
    VALUE_12,
    VALUE_13
};

// scoped enum
// enum is scoped to class Days, the default type is an int, but can be changed to short for example
// the days class must be defined for this to work
enum class Days : short {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main(int argc, char const *argv[])
{
    enum non_scoped_example1 non_scoped_example_enum1;
    non_scoped_example_enum1 = VALUE_4;
    std::cout << "non_scoped_example_enum1 = " << non_scoped_example_enum1 << std::endl;
    non_scoped_example_enum1 = VALUE_5;
    std::cout << "non_scoped_example_enum1 = " << non_scoped_example_enum1 << std::endl;
    non_scoped_example_enum1 = VALUE_6;
    std::cout << "non_scoped_example_enum1 = " << non_scoped_example_enum1 << std::endl << std::endl;

    enum non_scoped_example2 non_scoped_example_enum2;
    non_scoped_example_enum2 = VALUE_2;
    std::cout << "non_scoped_example_enum2 = " << non_scoped_example_enum2 << std::endl;
    non_scoped_example_enum2 = VALUE_7;
    std::cout << "non_scoped_example_enum2 = " << non_scoped_example_enum2 << std::endl;
    non_scoped_example_enum2 = VALUE_8;
    std::cout << "non_scoped_example_enum2 = " << non_scoped_example_enum2 << std::endl;
    non_scoped_example_enum2 = VALUE_11;
    std::cout << "non_scoped_example_enum2 = " << non_scoped_example_enum2 << std::endl;
    non_scoped_example_enum2 = VALUE_12;
    std::cout << "non_scoped_example_enum2 = " << non_scoped_example_enum2 << std::endl;
    non_scoped_example_enum2 = VALUE_13;
    std::cout << "non_scoped_example_enum2 = " << non_scoped_example_enum2 << std::endl << std::endl;

    return 0;
}

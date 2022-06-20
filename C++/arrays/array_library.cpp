#include <array>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::array<int, 4> array = {5, 6, 7, 8};

    // iterate using a for loop:
    for (size_t i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    // change index 0 of array
    array[0] = 4;

    // iterate using a for each loop
    for (const int x : array)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    std::array<int, 6> array_1 = {2, 3, 4}; // initialises as [2, 3, 4, 0, 0, 0]

    // iterate using a for loop:
    for (size_t i = 0; i < array_1.size(); i++)
    {
        std::cout << array_1[i] << " ";
    }

    std::cout << std::endl;

    // change index 4 and 5 of array
    array_1[4] = 8;
    array_1[5] = 9;

    // iterate using a for each loop
    for (const int x : array_1)
    {
        std::cout << x << " ";
    }

    return 0;
}

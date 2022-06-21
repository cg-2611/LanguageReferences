#include <iostream>

/*
    memory allocation using malloc, calloc, realloc and free can be used the same as in C using the <cstdlib> header

    when using these functions in c++, the result of the function call must be cast from a void* to whatever the
    pointer type is of the pointer being assigned the allocation, e.g. int* array = (int*)malloc(32 * sizeof(*array));
*/

int main(int argc, char const *argv[])
{
    // allocate memory to store values
    int* int_p = new int;
    float* float_p = new float;

    // assign values
    *int_p = 23;
    *float_p = 57.9;

    std::cout << "int_p = " << *int_p << std::endl;
    std::cout << "float_p = " << *float_p << std::endl;

    // free memory after use
    delete int_p;
    delete float_p;


    std::cout << "\narray allocation:" << std::endl;

    const int ARRAY_SIZE = 32;
    int* array = new int[ARRAY_SIZE]; // allocate memory for an array of 32 integers

    // assign values
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = i * i;
    }

    // print values
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    delete[] array; // deallocate array memory

    return 0;
}

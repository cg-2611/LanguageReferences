#include <iostream>

int main(int argc, char const *argv[])
{
    const int array_rows = 3;
    const int array_columns = 5;

    std::cout << "Static 2D array:" << std::endl;

    // static 2D array, memory allocated on the stack
    int static_array[3][5] = {
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {2, 3, 5, 1, 4}
    };

    for (size_t i = 0; i < array_rows; i++)
    {
        for (size_t j = 0; j < array_columns; j++)
        {
            std::cout << static_array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nDynamic 2D array:" << std::endl;

    // dynamic 2D array, using malloc and free, memory allocated on the heap
    // allocate memory to store the pointers to the arrays stored in the 2d array
    int **array = (int**) malloc(array_rows * sizeof(*array));

    // allocate memory to store the integers in each array
    for(size_t i = 0; i < array_rows; i++)
    {
        array[i] = (int*)malloc(array_columns * sizeof(*array[i]));
    }

    // assign values to each element of the individual arrays
    for (size_t i = 0; i < array_rows; i++)
    {
        for (size_t j = 0; j < array_columns; j++)
        {
            array[i][j] = (j + 1) + i;
        }
    }

    for (size_t i = 0; i < array_rows; i++)
    {
        for (size_t j = 0; j < array_columns; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // deallocate each individual array
    for(size_t i = 0; i < array_rows; i++)
    {
        free(array[i]);
        array[i] = NULL;
    }

    // deallocate array
    free(array);
    array = NULL;

    return 0;
}

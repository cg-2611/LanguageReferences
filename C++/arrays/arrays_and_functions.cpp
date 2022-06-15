#include <iostream>
#include <random>

std::random_device rd;

// returns a pointer to an array that contains a given number of random integers in range 1-99;
int* create_array(size_t array_size)
{
    int *array = (int*) malloc(array_size * sizeof(*array));

    // check if malloc successful
    if (array == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < array_size; i++)
    {
        array[i] = ((rd() % 99) + 1);
    }

    return array;
}

// returns an array with a new random number in range 1-99 added to the previous one in the array passed as an argument
int* update_array(int* array_to_update, size_t array_size)
{
    int *array = (int*) malloc(array_size * sizeof(*array));

    for (size_t i = 0; i < array_size; i++)
    {
        array[i] = array_to_update[i] + ((rd() % 99) + 1);
    }

    free(array_to_update);
    array_to_update = NULL;

    return array;
}

// prints the array provided as an argument
void print_array(int* array, size_t array_size)
{
    for (size_t i = 0; i < array_size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    const int ARRAY_SIZE = 16;

    int *int_array = create_array(ARRAY_SIZE);

    std::cout << "Array after creation:" << std::endl;
    print_array(int_array, ARRAY_SIZE);

    int_array = update_array(int_array, ARRAY_SIZE);

    std::cout << "\nArray after one update:" << std::endl;
    print_array(int_array, ARRAY_SIZE);

    int_array = update_array(int_array, ARRAY_SIZE);

    std::cout << "\nArray after two updates:" << std::endl;
    print_array(int_array, ARRAY_SIZE);

    free(int_array);
    int_array = NULL;

    return 0;
}

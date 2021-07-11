#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// returns a pointer to an array that contains a given number of random integers in range 1-99;
int *create_array(size_t array_size)
{
    int *array = malloc(array_size * sizeof(*array));

    if (array == NULL)
    {
        return NULL;
    }

    int i;
    for (i = 0; i < array_size; i++)
    {
        array[i] = ((rand() % 99) + 1);
    }

    return array;
}

// returns an array with a new random number in range 1-99 added to the previous one in the array passed as an argument
int *update_array(int *array_to_update, size_t array_size)
{
    int *array = malloc(array_size * sizeof(*array));

    int i;
    for (i = 0; i < array_size; i++)
    {
        array[i] = array_to_update[i] + ((rand() % 99) + 1);
    }

    free(array_to_update);
    array_to_update = NULL;

    return array;
}

// prints the array provided as an argument
void print_array(int *array, size_t array_size)
{
    int i;
    for (i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    const int ARRAY_SIZE = 16;

    srand(time(NULL));

    int *int_array = create_array(ARRAY_SIZE);

    printf("Array after creation:\n");
    print_array(int_array, ARRAY_SIZE);

    int_array = update_array(int_array, ARRAY_SIZE);

    printf("\nArray after one update:\n");
    print_array(int_array, ARRAY_SIZE);

    int_array = update_array(int_array, ARRAY_SIZE);

    printf("\nArray after two updates:\n");
    print_array(int_array, ARRAY_SIZE);

    free(int_array);
    int_array = NULL;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *arg[])
{
    int array_size = 8;
    int *array;

    printf("Initial memory allocation: ");
    // allocates memory on the heap for 8 int values
    // alternative is array = (int *)calloc(array_size, sizeof(int)); which will also initialize each element to 0
    array = (int *)malloc(sizeof(int) * 8);

    // good practice to check if the allocation was successful

    int i;

    // assign values to the array elemets
    for (i = 0; i < array_size; i++)
    {
        array[i] = i + 1;
    }

    for (i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n\nMemory reallocation: ");
    array_size *= 2;
    array = (int *)realloc(array, sizeof(int) * array_size);

    // assign values to the new 8 memory locations
    for(i = (array_size / 2) - 1; i < array_size; i++)
    {
        array[i] = i + 1;
    }

    for (i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);
    array = NULL;

    return 0;
}

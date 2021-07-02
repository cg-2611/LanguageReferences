#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    // allocate memory on the heap to store 32 characters (+ 1 for null terminator)
    char *string = (char *)malloc(sizeof(char) * (32 + 1));

    // return if memory allocation fails
    if (string == NULL)
    {
        return 1;
    }

    int i;
    for (i = 0; i < 32; i++)
    {
        string[i] = (rand() % 26) + 97; // assign each string character a random lowercase character
    }
    string[32] = '\0'; // add null terminator to end of string

    printf("%lu character string: %s\n", strlen(string), string);

    // resize memory on heap for string so it can store 64 (+1 for null terminator)
    string = (char *)realloc(string, sizeof(char) * (64 + 1));

    // return if memory reallocation fails
    if (string == NULL)
    {
        return 1;
    }

    for (i = 0; i < 64; i++)
    {
        string[i] = (rand() % 26) + 97; // assign each string character a random lowercase character
    }
    string[64] = '\0'; // add null terminator to end of string

    printf("%lu character string: %s\n", strlen(string), string);

    // deallocate the memory for string
    free(string);
    string = NULL;

    // allocate memory on the heap to store 16 integers and initialize each element to 0
    int *int_array = (int *)calloc(16, sizeof(int));

    // return if memory allocation fails
    if (int_array == NULL)
    {
        return 1;
    }

    printf("\nArray after initialization: ");
    for (i = 0; i < 16; i++)
    {
        printf("%d ", int_array[i]);
    }

    printf("\nArray after assignment: ");
    for (i = 0; i < 16; i++)
    {
        int_array[i] = rand() % 100; // assign each element a random number between 0 and 99
        printf("%d ", int_array[i]);
    }

    int_array = (int *)realloc(int_array, sizeof(int) * 32);

    // return if memory reallocation fails
    if (int_array == NULL)
    {
        return 1;
    }

    for (i = 0; i < 32; i++)
    {
        int_array[i] = rand() % 100; // assign each element a random number between 0 and 99
    }

    printf("\nArray after reallocation: ");
    for (i = 0; i < 32; i++)
    {
        printf("%d ", int_array[i]);
    }

    // deallocate the memory for int_array
    free(int_array);
    int_array = NULL;

    return 0;
}

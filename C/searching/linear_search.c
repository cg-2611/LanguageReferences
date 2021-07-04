#include <stdio.h>

int linear_search(int *array, size_t length, int target) {
    int i;
    for (i = 0; i < length; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int array[] = {9, 3, 2, 7, 1, 4, 5, 8, 6};
    size_t array_length = sizeof(array) / sizeof(int);

    printf("7 found at index: %d\n", linear_search(array, array_length, 7));
    printf("12 found at index: %d\n", linear_search(array, array_length,  12));

    return 0;
}

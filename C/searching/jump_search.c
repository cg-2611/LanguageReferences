#include <stdio.h>
#include <math.h>

int jump_search(int *array, size_t length, int target)
{
    double jump = sqrt(length), low = 0, high = jump;

    while (array[(int) fmin(high, length) - 1] < target)
    {
        low = high;
        high += jump;

        if (low >= length)
        {
            return -1;
        }
    }

    while (array[(int)low] < target)
    {
        low++;

        if (low == fmin(high, length))
        {
            return -1;
        }
    }

    if (array[(int)low] == target)
    {
        return (int)low;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t array_length = sizeof(array) / sizeof(int);

    printf("7 found at index: %d\n", jump_search(array, array_length, 7));
    printf("12 found at index: %d\n", jump_search(array, array_length,  12));

    return 0;
}

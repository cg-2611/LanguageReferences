#include <stdio.h>

int interpolation_search(int *array, size_t length, int target) {
    int low = 0, high = length - 1, mid;

    while ((array[high] != array[low]) && (target >= array[low]) && (target <= array[high]))
    {
        mid = low + ((target - array[low]) * (high - low)) / (array[high] - array[low]);

        if (target > array[mid])
        {
            low = mid + 1;
        }
        else if (target < array[mid])
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    if (target == array[low])
    {
        return low;
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

    printf("7 found at index: %d\n", interpolation_search(array, array_length, 7));
    printf("12 found at index: %d\n", interpolation_search(array, array_length,  12));

    return 0;
}

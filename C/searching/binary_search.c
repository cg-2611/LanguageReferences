#include <stdio.h>

int binary_search(int *array, size_t length, int target, int low, int high) {
    int mid = low  + ((high - low) / 2);

    if (high < low) {
        return -1;
    }

    if (target == array[mid]) {
        return mid;
    } else if (target < array[mid]) {
        return binary_search(array, length, target, low, mid - 1);
    } else {
        return binary_search(array,length, target, mid + 1, high);
    }
}

int main(int argc, char *argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t array_length = sizeof(array) / sizeof(int);

    printf("7 found at index: %d\n", binary_search(array, array_length, 7, 0, array_length - 1));
    printf("12 found at index: %d\n", binary_search(array, array_length,  12, 0, array_length - 1));

    return 0;
}

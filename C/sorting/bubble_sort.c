#include <stdio.h>

void bubble_sort(int *array, size_t length);
void optimized_bubble_sort(int *array, size_t length);
void swap(int *a, int *b);
void print_array(int *array, size_t length);

void bubble_sort(int *array, size_t length)
{
    int i, j;
    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }

        print_array(array, length);
    }
}

void optimized_bubble_sort(int *array, size_t length)
{
    int i = 0, j;
    int swapped = 0;

    while ((swapped == 0) && (i < length))
    {
        swapped = 1;
        for (j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = 0;
            }

        }

        i++;
        print_array(array, length);
    }
}

void swap(int *a_p, int *b_p)
{
    int temp = *a_p;
    *a_p = *b_p;
    *b_p = temp;
}

void print_array(int *array, size_t length)
{
    printf("[");
    int i;
    for(i = 0; i < length - 1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[length - 1]);
}

int main(int argc, char *argv[])
{
    int unsorted_array1[] = {9, 3, 2, 7, 1, 4, 5, 8, 6};
    size_t array_length = sizeof(unsorted_array1) / sizeof(int);
    printf("Unsorted Array 1:\n");
    print_array(unsorted_array1, array_length);

    printf("\nBubble Sort:\n");
    bubble_sort(unsorted_array1, array_length);

    int unsorted_array2[]  = {9, 3, 2, 7, 1, 4, 5, 8, 6};
    array_length = sizeof(unsorted_array2) / sizeof(int);
    printf("\nUnsorted Array 2:\n");
    print_array(unsorted_array2, array_length);

    printf("\nOptimized Bubble Sort:\n");
    optimized_bubble_sort(unsorted_array2, array_length);

    return 0;
}

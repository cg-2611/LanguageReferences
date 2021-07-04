#include <stdio.h>

void insertion_sort(int *array, size_t length);
void print_array(int *array, size_t length);

void insertion_sort(int *array, size_t length)
{
    int i;
    for (i = 1; i < length; i++)
    {
        int element_to_insert = array[i];
        int previous = i - 1;

        while ((previous >= 0) && (array[previous] > element_to_insert))
        {
            array[previous + 1] = array[previous];
            previous--;
        }

        array[previous + 1] = element_to_insert;
        print_array(array, length);
    }
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
    int unsorted_array[] = {9, 3, 2, 7, 1, 4, 5, 8, 6};
    size_t array_length = sizeof(unsorted_array) / sizeof(int);
    printf("Unsorted Array:\n");
    print_array(unsorted_array, array_length);

    printf("\nInsertion Sort:\n");
    insertion_sort(unsorted_array, array_length);

    return 0;
}
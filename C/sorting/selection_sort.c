#include <stdio.h>

void selection_sort(int *array, size_t length);
void swap(int *a_p, int *b_p);
void print_array(int *array, size_t length);

void selection_sort(int *array, size_t length)
{
    int i, j, smallest_index;
    for (i = 0; i < length - 2; i++)
    {
        smallest_index = i;
        for (j = i + 1; j < length; j++)
        {
            if (array[j] < array[smallest_index])
            {
                smallest_index = j;
            }
        }

        swap(&array[i], &array[smallest_index]);

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
    int unsorted_array[] = {9, 3, 2, 7, 1, 4, 5, 8, 6};
    size_t array_length = sizeof(unsorted_array) / sizeof(int);
    printf("Unsorted Array:\n");
    print_array(unsorted_array, array_length);

    printf("\nInsertion Sort:\n");
    selection_sort(unsorted_array, array_length);

    return 0;
}
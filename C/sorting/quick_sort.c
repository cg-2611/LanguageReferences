#include <stdio.h>

int partition(int *array, size_t length, int start, int end);
void quick_sort(int *array, size_t length, int stat, int end);
void swap(int *a_p, int *b_p);
void print_array(int *array, size_t length);

int partition(int *array, size_t length, int start, int end)
{
    int pivot = array[end];
    int i = start - 1, j;

    for (j = start; j < end; j++)
    {
        if (array[j] <= pivot)
        {
            i++;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[end]);

    print_array(array, length);

    return i + 1;
}

void quick_sort(int *array, size_t length, int start, int end)
{
   if (start < end)
   {
        int partition_index = partition(array, length, start, end);

        quick_sort(array, length, start, partition_index - 1);
        quick_sort(array, length, partition_index + 1, end);
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
    quick_sort(unsorted_array, array_length, 0, array_length - 1);

    return 0;
}

#include <stdio.h>

void merge(int *array, size_t length, int *left, int *right, int left_index, int right_index);
void merge_sort(int *array, size_t length);
void print_array(int *array, size_t length);

void merge(int *array, size_t length, int *left, int *right, int left_index, int right_index) {
    int i = 0, j = 0, k = 0;

        while (i < left_index && j < right_index)
        {
            if (left[i] <= right[j])
            {
                array[k++] = left[i++];
            }
            else
            {
                array[k++] = right[j++];
            }
        }

        while (i < left_index)
        {
            array[k++] = left[i++];
        }

        while (j < right_index)
        {
            array[k++] = right[j++];
        }

        print_array(array, length);
}

void merge_sort(int *array, size_t length)
{
    if (length < 2)
    {
        return;
    }

    int mid = length / 2;
    int left[mid];
    int right[length - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }

    for (int i = mid; i < length; i++) {
        right[i - mid] = array[i];
    }

    merge_sort(left, mid);
    merge_sort(right, length - mid);

    merge(array, length, left, right, mid, length - mid);
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
    merge_sort(unsorted_array, array_length);

    return 0;
}

#include <iostream>
#include <vector>

int partition(std::vector<int> &array, int start, int end);
void quick_sort(std::vector<int> &array, int stat, int end);
void print_array(std::vector<int> array);

int partition(std::vector<int> &array, int start, int end)
{
    int pivot = array[end];
    int i = start - 1, j;

    for (j = start; j < end; j++)
    {
        if (array[j] <= pivot)
        {
            i++;

            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[end]);

    print_array(array);

    return i + 1;
}

void quick_sort(std::vector<int> &array, int start, int end)
{
   if (start < end)
   {
        int partition_index = partition(array, start, end);

        quick_sort(array, start, partition_index - 1);
        quick_sort(array, partition_index + 1, end);
    }
}

void print_array(std::vector<int>array)
{
    std::cout << "[";
    for(size_t i = 0; i < array.size() - 1; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout <<  array[array.size() - 1] << "]" << std::endl;
}

int main(int argc, const char *argv[])
{
    std::vector<int> unsorted_array = {9, 3, 2, 7, 1, 4, 5, 8, 6};
    printf("Unsorted Array:\n");
    print_array(unsorted_array);

    printf("\nQuick Sort:\n");
    quick_sort(unsorted_array, 0, unsorted_array.size() - 1);

    return 0;
}

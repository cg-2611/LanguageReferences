#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> array);
void optimized_bubble_sort(std::vector<int>array);
void swap(int *a, int *b);
void print_array(std::vector<int>array);

void bubble_sort(std::vector<int>array)
{
    for (size_t i = 0; i < array.size() - 1; i++)
    {
        for (size_t j = 0; j < array.size() - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }

        print_array(array);
    }
}

void optimized_bubble_sort(std::vector<int> array)
{
    size_t i = 0;
    bool swapped = true;

    while ((swapped == true) && (i < array.size()))
    {
        swapped = false;
        for (size_t j = 0; j < array.size() - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }

        }

        i++;
        print_array(array);
    }
}

void swap(int *a_p, int *b_p)
{
    int temp = *a_p;
    *a_p = *b_p;
    *b_p = temp;
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
    std::vector<int> unsorted_array1 = {9, 3, 2, 7, 1, 4, 5, 8, 6};
    std::cout << "Unsorted Array 1:" << std::endl;
    print_array(unsorted_array1);

    std::cout << "\nBubble Sort:" << std::endl;
    bubble_sort(unsorted_array1);

    std::vector<int> unsorted_array2 = {9, 3, 2, 7, 1, 4, 5, 8, 6};
    std::cout << "\nUnsorted Array 2:" << std::endl;
    print_array(unsorted_array2);

    std::cout << "\nOptimised Bubble Sort:" << std::endl;
    optimized_bubble_sort(unsorted_array2);

    return 0;
}

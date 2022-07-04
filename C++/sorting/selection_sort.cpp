#include <iostream>
#include <vector>

void selection_sort(std::vector<int> array);
void swap(int *a_p, int *b_p);
void print_array(std::vector<int> array);

void selection_sort(std::vector<int> array)
{
    for (size_t i = 0; i < array.size() - 2; i++)
    {
        size_t smallest_index = i;
        for (size_t j = i + 1; j < array.size(); j++)
        {
            if (array[j] < array[smallest_index])
            {
                smallest_index = j;
            }
        }

        swap(&array[i], &array[smallest_index]);

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

    std::cout << "\nInsertion Sort:" << std::endl;
    selection_sort(unsorted_array1);

    return 0;
}


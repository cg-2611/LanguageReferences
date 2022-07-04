#include <iostream>
#include <vector>

void selection_sort(std::vector<int> &array);
void print_array(std::vector<int> array);

void selection_sort(std::vector<int> &array)
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

        std::swap(array[i], array[smallest_index]);

        print_array(array);
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
    std::cout << "Unsorted Array :" << std::endl;
    print_array(unsorted_array);

    std::cout << "\nSelection Sort:" << std::endl;
    selection_sort(unsorted_array);

    return 0;
}

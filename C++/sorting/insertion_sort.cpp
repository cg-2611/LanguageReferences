#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> &array);
void print_array(std::vector<int> array);

void insertion_sort(std::vector<int> &array)
{
    for (size_t i = 1; i < array.size(); i++)
    {
        int element_to_insert = array[i];
        int previous = i - 1;

        while ((previous >= 0) && (array[previous] > element_to_insert))
        {
            array[previous + 1] = array[previous];
            previous--;
        }

        array[previous + 1] = element_to_insert;
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
    std::cout << "Unsorted Array:" << std::endl;
    print_array(unsorted_array);

    std::cout << "\nInsertion Sort:" << std::endl;
    insertion_sort(unsorted_array);

    return 0;
}

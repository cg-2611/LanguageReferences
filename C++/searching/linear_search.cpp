#include <iostream>
#include <vector>

int linear_search(std::vector<int> array, int target)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main(int argc, const char *argv[])
{
    std::vector<int> array = {9, 3, 2, 7, 1, 4, 5, 8, 6};

    std::cout << "7 found at index: " << linear_search(array, 7) << std::endl;
    std::cout << "12 found at index: " << linear_search(array, 12) << std::endl;

    return 0;
}

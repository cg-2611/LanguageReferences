#include <iostream>
#include <vector>

int interpolation_search(std::vector<int> array, int target)
{
    int low = 0, high = array.size() - 1, mid;

    while ((array[high] != array[low]) && (target >= array[low]) && (target <= array[high]))
    {
        mid = low + ((target - array[low]) * (high - low)) / (array[high] - array[low]);

        if (target > array[mid])
        {
            low = mid + 1;
        }
        else if (target < array[mid])
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    if (target == array[low])
    {
        return low;
    }
    else
    {
        return -1;
    }
}

int main(int argc, const char *argv[])
{
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "7 found at index: " << interpolation_search(array, 7) << std::endl;
    std::cout << "12 found at index: " << interpolation_search(array, 12) << std::endl;

    return 0;
}
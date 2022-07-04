#include <iostream>
#include <vector>

int binary_search(std::vector<int> array, int target, int low, int high)
{
    int mid = low  + ((high - low) / 2);

    if (high < low) {
        return -1;
    }

    if (target == array[mid]) {
        return mid;
    } else if (target < array[mid]) {
        return binary_search(array, target, low, mid - 1);
    } else {
        return binary_search(array, target, mid + 1, high);
    }
}

int main(int argc, const char *argv[])
{
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "7 found at index: " << binary_search(array, 7, 0, array.size() - 1) << std::endl;
    std::cout << "12 found at index: " << binary_search(array, 12, 0, array.size() - 1) << std::endl;

    return 0;
}


#include <cmath>
#include <iostream>
#include <vector>

int jump_search(std::vector<int> array, int target)
{
    size_t length = array.size();
    double jump = sqrt(length), low = 0, high = jump;

    while (array[(int) fmin(high, length) - 1] < target)
    {
        low = high;
        high += jump;

        if (low >= length)
        {
            return -1;
        }
    }

    while (array[(int)low] < target)
    {
        low++;

        if (low == fmin(high, length))
        {
            return -1;
        }
    }

    if (array[(int)low] == target)
    {
        return (int)low;
    }
    else
    {
        return -1;
    }
}

int main(int argc, const char *argv[])
{
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "7 found at index: " << jump_search(array, 7) << std::endl;
    std::cout << "12 found at index: " << jump_search(array, 12) << std::endl;

    return 0;
}
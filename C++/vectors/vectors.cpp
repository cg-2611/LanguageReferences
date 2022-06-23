#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    // vectors are not indexable
    // std::vector<int> vector(5, 12) is equivalent to std::vector<int> vector = {12, 12, 12, 12, 12}
    std::vector<int> vector = {5, 6, 7, 8};

    // iterate using for loop
    for (size_t i = 0; i < vector.size(); i++)
    {
        // can also use vector[i], however, this does not throw an out of bounds exception
        // vectors also support front() and back() methods for access
        std::cout << vector.at(i) << " ";
    }

    std::cout << std::endl;

    // can also use insert() and emplace to add elements
    vector.push_back(9); // pushed 9 to back of vector
    vector.at(0) = 4; // sets value of index 0 to 4
    vector.push_back(11); // pushed 11 to back of vector

    // iterate using for each loop
    for (const int x : vector)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    vector.pop_back(); // remove last value from vector

    // iterate using for each loop
    for (const int x : vector)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    return 0;
}

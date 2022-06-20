#include <iostream>
#include <iterator>
#include <vector>

/*
    this example uses a vector iterator, however, there are other iterators too:
    vector   - random access
    list     - bidirectional
    dequeue  - random access
    map      - bidirectional
    multimap - bidirectional
    set      - bidirectional
    multiset - bidirectional

    random access iterators access in constant time, other iterators require n steps to access
    forward and reverse iterators also exist
*/


int main(int argc, char const *argv[])
{
    std::vector<int> vector {5, 6, 7, 8};
    std::vector<int>::iterator itr;

    // iterate forwards:
    // iterate using an iterator
    for (itr = vector.begin(); itr != vector.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    // iterate using a const_iterator
    for (auto c_itr = vector.cbegin(); c_itr != vector.cend(); c_itr++)
    {
        std::cout << *c_itr << " ";
    }

    std::cout << std::endl;

    // iterate backwards:
    // iterate using a reverse_iterator
    for(std::vector<int>::reverse_iterator r_itr = vector.rbegin(); r_itr != vector.rend(); r_itr++)
    {
        std::cout << *r_itr << " ";
    }

    std::cout << std::endl;

    // iterate using a const_reverse_iterator
    for(std::vector<int>::const_reverse_iterator c_r_itr = vector.crbegin(); c_r_itr != vector.crend(); c_r_itr++)
    {
        std::cout << *c_r_itr << " ";
    }

    std::cout << std::endl;

    // iterators can also be used to modify a vector
    // e.g. the following will insert a value 3 into the vector at index 2
    vector.insert(vector.begin() + 2, 3);

    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;


    return 0;
}

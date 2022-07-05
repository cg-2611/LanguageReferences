#include <iostream>
#include <iterator>
#include <list>

// iterators can be used with std::list
// i.e. iterators can be used to traverse the list and also insert elements at specific positions

// std::list is a doubly linked list, so reverse iterators can also be used

int main(int argc, char const *argv[])
{
    std::list<int> list = std::list<int>();

    list.push_back(11); // pushes element to back of list
    list.push_back(14);
    list.push_back(16);
    list.push_back(12);
    list.push_back(13);

    std::cout << "List empty: " << list.empty() << std::endl;
    std::cout << "List size: " << list.size() << std::endl;

    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        std::cout << *itr << " -> ";
    }

    std::cout << "END" << std::endl;

    std::cout << "\nList removed front: " << list.front() << std::endl;
    list.pop_front();
    std::cout << "List new front: " << list.front() << std::endl;
    std::cout << "List size: " << list.size() << std::endl;
    std::cout << "List: ";
    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        std::cout << *itr << " -> ";
    }

    std::cout << "END" << std::endl;

    std::cout << "\nList removed back: " << list.back() << std::endl;
    list.pop_back();
    std::cout << "List new back: " << list.back() << std::endl;
    std::cout << "List size: " << list.size() << std::endl;
    std::cout << "List: ";
    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        std::cout << *itr << " -> ";
    }

    std::cout << "END" << std::endl;

    list.push_back(17);
    std::cout << "\nList pushed back: " << list.back() << std::endl;
    std::cout << "List size: " << list.size() << std::endl;
    std::cout << "List: ";
    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        std::cout << *itr << " -> ";
    }

    std::cout << "END" << std::endl;

    list.push_front(18);
    std::cout << "\nList pushed front: " << list.front() << std::endl;
    std::cout << "List size: " << list.size() << std::endl;
    std::cout << "List: ";
    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        std::cout << *itr << " -> ";
    }

    std::cout << "END" << std::endl;

    list.clear();
    std::cout << "\nList cleared" << std::endl;
    std::cout << "List empty: " << list.empty() << std::endl;

    return 0;
}

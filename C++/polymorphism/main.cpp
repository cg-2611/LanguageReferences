#include <iostream>
#include <vector>

#include "sub_class_one.h"
#include "sub_class_two.h"
#include "super_class.h"

int main(int argc, char const *argv[])
{
    SuperClass super_class = SuperClass();
    SubClassOne sub_class_one = SubClassOne();
    SubClassTwo sub_class_two = SubClassTwo();

    // SuperClass* is used here because if SuperClass is used as the type, the subclasses
    // will undergo object slicing and the for loop will only call the print method of SuperClass for each
    // subclass instance

    std::vector<SuperClass*> vector = {&super_class, &sub_class_one, &sub_class_two};

    for(size_t i = 0; i < vector.size(); i++)
    {
        vector.at(i)->print();
    }

    return 0;
}

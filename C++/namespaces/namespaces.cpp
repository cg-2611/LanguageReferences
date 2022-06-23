#include <iostream>

#include "namespaces.h"

// namespaces are a named declarative regions of code that provide a scope to the identifiers defined inside it
// these identifiers can be for variables, functions, structs, unions, classes, etc.
// namespaces can also be nested inside other namespaces and classes
// namespaces can also be aliased, e.g. namespace new_name = current_name;

namespace first_namespace
{
    int x = 2;
    void function()
    {
        std::cout << "First Namespace Function" << std::endl;
    }
}

namespace second_namespace
{
    float y = 9.4;
    void function()
    {
        std::cout << "Second Namespace Function" << std::endl;
    }
}

namespace fourth_namespace
{
    class ExampleClass
    {
    public:
        void function()
        {
            std::cout << "Fourth Namespace Example Class Function" << std::endl;
        }
    };
}

namespace fifth_namespace
{
    class ExampleClass; // declare class
}

class fifth_namespace::ExampleClass // defined class
{
public:
    void function()
    {
        std::cout << "Fifth Namespace Example Class Function" << std::endl;
    }
};

using namespace third_namespace;

// define function from namespaces.h
void third_namespace::function()
{
    std::cout << "Third Namespace Function" << std::endl;
}

int main(int argc, char const *argv[])
{
    // if using keyword used, then the function from the namespace being used does not need the namespace specified
    // e.g.
    // using namespace first_namespace;
    // function();
    // second_namespace::function();

    first_namespace::function();
    second_namespace::function();

    function(); // from third_namespace

    fourth_namespace::ExampleClass object1 = fourth_namespace::ExampleClass();
    object1.function();

    fifth_namespace::ExampleClass object2 = fifth_namespace::ExampleClass();
    object2.function();

    std::cout << std::endl;

    std::cout << first_namespace::x << std::endl;
    std::cout << second_namespace::y << std::endl;

    // from third_namespace
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    using first_namespace::x;
    using second_namespace::y;

    std::cout << x << std::endl; // x now refers to first_namespace::x because of using statement above
    std::cout << y << std::endl; // y now refers to second_namespace::y because of using statement above

    return 0;
}

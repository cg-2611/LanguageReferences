#include <iostream>

class ExampleClass2;

class ExampleClass1 {
    private:
        int x;
        friend class ExampleClass2; // ExampleClass1 and ExampleClass2 are friends

    public:
        ExampleClass1()
        {
            x = 3;
        }
};

class ExampleClass2 {
    private:
        int y;
        friend int square(ExampleClass2 example_object2); // declare a function as a friend

    public:
        ExampleClass2()
        {
            y = 6;
        }

    int add()
    {
        // because ExampleClass1 and ExampleClass2 are friends they can access each others private members
        // as if they were public
        ExampleClass1 example_object1;
        return example_object1.x + y;
    }
};

// define friend function
int square(ExampleClass2 example_object2)
{
    return example_object2.y * example_object2.y;
}

int main()
{
    ExampleClass2 example_object2;
    std::cout << example_object2.add() << std::endl;

    std::cout << "y^2 = " << square(example_object2) << std::endl;

    return 0;
}
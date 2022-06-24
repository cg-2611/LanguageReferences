#include <iostream>

class ExampleClass
{
private:
    int x;
    int *y;

public:
   ExampleClass(int x, int y)
    {
        std::cout << "Constructor called" << std::endl;
        this->x = x;
        this->y = new int(y);
    }

    ~ExampleClass()
    {
        delete y;
        std::cout << "Destructor called" << std::endl;
    }

    int getX()
    {
        return x;
    }

    int getY_1()
    {
        return *y;
    }

    int getY_2()
    {
        return *(this->y);
    }
};


int main(int argc, char const *argv[])
{
    ExampleClass example1 = ExampleClass(5, 6);         // memory for object allocated on stack
    ExampleClass* example2 = new ExampleClass(12, 13); // memory for object allocated on heap (pointer allocated on stack)

    std::cout << example1.getX() << ", " << example1.getY_1() << ", " << example1.getY_2() << std::endl;
    std::cout << example2->getX() << ", " << example2->getY_1() << ", " << example2->getY_2() << std::endl;

    delete example2; // deallocate memory on heap

    return 0;
}

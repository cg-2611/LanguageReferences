#include <exception>
#include <iostream>
#include <stdexcept>

class CustomException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Custom Exception Message";
    }
};

void function(int x)
{
    if (x > 256 || x < -257)
    {
        throw std::invalid_argument("invalid argument exception");
    }

    std::cout << "value of x: " << x << std::endl;
}


int main(int argc, char const *argv[])
{
    try
    {
        throw CustomException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        function(123);         // ok
        function(256);         // ok
        function(257);  // throws exception
        function(-258); // throws exception
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

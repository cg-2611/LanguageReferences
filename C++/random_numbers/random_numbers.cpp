#include <functional>
#include <iostream>
#include <random>

int main(int argc, char const *argv[])
{
    // this example uses a random_device, which is described as a true random number generator that produces
    // non-deterministic random numbers
    std::random_device rd;
    std::cout << "rd.min() = " << rd.min() << std::endl;
    std::cout << "rd.max() = " << rd.max() << std::endl;
    std::cout << "Random integer (no bounds): " << rd() << std::endl; // rd() returns a random integer between rd.min() and rd.max()

    std::cout << "\n16 random integers between 10 and 99: ";
    for (int i = 0; i < 16; i++)
    {
        std::cout << (rd() % (100 - 10)) + 10 << " "; // (rd() % (upper - lower)) + lower
    }

    std::cout << std::endl;

    // for double, or other data types, see the C random numbers reference, but replace rand() with rd()

    // these examples use the default_random_engine and the uniform integer distribution
    // however there are other random engines and distributions that can be used
    std::default_random_engine generator;

    std::uniform_int_distribution<int> integer_distribution(10,100); // lower bound is included, upper bound is not

    std::cout << "\n16 random integers between 10 and 99: ";
    for (int i = 0; i < 16; i++)
    {
        std::cout << integer_distribution(generator) << " ";
    }

    std::cout.precision(2); // used to output to 2 d.p.

    std::uniform_real_distribution<double> double_distribution1(0, 1); // lower bound is included, upper bound is not
    std::cout << "\n16 random doubles between 0 and 1: ";
    for (int i = 0; i < 16; i++)
    {
        std::cout << double_distribution1(generator) << " ";
    }

    std::uniform_real_distribution<double> double_distribution2(5.5, 9.9); // lower bound is included, upper bound is not
    std::cout << "\n16 random doubles between 5.5 and 9.9: ";
    for (int i = 0; i < 16; i++)
    {
        std::cout << double_distribution2(generator) << " ";
    }

    std::uniform_int_distribution<int> boolean_distribution(0, 1);
    std::cout << "\n16 random boolean values: ";
    for (int i = 0; i < 16; i++)
    {
        std::cout << (boolean_distribution(generator) ? "true" : "false") << " ";
    }


    return 0;
}

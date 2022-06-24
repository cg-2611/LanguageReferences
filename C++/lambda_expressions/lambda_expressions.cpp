#include <algorithm>
#include <iostream>
#include <vector>

/*
    The structure of a C++ lambda expression:
     1   2     3      4         5    6
    []  ()  mutable throw() -> type {}

    1 - capture clause (or lambda-introducer)
        - used to specify which variables are captured from the surrounding scope, and whether
          they are captured by reference(&) or by value(=)
        - if left empty, this indicates that the lambda does not capture any variables
        - [&x, =y] captures x by reference and  by value
        - capture defaults can also be used e.g. [&] captures any captured variables by reference

    2 - parameter list (or lambda declarator, optional)

    3 - mutable specification (optional)
        - const-by-value is default unless mutable is specified
        - enables the body of a lambda expression to modify variables that are captured by value

    4 - exception specification (optional)
        - specify an exception thrown by the lambda, noexcept can also be used

    5 - trailing return type (optional)
        - if specified, it must follow the parameter list
        - if the lambda contains a single return statement, this type can be deduced by the compiler
          otherwise, the compiler deduces the return type as void

    6 - lambda body
*/

void fillVector(std::vector<int> &vector)
{
    static int value = 1;

    //note this isn't thread-safe
    std::generate(vector.begin(), vector.end(), [] { return value++; });
}

int main(int argc, char const *argv[])
{
    std::cout << "4^2 = " << ([] (int x) { return x * x; })(4) << std::endl;

    int m = 0;
    int n = 7;

    // capture m by reference and n by value
    // m can only be changed since mutable is specified
    [=, &m] (int a) mutable { m = ++n + a; }(19);

    std::cout << "m = " << m << std::endl << "n = " << n << std::endl;

    std::vector<int> vector(10, 0); // initialize vector with 10 elements, each 0
    fillVector(vector);

    for(const int x : vector) {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    std::vector<int> fibonacci(10, 1);

    int x = fibonacci[0];
    int y = fibonacci[1];

    generate_n(fibonacci.begin() + 2, fibonacci.size() - 2,
        [=]() mutable -> int {
        int n = x + y;
        x = y;
        y = n;
        return n;
    });

    for(const int x : fibonacci) {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    return 0;
}

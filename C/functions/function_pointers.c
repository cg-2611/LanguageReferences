#include <stdio.h>

void add(int x, int y) {
    int result = x + y;
    printf("%d + %d = %d\n", x, y, result);
}

void multiply(int x, int y) {
    int result = x * y;
    printf("%d * %d = %d\n", x, y, result);
}

long double square(double x) {
    return x * x;
}

long double cube(double x) {
    return x * x * x;
}

void execute_void_function(void (*void_function_p)(int, int), int a, int b) {
    void_function_p(a, b);
}

void execute_long_double_function(long double(*long_double_function_p)(double), double a) {
    long double result = long_double_function_p(a);
    printf("%Lf\n", result);
}

int main(int argc, char *argv[])
{
    execute_void_function(&add, 4, 11);
    execute_void_function(&multiply, 4, 11);
    execute_void_function(&add, 13, 24);
    execute_void_function(&multiply, 13, 24);

    printf("\n");

    execute_long_double_function(&square, 6.7);
    execute_long_double_function(&cube, 8.9);

    return 0;
}

#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 5;
    int *x_pointer = &x;
    int **x_pointer_pointer = &x_pointer;

    printf("Address of x: %p\n", &x);
    printf("Value of x_pointer: %p\n", x_pointer);
    printf("Value of x: %d\n", x);
    printf("Value of *x_pointer: %d\n", *x_pointer);
    printf("Address of x_pointer: %p\n", &x_pointer);
    printf("Value of x_pointer_pointer: %p\n", x_pointer_pointer);
    printf("Value of x_pointer: %p\n", x_pointer);
    printf("Value of *x_pointer_pointer: %p\n", *x_pointer_pointer);
    printf("Value of **x_pointer_pointer: %d\n", **x_pointer_pointer);

    return 0;
}

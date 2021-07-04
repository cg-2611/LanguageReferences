#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 5;
    int *x_p = &x;
    int **x_p_p = &x_p;

    printf("Address of x: %p\n", &x);
    printf("Value of x_p: %p\n", x_p);
    printf("Value of x: %d\n", x);
    printf("Value of *x_p: %d\n", *x_p);
    printf("Address of x_p: %p\n", &x_p);
    printf("Value of x_p_p: %p\n", x_p_p);
    printf("Value of x_p: %p\n", x_p);
    printf("Value of *x_p_p: %p\n", *x_p_p);
    printf("Value of **x_p_p: %d\n", **x_p_p);

    return 0;
}

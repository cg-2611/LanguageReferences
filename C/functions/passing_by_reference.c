#include <stdio.h>

void change_string(char **old_string) {
    *old_string = "New String";
}

// returns square of x, square of y as square and the sum and product of x and y
// actual return value is y^2, however, passing sum, product and square by reference allows
// for more return values
int perform_calculations(int x, int y, int *sum, int *product, int *square) {
    *sum = x + y;
    *product = x * y;
    *square = y * y;
    return x * x;
}

int main(int argc, char *argv[])
{
    char *string = " This is a string";
    printf("String before change: %s\n", string);

    change_string(&string);

    printf("String after change: %s\n", string);

    int a = 4;
    int b = 9;
    int sum_a_b, product_a_b, square_a,square_b;

    square_a = perform_calculations(a, b, &sum_a_b, &product_a_b, &square_b);

    printf("%d + %d = %d\n", a, b, sum_a_b);
    printf("%d * %d = %d\n", a, b, product_a_b);
    printf("%d^2 = %d\n", a, square_a);
    printf("%d^2 = %d\n", b, square_b);


    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// returns a random integer in range lower inclusive to upper exclusive, or lower to upper - 1 inclusive
int random_integer_in_range(int lower, int upper)
{
    return ((rand() % (upper - lower)) + lower);
}

// returns a random double in range 0 to 1 inclusive, divide by RAND_MAX + 1 for range 0 inclusive to 1 exclusive
double random_double()
{
    return ((double)rand() / (double)RAND_MAX);
}

// returns a random double in range lower inclusive to upper inclusive
double random_double_in_range(double lower, double upper)
{
    return ((random_double() * (upper - lower)) + lower);
}

int main(int argc, char *argv[])
{
    srand(time(NULL)); // initialize random seed using current time

    // rand() returns a random integer between 0 and RAND_MAX inclusive
    int random_integer = rand();

    printf("RAND_MAX = %d\n", RAND_MAX);
    printf("Random integer (no bounds): %d\n", random_integer);

    int i;

    printf("\n\n16 random integers between 10 and 99: ");
    for (i = 0; i < 16; i++)
    {
        printf("%d ", random_integer_in_range(10, 100));
    }

    printf("\n\n16 random doubles between 0 and 1: ");
    for (i = 0; i < 16; i++)
    {
        printf("%.2lf ", random_double());
    }

    printf("\n\n16 random doubles between 5.5 and 9.9: ");
    for (i = 0; i < 16; i++)
    {
        printf("%.2lf ", random_double_in_range(5.5, 9.9));
    }

    printf("\n\n16 random boolean values: ");
    for (i = 0; i < 16; i++)
    {
        printf("%d ", random_integer_in_range(0, 2));
    }

    return 0;
}

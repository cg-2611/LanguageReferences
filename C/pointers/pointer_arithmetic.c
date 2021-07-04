#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Incrementing pointers:\n");

    int increment_numbers[] = {36, 41, 55, 62, 78, 89, 94, -1};
    int *increment_numbers_p = increment_numbers;

    int i = 0;
    // loop while the end of the array is reached,
    //
    // condition can also be increment_numbers_p != &increment_numbers[7]
    //
    // could also store length of array and compare to i, then no need to store -1
    //
    // for loop variation:
    // for (i = 0; i < 7; i++)
    // {
    //     // print same as while
    //
    //     increment_numbers_p++;
    // }
    while (*increment_numbers_p != -1)
    {
        printf("Address of increment_numbers[%d]: %p\n", i, &increment_numbers_p);
        printf("Value of increment_numbers_p: %p\n", increment_numbers_p);
        printf("Value of increment_numbers[%d]: %d\n", i, increment_numbers[i]);
        printf("Value of *increment_numbers_p: %d\n\n", *increment_numbers_p);

        i++;

        increment_numbers_p++;
    }

    printf("\n\nDecrementing pointers: \n");

    int decrement_numbers[] = {-1, 124, 152, 167, 132, 185, 149, 175};
    int *decrement_numbers_p = &decrement_numbers[7];

    i = 7;
    // loop while the end of the array is reached,
    //
    // condition can also be decrement_numbers_p != &decrement_numbers
    //
    // could also store length of array and compare to i, then no need to store -1
    //
    // for loop variation:
    // for (i = 7; i > 0; i--)
    // {
    //     // print same as while
    //
    //     decrement_numbers_p--;
    // }
    while (*decrement_numbers_p != -1)
    {
        printf("Address of decrement_numbers[%d]: %p\n", i, &decrement_numbers_p);
        printf("Value of decrement_numbers_p: %p\n", decrement_numbers_p);
        printf("Value of decrement_numbers[%d]: %d\n", i, decrement_numbers[i]);
        printf("Value of *decrement_numbers_p: %d\n\n", *decrement_numbers_p);

        i--;

        decrement_numbers_p--;
    }

    return 0;
}

#include <stdio.h>

int main(int argc, char *argv[])
{
    const int LENGTH = 6;
    int numbers[] = {11, 12, 13, 14, 15, 16};

    printf("Address of numbers[0]: %p\n", &numbers[0]);
    printf("Value of numbers: %p\n", numbers);
    printf("Value of *numbers: %d\n", *numbers);
    printf("Value of numbers[0]: %d\n\n", numbers[0]);

    int i;
    for (i = 0; i < LENGTH; i++)
    {
        printf("Address of numbers[%d]: %p\n", i, &numbers[i]);
        printf("Value of numbers + %d: %p\n", i, numbers + i);
        printf("Value of numbers[%d]: %d\n", i, numbers[i]);
        printf("Value of *(numbers + %d): %d\n\n", i,  *(numbers + i));
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {1, 2, 9, 4, 6};

    // memcmp compares a given number of bytes of each memory location and returns the difference between
    // the first two memory locations that are different
    // if the arrays are different sizes, always use the size of the smaller one
    int difference = memcmp(array1, array2, sizeof(array1));

    if (difference > 0)
    {
        printf("array1 is greater than array2 by %d\n", abs(difference));
    }
    else if (difference < 0)
    {
        printf("array2 is greater than array1 by %d\n", abs(difference));
    }
    else
    {
        printf("array1 and array2 are equal\n");
    }

    // memchr returns a pointer to the location of the first occurrence of the given value
    // it searches the number of bytes specified
    int *int1_p = memchr(array2, 9, sizeof(array2));
    int *int2_p = memchr(array2, 7, sizeof(array2));

    if (int1_p == NULL)
    {
        printf("9 not found in array2\n");
    }
    else
    {
        printf("9 found at index %ld of array2\n", int1_p - array2); // calculate the index
    }

    if (int2_p == NULL)
    {
        printf("7 not found in array2\n");
    }
    else
    {
        printf("7 found at index %ld of array2\n", int2_p - array2); // calculate the index
    }

    int array3[] = {1, 1, 1, 1, 1};

    printf("array3 before memset: ");
    int i;
    for(i = 0; i < 5; i++)
    {
        printf("%d ", array3[i]);
    }

    // memset sets the value of the given number of bytes from the given pointer to the given value
    // this will set every element of array3 to 0 apart from array3[0]
    // to, for example, all bu the first two elements, use memset(array3 + 2, 0, sizeof(array3) - (2 * sizeof(int)));
    memset(array3 + 1, 0, sizeof(array3) - sizeof(int));

    printf("\narray3 after memset and before memcpy: ");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", array3[i]);
    }

    // memcpy directly copies the given number of bytes from the source (array2) to the destination (array3)
    // to copy every element from one array to another, use memcpy(&array3, &array2, sizeof(array2));
    // this copies all but the first two elements of array2 to array3
    memcpy(array3 + 2, array2 + 2, sizeof(array2) - (2 * sizeof(int)));

    printf("\narray3 after memcpy from array2: ");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", array3[i]);
    }

    char string[] = "This is a string that will be altered..";
    printf("\nString before memmove: ");
    puts(string);

    // memmove is similar to memcpy however it copies the given number bytes from the source to an intermediate
    // buffer before copying to the destination, this allows the destination and source to overlap
    memmove(string + 30, string + 8, 8);
    printf("String after memmove: ");
    puts(string);

    return 0;
}

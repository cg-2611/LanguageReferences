#include <stdio.h>

typedef unsigned long long int type_uint64;

// typedef also works for unions and enums
// the 'example' tag is optional and allows for the declaration of the struct using either:
// type_example identifier;
// or
// struct example identifier;
typedef struct example
{
    int value1;
    type_uint64 value2;
} type_example;

int main(int argc, char *argv[])
{
    printf("Size of unsigned long long int: %lu\n", sizeof(unsigned long long int));
    printf("Size of type_uint64 type: %lu\n", sizeof(type_uint64));

    unsigned long long int int1 = 4294967295 + 1; // 2^32 + 1 (too big to store in an unsigned long int)
    type_uint64 int2 = 4294967295 + 1;

    printf("\nint1 = %llu\n", int1);
    printf("int2 = %llu\n", int2);

    struct example example1 = {
        .value1 = 512,
        .value2 = 65535
    };

    type_example example2 = {
        .value1 = 512,
        .value2 = 65535
    };

    printf("\nSize of struct example: %lu\n", sizeof(struct example));
    printf("Size of type_example: %lu\n", sizeof(type_example));

    printf("\nexample1:\nvalue1 = %d\nvalue2 = %llu\n", example1.value1, example1.value2);
    printf("\nexample2:\nvalue1 = %d\nvalue2 = %llu\n", example2.value1, example2.value2);

    return 0;
}

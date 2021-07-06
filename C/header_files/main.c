#include <stdio.h>
#include "headers/header.h"
#include "util.h"

int main(int argc, char *argv[])
{
    int a = 9;
    int b = 17;

    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", b, a, subtract(a, b));
    printf("%d * %d = %d\n", a, b, multiply(a, b));
    printf("%d / %d = %.2f\n", b, a, divide(a, b));

    // struct accessible through header.h include
    example_struct example = {19, "example string", strlen(example.string)};

    printf("\nStruct Example:\n");
    // MAX_SIZE accessible trough incldue
    if(sizeof(example.string) == MAX_SIZE)
    {
        printf("Struct has size of MAX_SIZE = %lu\n", sizeof(example.string));
    }

    print_struct_members(example);

    return 0;
}

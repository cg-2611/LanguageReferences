#include <stdio.h>

int main(int argc, char *argv[])
{
    // argc always >= 1 as program name is counted

    printf("Number of arguments passed: %d\n\n", argc);

    int i;
    for (i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", (i + 1), argv[i]);
    }

    printf("\nFirst argument provided: %s\n", argv[0]);
    printf("Final argument provided: %s\n", argv[argc - 1]);

    return 0;
}

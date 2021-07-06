#include <stdio.h>
#include <string.h>

// preprocessors are replaced in the program before compilation occurs
// constants vs macros:
// - Constants follow scoping rules, macros do not
// - Constants are type safe, macros are not
// - Constants must be stored, macros do not
// - Constants require initialization, macros do not
#define MAX_SIZE 32
#define PI 3.14
#define AREA_OF_CIRCLE(r) (PI * r * r)
#define PRINT_AREA_OF_CIRCLE(r) printf("Area of circle with radius %d = %.2f\n", r, AREA_OF_CIRCLE(r))
#define PRINT_VARIABLE_NAME_AND_VALUE(variable) printf("\nName: " #variable "\nValue: %d\n", variable)
#define SWAP(a, b)  {           \
                        a ^= b; \
                        b ^= a; \
                        a ^= b; \
                    }

#ifndef E
#define E 2.72
#endif

// not a very useful if statement
#if MAX_SIZE > 32
#define FLAG -1
#elif MAX_SIZE == 32
#define FLAG 0
#elif defined PI
#undef FLAG
#else
#define FLAG 1
#endif

int main(int argc, char *argv[])
{
    char string[MAX_SIZE] = "abcdefghijklmnopqrstuvwxyz";

    printf("MAX_SIZE = %d\n", MAX_SIZE);
    printf("sizeof(string) = %lu\n", sizeof(string));
    printf("string length = %lu\n\n", strlen(string));

    // undefine MAX_SIZE and redefine it with a new value
    // macros can be defined almost anywhere
    #undef MAX_SIZE
    #define MAX_SIZE 64

    char sting2[MAX_SIZE] = "abcdefghijklmnopqrstuvwxyz";

    printf("MAX_SIZE = %d\n", MAX_SIZE);
    printf("sizeof(sting2) = %lu\n", sizeof(sting2));
    printf("sting2 length = %lu\n\n", strlen(sting2));

    printf("PI = %.2f\n\n", PI);

    printf("Area of circle with radius 5 = %.2f\n", AREA_OF_CIRCLE(5));
    PRINT_AREA_OF_CIRCLE(5);

    int integer_value = 17;
    PRINT_VARIABLE_NAME_AND_VALUE(integer_value);

    int a = 3, b = 7;
    printf("a = %d, b = %d\n", a, b);
    SWAP(a, b);
    printf("a = %d, b = %d\n", a, b);

    printf("\ne = %.2f\n", E);

    printf("\nFLAG = %d\n", FLAG);

    printf("\nPredefined Macros:\n");
    printf("Current line number: %d\n", __LINE__);
    printf("Date: %s\n", __DATE__);
    printf("Current line number: %d\n", __LINE__);
    printf("Time: %s\n", __TIME__);
    printf("Current line number: %d\n", __LINE__);
    printf("File name: %s\n", __FILE__);
    printf("Current line number: %d\n", __LINE__);
    printf("Follows ANSI standard: %d\n", __STDC__);
    printf("Current line number: %d\n", __LINE__);

    return 0;
}

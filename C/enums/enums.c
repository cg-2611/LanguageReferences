#include <stdio.h>

// default enumeration begins with 0
// e.g. TRUE = 0, FALSE = 1 (TRUE + 1)
enum boolean
{
    TRUE,
    FALSE
};

// by defining VALUE_4 = 4, the enumeration will being at 4
// e.g. VALUE_5 = 5 (VALUE_4 + 1) and VALUE_6 = 6 (VALUE_5 + 1)
enum example1
{
    VALUE_4 = 4,
    VALUE_5,
    VALUE_6
};

// the next enum will be one more than the previous, unless specified otherwise
enum example2
{
    VALUE_2 = 1,
    VALUE_7 = 7,
    VALUE_8,
    VALUE_11 = 11,
    VALUE_12,
    VALUE_13
};

int main(int argc, char *argv[])
{
    enum boolean boolean_true = TRUE;
    enum boolean boolean_false = FALSE;
    printf("boolean_true = %d\n", boolean_true);
    printf("booleean_false = %d\n\n", boolean_false);

    enum example1 example_enum1;
    example_enum1 = VALUE_4;
    printf("example_enum1 = %d\n", example_enum1);
    example_enum1 = VALUE_5;
    printf("example_enum1 = %d\n", example_enum1);
    example_enum1 = VALUE_6;
    printf("example_enum1 = %d\n\n", example_enum1);

    enum example2 example_enum2;
    example_enum2 = VALUE_2;
    printf("example_enum2 = %d\n", example_enum2);
    example_enum2 = VALUE_7;
    printf("example_enum2 = %d\n", example_enum2);
    example_enum2 = VALUE_8;
    printf("example_enum2 = %d\n", example_enum2);
    example_enum2 = VALUE_11;
    printf("example_enum2 = %d\n", example_enum2);
    example_enum2 = VALUE_12;
    printf("example_enum2 = %d\n", example_enum2);
    example_enum2 = VALUE_13;
    printf("example_enum2 = %d\n", example_enum2);


    return 0;
}

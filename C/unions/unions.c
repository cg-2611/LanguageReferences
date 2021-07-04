#include <stdio.h>
#include <string.h>

// unions allow for different types of data to be stored in the same address
// useful for storing a value in multiple types to avoid casting
// the memory occupied by a union will be large enough to store the largest member
union number
{
    int value;
    char bytes[4];
};

union fraction
{
    long int int_value;
    float  float_value;
};


int main(int argc, char *argv[])
{
    union number x;

    printf("x.value address: %p\n", &x.value);
    printf("x.bytes[0] address: %p\n", &x.bytes[0]);
    printf("x.bytes[1] address: %p\n", &x.bytes[1]);
    printf("x.bytes[2] address: %p\n", &x.bytes[2]);
    printf("x.bytes[3] address: %p\n", &x.bytes[3]);

    x.value = 14;
    printf("\n\nx value = %d\n", x.value);
    printf("x bytes = ");
    int i;
    for (i = 0; i < 4; i++)
    {
        printf("%02x ", x.bytes[i]);
    }

    x.bytes[0] = 113;
    printf("\n\nx value = %d\n", x.value);
    printf("x bytes = ");
    for (i = 0; i < 4; i++)
    {
        printf("%02x ", x.bytes[i]);
    }

    x.bytes[0] = 117;
    x.bytes[1] = 101;
    x.bytes[2] = 98;
    x.bytes[3] = 121;
    printf("\n\nx value = %d\n", x.value);
    printf("x bytes = ");
    for (i = 0; i < 4; i++)
    {
        printf("%02x ", x.bytes[i]);
    }

    strcpy(x.bytes, "xyz"); // only 3 characters as null terminator needed for string
    printf("\n\nx value = %d\n", x.value);
    printf("x bytes = ");
    for (i = 0; i < 4; i++)
    {
        printf("%02x ", x.bytes[i]);
    }

    union fraction y;

    printf("\n\ny.int_value address: %p\n", &y.int_value);
    printf("\n\ny.float_value address: %p\n", &y.float_value);

    y.int_value = 149;
    printf("\n\ny int value = %ld\n", y.int_value);
    printf("y float value = %f\n", y.float_value);

    y.float_value = 336.8;
    printf("\n\ny int value = %ld\n", y.int_value);
    printf("y float value = %f\n", y.float_value);

    return 0;
}

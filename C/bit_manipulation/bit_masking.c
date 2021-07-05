#include <stdio.h>

char mask_value_0x70(char value)
{
  char mask = 0x70;   // 01110000
  return mask & value;
}

char mask_value_0x4b(char value)
{
  char mask = 0x4b;   // 01001011
  return mask & value;
}

int is_odd(int value) {
    char mask = 0b00000001;
    return value & mask;
}

// prints they bytes of the int value passed
void print_bytes(int value) {
    int i;
    for (i = sizeof(value) - 1; i >= 0; i--)
    {
       printf("%x ", (value >> (8 * i)) & 0xff);
    }

    printf("\n");
}


int main(int argc, char *argv[])
{
    char value = 0b01011101;

    // mask  = 01110000
    // value = 01011101
    // &     = 010100000
    printf("0x%02x, %d\n", mask_value_0x70(value), mask_value_0x70(value));

    // mask  = 01001011
    // value = 01011101
    // &     = 01001001
    printf("0x%02x, %d\n", mask_value_0x4b(value), mask_value_0x4b(value));

    unsigned int int_value;

    // mask  = 00000001
    // value = 00001101
    // &     = 00000001
    int_value = 13;
    printf("\nis %d odd: %d\n", int_value, is_odd(int_value));

    // mask  = 00000001
    // value = 00001110
    // &     = 00000000
    int_value = 14;
    printf("\nis %d odd: %d\n", int_value, is_odd(int_value));

    int_value = 0x3a6cb56f;
    printf("bytes of %d: ", int_value);
    print_bytes(int_value);

    return 0;
}

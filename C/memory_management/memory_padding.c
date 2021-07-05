#include <stdio.h>

// short and char padded by 4 bytes to match size of int
struct example1_default_packing
{
    short s; // 2 bytes         +
             // 2 padding bytes +
    int i;   // 4 bytes         +
    char c;  // 1 byte          +
             // 3 padding bytes +
             //                 = 12
};

// char padded by 1 bytes so combined with short they match size of int
struct example2_default_packing
{
    int i;   // 4 bytes         +
    char c;  // 1 byte          +
             // 1 padding byte  +
    short s; // 2 bytes         +
             //                 = 8
};

// same as above
struct example3_default_packing
{
    int i;   // 4 bytes         +
    short s; // 2 bytes         +
    char c;  // 1 byte          +
             // 1 padding byte  +
             //                 = 8
};

// char is padded by 3 bytes so when combined with int they match size of int *
// short padded by 6 bytes to match size of int *
struct example4_default_packing
{
    int i;   // 4 bytes         +
    char c;  // 1 byte          +
             // 3 padding bytes +
    int *p;  // 8 bytes         +
    short s; // 2 bytes         +
             // 6 padding bytes +
             //                 = 24
};

// char is padded by 1 byte so when combined with int and short they match size of int *
struct example5_default_packing
{
    int i;   // 4 bytes         +
    short s; // 2 bytes         +
    char c;  // 1 byte          +
             // 1 padding byte  +
    int *p;  // 8 bytes         +
             //                 = 16
};

// char is padded by 3 byte so when combined with int they match size of int *
// char [] padded by 2 bytes to match size of int *
// short padded by 2 bytes to match size of int *
struct example6_default_packing
{
    int i;       // 4 bytes         +
    char c;      // 1 byte          +
                 // 3 padding bytes +
    char str[6]; // 6 bytes         +
                 // 2 padding bytes +
    int* p;      // 8 bytes         +
    short s;     // 2 bytes         +
                 // 6 padding bytes +
                 //                 = 32
};

// char is padded by 3 byte so when combined with int they match size of int *
// char [] and short not padded because when combined match size of int *
struct example7_default_packing
{
    int i;       // 4 bytes         +
    char c;      // 1 byte          +
                 // 3 padding bytes +
    int* p;      // 8 bytes         +
    char str[6]; // 6 bytes         +
    short s;     // 2 bytes         +
                 //                 = 24
};

// NOT RECOMMENDED
// pack(n) controls the alignment of a member, when set to 1, members are aligned to 1 byte
#pragma pack(1)

struct example1_packing_1
{
    short s; // 2 bytes         +
    int i;   // 4 bytes         +
    char c;  // 1 byte          +
             //                 = 7
};

struct example2_packing_1
{
    int i;   // 4 bytes         +
    char c;  // 1 byte          +
    short s; // 2 bytes         +
             //                 = 7
};

struct example3_packing_1
{
    int i;   // 4 bytes         +
    short s; // 2 bytes         +
    char c;  // 1 byte          +
             //                 = 7
};

struct example4_packing_1
{
    int i;   // 4 bytes         +
    char c;  // 1 byte          +
    int *p;  // 8 bytes         +
    short s; // 2 bytes         +
             //                 = 15
};

struct example5_packing_1
{
    int i;   // 4 bytes         +
    char c;  // 1 byte          +
    short s; // 2 bytes         +
    int *p;  // 8 bytes         +
             //                 = 16
};

struct example6_packing_1
{
    int i;       // 4 bytes         +
    char c;      // 1 byte          +
    char str[6]; // 6 bytes         +
    int* p;      // 8 bytes         +
    short s;     // 2 bytes         +
                 //                 = 21
};

struct example7_packing_1
{
    int i;       // 4 bytes         +
    char c;      // 1 byte          +
    int* p;      // 8 bytes         +
    char str[6]; // 6 bytes         +
    short s;     // 2 bytes         +
                 //                 = 21
};

int main(int argc, char *argv[])
{
    printf("example1_default_packing: %lu bytes\n", sizeof(struct example1_default_packing));
    printf("example1_packing_1: %lu bytes\n\n", sizeof(struct example1_packing_1));

    printf("example2_default_packing: %lu bytes\n", sizeof(struct example2_default_packing));
    printf("example2_packing_1: %lu bytes\n\n", sizeof(struct example2_packing_1));

    printf("example3_default_packing: %lu bytes\n", sizeof(struct example3_default_packing));
    printf("example3_packing_1: %lu bytes\n\n", sizeof(struct example3_packing_1));

    printf("example4_default_packing: %lu bytes\n", sizeof(struct example4_default_packing));
    printf("example4_packing_1: %lu bytes\n\n", sizeof(struct example4_packing_1));

    printf("example5_default_packing: %lu bytes\n", sizeof(struct example5_default_packing));
    printf("example5_packing_1: %lu bytes\n\n", sizeof(struct example5_packing_1));

    printf("example6_default_packing: %lu bytes\n", sizeof(struct example6_default_packing));
    printf("example6_packing_1: %lu bytes\n\n", sizeof(struct example6_packing_1));

    printf("example7_default_packing: %lu bytes\n", sizeof(struct example7_default_packing));
    printf("example7_packing_1: %lu bytes\n\n", sizeof(struct example7_packing_1));

    return 0;
}

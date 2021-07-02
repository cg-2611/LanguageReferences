#include <stdio.h>

void print_array_bytes(void *array, size_t array_size) {
    int i;
    for (i = 0; i < array_size; i++)
    {
        printf("%04x ", ((int *)array)[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    printf("Void pointer to variable:\n");
    int x = 45;
    double y = 33.21;
    char z = 'z';
    void *variable_void_pointer;

    variable_void_pointer = &x;
    printf("x = %d\n", *((int *)variable_void_pointer));
    variable_void_pointer = &y;
    printf("y = %.2lf\n", *((double *)variable_void_pointer));
    variable_void_pointer = &z;
    printf("z = %c\n\n", *((char *)variable_void_pointer));

    // since the void pointer is cast to an int pointer, and the array contains ints
    // the size argument is the number of elements in the array
    int int_array[] = {3, 30, 300};
    size_t array_size = sizeof(int_array) / sizeof(int);
    print_array_bytes(int_array, array_size);

    // each long is twice the size of an int, so the size must be doubled for the
    // correct number of elements to be output
    long long_array[] = {3213, 32132, 321321};
    array_size = (sizeof(long_array) / sizeof(long)) * 2;
    print_array_bytes(long_array, array_size);


    return 0;
}

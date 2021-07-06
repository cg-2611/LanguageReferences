#include <stdio.h>

static void main_static_function()
{
    printf("Printed from static function in main.c\n");
}

int main(int argc, char *argv[])
{
    // gives a compiler error when linking as static function only available in scope
    // of the object file other_file.o
    // static_function();

    main_static_function();

    return 0;
}

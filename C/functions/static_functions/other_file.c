#include <stdio.h>

static void static_function()
{
    // gives a compiler error when linking as static function only available in scope
    // of the object file main.o
    // main_static_function();

    printf("Printed from static function in other_file.c\n");
}
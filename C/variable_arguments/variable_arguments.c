#include <stdarg.h>
#include <stdio.h>

void printArgs(int args_count, ...) {
    va_list args;

    // initialize va_list args to store all arguments after args_count
    va_start(args, args_count);

    int i;
    for (i = 0; i < args_count; i++) {
        // print each argument, treating each one as a char *
        printf("%s, ", va_arg(args, char *));
    }

    // clean the list
    va_end(args);

    printf("\n");
}

double average_args(int args_count, ...) {
    double sum = 0.0;

    va_list args;

    // initialize va_list args to store all arguments after args_count
    va_start(args, args_count);
    
    int i;
    for (i = 0; i < args_count; i++) {
        // add each argument to the sum, treating each one as a double
        sum += va_arg(args, double);
    }

    // clean the list
    va_end(args);

    return (double)sum / (double)args_count;
}

int main(int argc, char *argv[]) {
    printArgs(1, "Argument 1");
    printArgs(2, "Argument 1", "Argument 2");
    printArgs(3, "Argument 1", "Argument 2", "Argument 3");
    printArgs(6, "Argument 1", "Argument 2", "Argument 3", "Argument 4", "Argument 5", "Argument 6");

    double average =  average_args(5 , 1.4, 3.7, 5.1, 7.2, 9.9);
    printf("\nAverage of 1.4, 3.7, 5.1, 7.2, 9.9 = %lf\n", average);

    average = average_args(9 , 2.42, 6.51, 12.36, 17.39, 14.67, 8.74, 9.30, 3.65, 5.89);
    printf("\nAverage of 2.42, 6.51, 12.36, 17.39, 14.67, 8.74, 9.30, 3.65, 5.89 = %lf\n", average);

    return 0;
}
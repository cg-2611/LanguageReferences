#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const int array_rows = 3;
    const int array_columns = 5;

    printf("Static 2D array:\n");

    // static 2D array, memory allocated on the stack
    int static_array[3][5] = {
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {2, 3, 5, 1, 4}
    };

    int i, j;
    for (i = 0; i < array_rows; i++)
    {
        for (j = 0; j < array_columns; j++)
        {
            printf("%d ", static_array[i][j]);
        }
        printf("\n");
    }

    printf("\nDynamic 2D array:\n");

    // dynamic 2D array, memory allocated on the heap
    // allocated memory to store the pointers to the arrays stored in the 2d array
    int **array = (int **)malloc(sizeof(int *) * array_rows);

    // allocate memory to store the integers in each array
    for(i = 0; i < array_rows; i++)
    {
        array[i] = (int *)malloc(sizeof(int) * array_columns);
    }

    // assign values to each element of the individual arrays
    for (i = 0; i < array_rows; i++)
    {
        for (j = 0; j < array_columns; j++)
        {
            array[i][j] = (j + 1) + i;
        }
    }

    for (i = 0; i < array_rows; i++)
    {
        for (j = 0; j < array_columns; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // deallocate each individual array
    for(i = 0; i < array_rows; i++)
    {
        free(array[i]);
        array[i] = NULL;
    }

    // deallocate array
    free(array);
    array = NULL;

    return 0;
}

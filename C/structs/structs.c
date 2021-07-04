#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct point
{
    double x;
    double y;
};

// using const ensures the structs cannot be changed
double get_euclidean_distance(const struct point *point1, const struct point *point2)
{
    return sqrt(pow((point1->x - point2->x), 2) + pow((point1->y - point2->y), 2));
}

struct point *get_mid_point_return_pointer(const struct point *point1, const struct point *point2)
{
    // allocate memory to store a struct point
    struct point *mid_point = (struct point *)malloc(sizeof(struct point));

    // good practice to check memory allocation was successful

    // point->x is equivalent to *(point).x
    mid_point->x = (point1->x + point2->x) / 2;
    mid_point->y = (point1->y + point2->y) / 2;

    return mid_point;
}

void get_mid_point_void(struct point *mid, const struct point *point1, const struct point *point2)
{
    mid->x = (point1->x + point2->x) / 2;
    mid->y = (point1->y + point2->y) / 2;
}

int main(int argc, char *argv[])
{
    struct point p1 = {
        .x = 1.24,
        .y = 2.48
    };

    struct point p2 = {
        .x = 3.21,
        .y = 6.42
    };

    printf("p1 = (%.2lf, %.2lf)\n", p1.x, p1.y);
    printf("p2 = (%.2lf, %.2lf)\n", p2.x, p2.y);

    double euclidean_distance = get_euclidean_distance(&p1, &p2);
    printf("Euclidean distance between p1 and p2 = %.2lf\n", euclidean_distance);

    struct point *midpoint1_p = get_mid_point_return_pointer(&p1, &p2);
    printf("midpoint1_p = (%.2lf, %.2lf)\n", midpoint1_p->x, midpoint1_p->y);

    struct point midpoint2;
    // pass midpoint2 by reference to function so midpoint2 can be stored on stack and not heap
    get_mid_point_void(&midpoint2, &p1, &p2);
    printf("midpoint2 = (%.2lf, %.2lf)\n", midpoint2.x, midpoint2.y);


    // deallocate memory allocated in get_mid_point_return_pointer()
    free(midpoint1_p);
    midpoint1_p = NULL;

    return 0;
}

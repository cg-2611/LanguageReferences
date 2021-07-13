#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    unsigned int max_size;
    int top;
    int *array;
};

struct stack *initialize_stack(unsigned int max_size);
void push(struct stack *s, int item);
int pop(struct stack *s);
int peek(struct stack *s);
int is_empty(struct stack *s);
int is_full(struct stack *s);
void print_stack(struct stack *s);
void free_stack(struct stack *s);

struct stack *initialize_stack(unsigned int max_size)
{
    struct stack *s = malloc(sizeof(*s));

    s->max_size = max_size;
    s->top = -1;

    s->array = malloc(max_size * sizeof(*s->array));

    return s;
}

void push(struct stack *s, int item)
{
    if (is_full(s))
    {
        printf("Stack overflow, cannot insert item %d\n", item);
        return;
    }

    s->array[++s->top] = item;
    printf("Pushed item %d to stack\n", item);
}

int pop(struct stack *s)
{
    if (is_empty(s))
    {
        printf("Stack underflow, cannot pop item\n");
        return INT_MIN;
    }

    int item = s->array[s->top--];
    printf("Popped item %d\n", item);
    return item;
}

int peek(struct stack *s)
{
    if (is_empty(s))
    {
        printf("Stack empty, cannot peek\n");
        return INT_MIN;
    }

    int item = s->array[s->top];
    printf("Peeked at item %d\n", item);
    return item;
}

int is_empty(struct stack *s)
{
    return s->top < 0;
}

int is_full(struct stack *s)
{
    return s->top == s->max_size - 1;
}

void print_stack(struct stack *s)
{
    if (!is_empty(s))
    {
        int i;
        for (i = 0; i < s->top; i++)
        {
            printf("%d, ", s->array[i]);
        }

        printf("%d\n", s->array[s->top]);
    }

}

void free_stack(struct stack *s)
{
    free(s->array);
    s->array = NULL;

    free(s);
    s = NULL;
}

int main(int argc, char *argv[])
{
    struct stack *s = initialize_stack(5);

    push(s, 1);
    print_stack(s);
    push(s, 2);
    print_stack(s);
    push(s, 3);
    print_stack(s);
    push(s, 4);
    print_stack(s);
    push(s, 5);
    print_stack(s);
    push(s, 6);
    print_stack(s);
    peek(s);
    pop(s);
    print_stack(s);
    peek(s);
    pop(s);
    print_stack(s);
    pop(s);
    print_stack(s);
    peek(s);
    push(s, 9);
    print_stack(s);
    peek(s);
    pop(s);
    print_stack(s);
    push(s, 13);
    print_stack(s);
    pop(s);
    print_stack(s);
    pop(s);
    print_stack(s);
    pop(s);
    print_stack(s);
    pop(s);
    print_stack(s);
    push(s, 3);
    print_stack(s);
    push(s, 7);
    print_stack(s);
    push(s, 11);
    print_stack(s);

    free_stack(s);

    return 0;
}
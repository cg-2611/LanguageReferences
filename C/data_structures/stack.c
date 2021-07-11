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
void free_stack(struct stack *stack_to_free);
void push(struct stack *s, int item);
int pop(struct stack *s);
int peek(struct stack *s);
int is_empty(struct stack *s);
int is_full(struct stack *s);

struct stack *initialize_stack(unsigned int max_size)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));

    s->max_size = max_size;
    s->top = -1;

    s->array = (int *)malloc(max_size * sizeof(int));

    return s;
}

void free_stack(struct stack *stack_to_free)
{
    free(stack_to_free->array);
    stack_to_free->array = NULL;

    free(stack_to_free);
    stack_to_free = NULL;
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

int main(int argc, char *argv[])
{
    struct stack *s = initialize_stack(5);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);

    peek(s);

    pop(s);

    peek(s);

    pop(s);
    pop(s);

    peek(s);

    pop(s);
    pop(s);
    pop(s);

    push(s, 3);
    push(s, 7);
    push(s, 11);

    free_stack(s);

    return 0;
}
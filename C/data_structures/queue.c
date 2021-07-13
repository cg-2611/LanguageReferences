#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    unsigned int max_size;
    int front;
    int rear;
    int size;
    int *array;
};

struct queue *initialize_queue(unsigned int max_size);
void enqueue(struct queue *q, int item);
int dequeue(struct queue *q);
int is_empty(struct queue *q);
int is_full(struct queue *q);
void print_queue(struct queue *q);
void free_queue(struct queue *q);

struct queue *initialize_queue(unsigned int max_size)
{
    struct queue *q = malloc(sizeof(*q));

    q->max_size = max_size;
    q->front = 0;
    q->size = 0;
    q->rear = max_size - 1;

    q->array = malloc(max_size * sizeof(*q->array));

    return q;
}

void enqueue(struct queue *q, int item)
{
    if (is_full(q))
    {
        printf("Queue full, cannot enqueue item %d\n", item);
        return;
    }

    q->rear = (q->rear + 1) % q->max_size;
    q->array[q->rear] = item;
    q->size++;
    printf("Enqueued item %d to queue\n", item);
}

int dequeue(struct queue *q)
{
    if (is_empty(q))
    {
        printf("Queue empty, cannot dequeue item\n");
        return INT_MIN;
    }

    int item = q->array[q->front];
    q->front = (q->front + 1) % q->max_size;
    q->size--;
    printf("Dequeued item %d\n", item);
    return item;
}

int is_empty(struct queue *q)
{
    return q->size == 0;
}

int is_full(struct queue *q)
{
    return q->size == q->max_size;
}

void print_queue(struct queue *q)
{
    int i = q->front;
    while (i != q->rear)
    {
        printf("%d, ", q->array[i]);

        i = (i + 1) % q->max_size;
    }
    printf("%d\n", q->array[q->rear]);
}

void free_queue(struct queue *q)
{
    free(q->array);
    q->array = NULL;

    free(q);
    q = NULL;
}

int main(int argc, char *argv[])
{
    struct queue *q = initialize_queue(5);

    enqueue(q, 1);
    print_queue(q);
    enqueue(q, 2);
    print_queue(q);
    enqueue(q, 3);
    print_queue(q);
    enqueue(q, 4);
    print_queue(q);
    enqueue(q, 5);
    print_queue(q);
    enqueue(q, 6);
    print_queue(q);
    dequeue(q);
    print_queue(q);
    dequeue(q);
    print_queue(q);
    dequeue(q);
    print_queue(q);
    enqueue(q, 9);
    print_queue(q);
    dequeue(q);
    print_queue(q);
    enqueue(q, 13);
    print_queue(q);
    dequeue(q);
    print_queue(q);
    dequeue(q);
    print_queue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 3);
    print_queue(q);
    enqueue(q, 7);
    print_queue(q);
    enqueue(q, 11);
    print_queue(q);

    free_queue(q);

    return 0;
}

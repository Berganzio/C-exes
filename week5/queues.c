#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// create a queues type data structure

typedef struct queues
{
    int *array;
    int front;
    int rear;
    int size;
} queues;

// create a new queues
queues *newQueues(int size)
{
    queues *q = malloc(sizeof(queues));
    if (q == NULL)
    {
        return NULL;
    }
    q->array = malloc(size * sizeof(int));
    if (q->array == NULL)
    {
        return NULL;
    }
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

// insert a value into a queues
bool enqueue(queues *q, int value)
{
    // TODO
    if (q->rear == q->size)
    {
        return false;
    }
    q->array[q->rear] = value;
    q->rear++;
    return true;
}

// returns true if queues is empty else false
bool isEmpty(queues *q)
{
    // TODO
    if (q->front == q->rear)
    {
        return true;
    }
    return false;
}

// returns the value at the front of the queues
int peek(queues *q)
{
    // TODO
    if (isEmpty(q))
    {
        return -1;
    }
    return q->array[q->front];
}

// removes the value at the front of the queues
int dequeue(queues *q)
{
    // TODO
    if (isEmpty(q))
    {
        return -1;
    }
    int value = q->array[q->front];
    q->front++;
    return value;
}

// print the queues
void printQueues(queues *q)
{
    // TODO
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%i ", q->array[i]);
    }
    printf("\n");
}

int main(void)
{
    queues *q = newQueues(5);
    enqueue(q, 10);
    enqueue(q, 22);
    enqueue(q, 13);
    enqueue(q, 24);
    enqueue(q, 55);
    printQueues(q);
    printf("peek: %i\n", peek(q));
    printf("dequeue: %i\n", dequeue(q));
    printQueues(q);
    printf("dequeue: %i\n", dequeue(q));
    printQueues(q);
    printf("dequeue: %i\n", dequeue(q));
    printQueues(q);
    printf("dequeue: %i\n", dequeue(q));
    printQueues(q);
    printf("dequeue: %i\n", dequeue(q));
    printQueues(q);
    printf("dequeue: %i\n", dequeue(q));
    printQueues(q);
}
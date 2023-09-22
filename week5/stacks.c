#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// create a stacks type data structure
typedef struct stacks
{
    int *array;
    int top;
    int size;
} stacks;

// create a new stacks
stacks *newStacks(int size)
{
    stacks *s = malloc(sizeof(stacks));
    if (s == NULL)
    {
        return NULL;
    }
    s->array = malloc(size * sizeof(int));
    if (s->array == NULL)
    {
        return NULL;
    }
    s->top = 0;
    s->size = size;
    return s;
}

// push a value onto a stacks
bool push(stacks *s, int value)
{
    // TODO
    if (s->top == s->size)
    {
        return false;
    }
    s->array[s->top] = value;
    s->top++;
    return true;
}

// returns true if stacks is empty else false
bool isEmpty(stacks *s)
{
    // TODO
    if (s->top == 0)
    {
        return true;
    }
    return false;
}

// returns the value at the top of the stacks
int peek(stacks *s)
{
    // TODO
    if (isEmpty(s))
    {
        return -1;
    }
    return s->array[s->top - 1];
}

// pop a value off of a stacks
int pop(stacks *s)
{
    // TODO
    if (isEmpty(s))
    {
        return -1;
    }
    int value = s->array[s->top - 1];
    s->top--;
    return value;
}

// print a stacks
void printStacks(stacks *s)
{
    if (isEmpty(s))
    {
        printf("Stacks is empty\n");
        return;
    }
    else
    {
        printf("Stacks: ");
        for (int i = 0; i < s->top; i++)
        {
            printf("%i ", s->array[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    stacks *s = newStacks(10);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 11);
    printStacks(s);
    printf("peek: %i\n", peek(s));
    printf("pop: %i\n", pop(s));
    printf("peek: %i\n", peek(s));
    printf("pop: %i\n", pop(s));
    printf("peek: %i\n", peek(s));
    printf("pop: %i\n", pop(s));
    printf("peek: %i\n", peek(s));
    printf("pop: %i\n", pop(s));
    printf("peek: %i\n", peek(s));
    printf("pop: %i\n", pop(s));
    printStacks(s);
    printf("peek: %i\n", peek(s));
    printf("pop: %i\n", pop(s));
    printf("peek: %i\n", peek(s));
    printf("pop: %i\n", pop(s));
    printf("peek: %i\n", peek(s));
    printf("pop: %i\n", pop(s));
    printf("peek: %i\n", peek(s));
    printf("pop: %i\n", pop(s));
    printf("peek: %i\n", peek(s));
    printf("pop: %i\n", pop(s));
    printStacks(s);
}
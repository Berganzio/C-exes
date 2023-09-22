#include <stdio.h>
#include <stdlib.h>
#include <cs50.c>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i\n", x);
    printf("y is %i\n", y);

    swap(&x, &y); // pass the addresses of x and y to the swap function

    printf("x is %i\n", x);
    printf("y is %i\n", y);
}

void swap(int *a, int *b)
{
    printf("\nSwapping...\n");
    int temp = *a; // temp = 1
    *a = *b;       // a = 2
    *b = temp;     // b = 1
}
#include <stdio.h>
#include <cs50.c>

int main(void)
{
    int a = 28;
    int b = 50;
    int *c = &a;

    *c = 14;
    c = &b;
    *c = 25;

    printf("a is %i, located at %p\n", a, &a);
    printf("b is %i, located at %p\n", b, &b);
    printf("c is %p, located at %p\n", c, &c);
}
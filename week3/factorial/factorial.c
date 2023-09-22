#include <stdio.h>
#include <cs50.c>

int factorial(int n);

int main(void)
{
    int n = get_int("Enter a number: ");
    printf("Factorial of %i is %d\n", n, factorial(n));
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
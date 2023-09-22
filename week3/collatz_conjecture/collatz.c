#include <stdio.h>
#include <cs50.c>

int collatz(int n);

int main(void)
{
    int n = get_int("Enter a number: ");
    printf("The number of steps is: %i\n", collatz(n));
}

int collatz(int n)
{
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return 1 + collatz(n / 2);
    else if (n % 2 != 0)
        return 1 + collatz(3 * n + 1);
}
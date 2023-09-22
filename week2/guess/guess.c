#include <stdio.h>
#include <cs50.c>

int main(void)
{
    int number = 5;
    int guess = get_int("Guess: ");

    while (guess != number)
    {
        printf("Wrong!\n");
        return 0;
    }
    printf("Correct!\n");
}

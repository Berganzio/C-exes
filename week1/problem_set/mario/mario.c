#include <stdio.h>
#include <cs50.c>

int main(void)
{
    // prompt the user for a positive number
    int n;
    do
    {
        n = get_int("Height: ");
    } while (n <= 0 || n > 8);

    for (int i = 0; i < n; i++)
    {
        // print spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // print hashes
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // print a gap
        printf("  ");
        // print hashes on the right
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // print a new line
        printf("\n");
    }
}
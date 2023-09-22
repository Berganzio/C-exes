#include <stdio.h>
#include <cs50.c>
#include <string.h> // for strlen

int main(void)
{
    string name = get_string("","What's your name? ");

    int n = 0;
    while (name[n] != '\0') // '\0' is the null character
    {
        n++;
    }
    printf("%i\n", n);

    string name2 = get_string("","What's your name? ");
    printf("%i\n", strlen(name2));
} 
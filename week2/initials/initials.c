#include <stdio.h>
#include <cs50.c>

int main(int argc, string argv[])
{
    // print first character for every argv
    for (int i = 1; i < argc; i++)
    {
        printf("%c\n", argv[i][0]);
    }
}
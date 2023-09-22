#include <stdio.h>
#include <cs50.c>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing Command Line Argument\n");
        return 1;
    }
    else
    {
        printf("hello, %s\n", argv[1]);
    }
}
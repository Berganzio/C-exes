#include <stdio.h>
#include <cs50.c>

int main(void)
{
    string name = get_string("", "Name: ");
    printf("hello, %s\n", name);
}
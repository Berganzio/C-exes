#include <stdio.h>
#include <cs50.c>
#include <string.h>

int main(void)
{
    string s = get_string("", "Enter a string to check if it's in alphabetical order: ");
    int n = strlen(s);
    int i = 0;
    while (i < n - 1)
    {
        if (s[i] > s[i + 1])
        {
            printf("No\n");
            return 0;
        }
        i++;
    }
    printf("Yes\n");
}
#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <ctype.h> // for islower() and toupper()

int main(void)
{
    string s = get_string("", "Before: ");
    printf("After: ");
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32); // 32 is the difference between upper and lower case letters in ASCII
        }
        else
        {
            printf("%c", s[i]);
        }
        
    }
    printf("\n");

    string t = get_string("", "Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(t); i < n; i++) 
    {
        printf("%c", toupper(t[i]));
    }
    printf("\n");
}
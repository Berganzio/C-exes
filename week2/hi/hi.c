#include <stdio.h>
#include <cs50.c>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';
    printf("%c %c %c\n", c1, c2, c3);
    printf("%i %i %i\n", c1, c2, c3);

    string s = "HI!";
    printf("%s\n", s);
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);

    string t = "BYE!";
    printf("%s%s\n", s, t);
    printf("%i %i %i %i %i %i %i %i %i\n", s[0], s[1], s[2], s[3], t[0], t[1], t[2], t[3], t[4]);

    string words[2] = {"HI!", "BYE!"};
    printf("%s %s\n", words[0], words[1]);
    printf("%c %c %c %i %c %c %c %c %i\n", words[0][0], words[0][1], words[0][2], words[0][3], words[1][0], words[1][1], words[1][2], words[1][3], words[1][4]);
}
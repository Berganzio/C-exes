#include <stdio.h>
#include <cs50.c>
#include <string.h>

typedef struct
{
    string name;
    int votes;
} candidate;

candidate get_candidate(string prompt);

int main(void)
{
    candidate candidates[3];
    for (int i = 0; i < 3; i++)
    {
        candidates[i] = get_candidate("Enter candidate info: ");
    }
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    candidate c;
    c.name = get_string("", "Enter candidate name: ");
    c.votes = get_int("Enter candidate's total votes: ");
    return c;
}
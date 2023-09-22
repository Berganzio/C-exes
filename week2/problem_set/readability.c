#include <stdio.h>
#include <cs50.c>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int Liaus_index(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("", "Text: ");
    // count letters
    int count = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    Liaus_index(count, words, sentences);
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count + 1;
}

int Liaus_index(int letters, int words, int sentences)
{
    float L = (float)letters / (float)words * 100;
    float S = (float)sentences / (float)words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index) + 1;
    if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    return 0;
}
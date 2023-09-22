#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// create a tries type data structure

typedef struct tries
{
    bool is_word;
    struct tries *children[27];
} tries;

// create a new tries
tries *newTries(void)
{
    tries *t = malloc(sizeof(tries));
    if (t == NULL)
    {
        return NULL;
    }
    t->is_word = false;
    for (int i = 0; i < 27; i++)
    {
        t->children[i] = NULL;
    }
    return t;
}

// hash function that returns an index for a word
int hash(tries *t, char *word)
{
    int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % 27;
}

// insert a word into a tries
bool insert(tries *t, char *word)
{
    // TODO
    int index = hash(t, word);
    if (t->children[index] == NULL)
    {
        t->children[index] = newTries();
    }
    if (word[0] == '\0')
    {
        t->children[index]->is_word = true;
        return true;
    }
    return insert(t->children[index], word + 1);
}

// returns true if word is in tries else false
bool check(tries *t, char *word)
{
    // TODO
    int index = hash(t, word);
    if (t->children[index] == NULL)
    {
        return false;
    }
    if (word[0] == '\0')
    {
        return t->children[index]->is_word;
    }
    return check(t->children[index], word + 1);
}

// unload tries from memory, returning true if successful else false
bool unload(tries *t)
{
    // TODO
    for (int i = 0; i < 27; i++)
    {
        if (t->children[i] != NULL)
        {
            unload(t->children[i]);
        }
    }
    free(t);
    return true;
}

int main(void)
{
    // create a new tries
    tries *t = newTries();
    if (t == NULL)
    {
        return 1;
    }

    // insert words into tries
    char *words[4] = {"HELLO", "HI", "HOW", "ARE"};
    for (int i = 0; i < 4; i++)
    {
        if (!insert(t, words[i]))
        {
            return 1;
        }
    }

    // check if words are in tries
    for (int i = 0; i < 4; i++)
    {
        if (check(t, words[i]))
        {
            printf("%s is in tries\n", words[i]);
        }
        else
        {
            printf("%s is not in tries\n", words[i]);
        }
    }

    // unload tries
    if (unload(t))
    {
        printf("Successfully unloaded tries\n");
    }
    else
    {
        printf("Could not unload tries\n");
    }
}

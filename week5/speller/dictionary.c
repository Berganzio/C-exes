// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000; // 100,000 buckets in the hash table

// Hash table
node *table[N]; // initialize an array of pointers to nodes

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word to get its index in the hash table
    // index is the bucket number, unsigned because it can't be negative
    unsigned int index = hash(word);

    // Traverse the linked list at the index
    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            // The word is in the dictionary
            return true;
        }
    }

    // The word is not in the dictionary
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // convert to lowercase and add to sum
        sum += (unsigned int)tolower(word[i]);
    }
    return sum % N; // return the remainder of sum divided by N
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Read words from the file and add them to the hash table
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF) // while not end of file
    {
        // Create a new node for the word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL) // if equal NULL means malloc failed
        {
            fclose(file); // close the file for avoiding memory leak
            return false;
        }
        strcpy(new_node->word, word); // copy the word to the node

        // Hash the word to get its index in the hash table
        unsigned int index = hash(word);

        // Insert the node at the beginning of the linked list
        new_node->next = table[index];
        table[index] = new_node;
    }

    // Close the dictionary file
    fclose(file);

    // Dictionary has been loaded successfully
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Keep track of the number of words
    unsigned int count = 0;

    // Traverse the hash table and count the number of nodes
    for (int i = 0; i < N; i++)
    {
        for (node *ptr = table[i]; ptr != NULL; ptr = ptr->next)
        {
            count++;
        }
    }

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Traverse the hash table and free the nodes
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *ptr = table[i];
            table[i] = ptr->next;
            free(ptr);
        }
    }

    // Dictionary has been unloaded successfully
    return true;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 26 // The hash table has 26 buckets (one for each letter of the alphabet)
#define INPUT_SIZE 26 // Maximum length of a string is 25 characters

typedef struct node
{
    char *data;
    struct node *next;
} node;

node *table[TABLE_SIZE]; // Hash table of linked lists of nodes (strings)

// Hash function
int hash(char *key) // key is a string of length 1 (e.g. "a", "b", "c", ...)
{
    return toupper(key[0]) - 'A'; // Convert the first character of the string to uppercase and subtract 'A' to get the index of the bucket
}

// Insert a string into the hash table
void insert(char *data)
{
    int index = hash(data);                            // Get the hash value of the string
    node *new_node = (node *)malloc(sizeof(node));     // Create a new node
    new_node->data = (char *)malloc(strlen(data) + 1); // Allocate memory for the string in the node
    strcpy(new_node->data, data);                      // Copy the string into the node
    new_node->next = table[index];                     // Insert the node at the beginning of the linked list
    table[index] = new_node;                           // Update the hash table
}

// Print the contents of the hash table in alphabetical order
void print_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        node *current = table[i]; // Get the head of the linked list
        while (current != NULL)   // Traverse the linked list
        {
            printf("%s\n", current->data);
            current = current->next; // Move to the next node
        }
    }
}

int main()
{
    // Initialize the hash table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL; // Set each bucket to NULL to initialize the linked list
    }

    // Read strings from standard input and insert them into the hash table
    char input[INPUT_SIZE];                 // Store the string read from standard input
    while (fgets(input, INPUT_SIZE, stdin)) // Read a string from standard input
    {
        // Remove the newline character at the end of the string
        input[strlen(input) - 1] = '\0'; // Replace the newline character with the null character
        insert(input);                   // Insert the string into the hash table
    }

    // Print the contents of the hash table in alphabetical order
    print_table();

    return 0;
}

// to close the program press ctrl + d in the terminal window
// then the program will print the contents of the hash table
// in alphabetical order

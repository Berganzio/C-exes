#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    node *list = NULL; // declare list and set to NULL (empty list)

    for (int i = 1; i < argc; i++) // starts from 1 to skip the program name
    {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node)); // create node in heap
        if (n == NULL)
        {
            return 1;
        }
        n->number = number; // set number in node
        n->next = NULL;     // set next to NULL in node (end of list)

        n->next = list; // set next to list (start of list)
        list = n;       // set list to n (start of list)
    }
    // create ptr
    node *ptr = list; // set ptr to list (start of list)
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number); // print number in ptr
        // set ptr to next in ptr (next in list) so we can print the next number
        ptr = ptr->next;
    }

    ptr = list; // set ptr to list (start of list)

    // free memory
    while (ptr != NULL)
    {
        node *next = ptr->next; // set tmp to next in ptr (next in list)
        free(ptr);              // free ptr
        ptr = next;             // set pointer to next
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// create a new type called struct node
struct node
{
    int data;          // the data of the node
    struct node *next; // a pointer to the next node
    struct node *prev; // a pointer to the previous node
};

// create a new node and return a pointer to it so that we can use it for other functions
struct node *new_node(int data) // return a pointer to the new node
{
    struct node *new = (struct node *)malloc(sizeof(struct node)); // allocate memory for the new node
    new->data = data;                                              // set the data of the new node
    new->next = NULL;                                              // set the next pointer of the new node to NULL
    new->prev = NULL;                                              // set the prev pointer of the new node to NULL
    return new;                                                    // return the pointer to the new node
}

// insert a new node at the end of the list
void insert(struct node **head, int data) // pass the head of the list by reference
{
    struct node *new = new_node(data); // create a new node and store the pointer to it in new
    if (*head == NULL)
    {
        *head = new;
        return;
    }
    struct node *temp = *head; // create a temporary pointer to the head of the list
    while (temp->next != NULL)
    {
        temp = temp->next; // move the temporary pointer to the next node
    }
    temp->next = new; // set the next pointer of the last node to the new node
    new->prev = temp; // set the prev pointer of the new node to the last node
}

// print the list
void print(struct node *head) // pass the head of the list by value
{
    while (head != NULL)
    {
        printf("%d ", head->data); // print the data of the current node
        head = head->next;         // move the head pointer to the next node
    }
    printf("\n");
}

// delete a node from the list
void delete(struct node **head, int data)
{
    struct node *temp = *head; // create a temporary pointer to the head of the list
    if (temp->data == data)    // if the first node is the one we want to delete
    {
        *head = temp->next; // set the head of the list to the next node
        free(temp);         // free the memory of the first node
        return;
    }
    while (temp->next != NULL) // if the first node is not the one we want to delete
    {
        if (temp->next->data == data) // if the next node is the one we want to delete
        {
            struct node *temp2 = temp->next; // create a temporary pointer to the node we want to delete
            temp->next = temp->next->next;   // set the next pointer of the current node to the next node of the node we want to delete
            free(temp2);                     // free the memory of the node we want to delete
            return;
        }
        temp = temp->next; // move the temporary pointer to the next node
    }
}

int main()
{
    struct node *head = NULL; // create a pointer to the head of the list and set it to NULL
    insert(&head, 21);        // pass the head of the list by reference and insert the value 21
    insert(&head, 32);
    insert(&head, 13);
    insert(&head, 4);
    insert(&head, 25);  // the list now contains 21, 32, 13, 4, 25
    print(head);        // print the list
    delete (&head, 13); // delete the node with the value 13
    print(head);        // print the list again

    // free the list
    struct node *temp = head; // create a temporary pointer to the head of the list
    while (temp != NULL)
    {
        struct node *temp2 = temp; // create a temporary pointer to the current node
        temp = temp->next;         // move the temporary pointer to the next node
        free(temp2);               // free the memory of the current node
    }

    return 0;
}

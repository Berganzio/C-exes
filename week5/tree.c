#include <stdio.h>
#include <stdlib.h>

typedef struct node // declare a struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

struct node *newNode(int data) // create a new node with data
{
    // allocate memory for the node
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;  // set the data of the node to data
    node->left = NULL;  // set the left child of the node to NULL
    node->right = NULL; // set the right child of the node to NULL
    return (node);
}

void printTree(struct node *root) // print the tree in preorder
{
    if (root == NULL)
        return;
    printf("%d ", root->data); // print the data of the node
    printTree(root->left);     // print the left subtree
    printTree(root->right);    // print the right subtree
}

int main(void)
{
    struct node *root = newNode(1); // create a new node with data 1
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6); // create a new node with data 6

    printTree(root);

    // save everything in a tree.txt file
    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "root->data = %d\n", root->data);
    fprintf(fp, "root->left->data = %d\n", root->left->data);
    fprintf(fp, "root->right->data = %d\n", root->right->data);
    fprintf(fp, "root->left->left->data = %d\n", root->left->left->data);
    fprintf(fp, "root->left->right->data = %d\n", root->left->right->data);
    fprintf(fp, "root->right->left->data = %d\n", root->right->left->data);
    fclose(fp);

    // free memory
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}

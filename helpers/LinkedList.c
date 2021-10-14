#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void insertEnd(Node **root, int _value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        exit(1);
    }
    newNode->next = NULL;
    newNode->value = _value;

    if(*root == NULL) {
        *root = newNode;
    }


    Node *curr = *root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

int main()
{
    Node* root = NULL;
    // Node* root = malloc(sizeof(Node));
    // if(root == NULL) {
    //     exit(2);
    // }
    // root->value = 10;
    // root->next = NULL;

    insertEnd(&root, 5);
    insertEnd(&root, 25);
    insertEnd(&root, 15);
    insertEnd(&root, 50);

    Node* curr = root;
    while (curr != NULL)
    {
        printf("%d\n", curr->value);
        curr = curr->next;
    }

    return 0;
}
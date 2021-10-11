#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void insertEnd(Node** _root, int _value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->next = NULL;
    newNode->value = _value;

    if (*_root == NULL) {
        *_root = newNode;
        return;
    }

    Node* curr = *_root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void deallocate(Node** _root) {
    Node* curr = *_root;

    while (curr != NULL) {
        Node* aux = curr;
        curr = curr->next;
        free(aux);
    }

    *_root = NULL;
}

int main() {
    Node* root = malloc(sizeof(Node));
    if (root == NULL) {
        exit(2);
    }
    root->value = 10;
    root->next = NULL;

    insertEnd(&root, 5);
    insertEnd(&root, 25);
    insertEnd(&root, 15);
    insertEnd(&root, 50);

    Node* curr = root;
    while (curr != NULL) {
        printf("%d\n", curr->value);
        curr = curr->next;
    }

    deallocate(&root);
    return 0;
}